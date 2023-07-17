#include "Actor.h"

void Actor::Draw(umbra::Renderer& renderer)
{
	m_model.Draw(renderer, m_transform);
}
