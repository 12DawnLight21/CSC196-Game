#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include "Framework/Scene.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt)
{
	Actor::Update(dt);
	Player* player = m_scene->GetActor<Player>(); //T* is replaced by player 
	if (player)
	{
		umbra::vec2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.Angle() + umbra::HalfPi;
	}

	umbra::vec2 forward = umbra::vec2(0, -1).Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * umbra::g_time.GetDeltaTime();

	m_transform.position.x = umbra::Wrap(m_transform.position.x, (float)umbra::g_renderer.GetWidth()); //if i dont cast these to a float he stutters and dies
	m_transform.position.y = umbra::Wrap(m_transform.position.y, (float)umbra::g_renderer.GetHeight());

	//timer <= 0 reset time

	//uhhhh fires SUPER fast but if i change the firetimer value itll fix itself??
	if (m_fireTimer <= 0)
	{
		m_fireTimer = m_fireRate;

		//create weapon
		umbra::Transform transform{ m_transform.position, m_transform.rotation, 1}; //changes bullet size
		std::unique_ptr<Projectile> projectile = std::make_unique<Projectile>(400.0f, transform, m_model);
		projectile->m_tag = "EnemyBullet";

		m_scene->Add(std::move(projectile));
	}
	else
	{
		m_fireTimer -= dt;
	}
}

void Enemy::OnCollision(Actor* other)
{
	//dynamic_cast<Player*>(other) returns a player or null

	if (other->m_tag == "PlayerBullet")
	{
		m_health -= m_health;
		if (m_health <= 0) m_destroyed = true;
	}
}
