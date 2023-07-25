#include "Player.h"
#include "Projectile.h"
#include "Framework/Scene.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

#include "Game/SpaceRanch.h"

void Player::Update(float dt)
{
	//movement
	float rotate = 0;
	if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_D)) rotate = 1;
	m_transform.rotation += rotate * m_turnRate * umbra::g_time.GetDeltaTime();

	float thrust = 0;
	if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_W)) thrust = 1;

	umbra::vec2 forward = umbra::vec2(0, -1).Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * umbra::g_time.GetDeltaTime();

	m_transform.position.x = umbra::Wrap(m_transform.position.x, (float)umbra::g_renderer.GetWidth()); //if i dont cast these to a float he stutters and dies
	m_transform.position.y = umbra::Wrap(m_transform.position.y, (float)umbra::g_renderer.GetHeight());

	//fire projectiles
	if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_SPACE) && !umbra::g_inputSystem.getPreviousKeyDown(SDL_SCANCODE_SPACE))
	{
		//create weapon
		umbra::Transform transform{ m_transform.position, m_transform.rotation, 1.0f}; //changes bullet size
		std::unique_ptr<Projectile> projectile = std::make_unique<Projectile>( 400.0f, transform, m_model );
		projectile->m_tag = "PlayerBullet";

		m_scene->Add(std::move(projectile));
	}

}

void Player::OnCollision(Actor* other)
{
	if (other->m_tag == "EnemyBullet")
	{
		m_game->SetLives(m_game->GetLives() - 1);
		dynamic_cast<SpaceRanch*>(m_game)->SetState(SpaceRanch::eState::PlayerDead);
	}

}
