#include "Actor.h"

namespace umbra
{
	void Actor::Update(float dt)
	{
		if (m_lifespan != m_lifespan)
		{
			m_lifespan = m_lifespan - dt;
		}
		if (m_lifespan <= 0) m_destroyed = true;
	}

	void Actor::Draw(umbra::Renderer& renderer)
	{
		m_model->Draw(renderer, m_transform);
	}
}