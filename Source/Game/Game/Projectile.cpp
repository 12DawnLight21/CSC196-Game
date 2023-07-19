#include "Projectile.h"

void Projectile::Update(float dt)
{
	umbra::vec2 forward = umbra::vec2(0, -1).Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * umbra::g_time.GetDeltaTime();

	m_transform.position.x = umbra::Wrap(m_transform.position.x, (float)umbra::g_renderer.GetWidth());
	m_transform.position.y = umbra::Wrap(m_transform.position.y, (float)umbra::g_renderer.GetHeight());
}