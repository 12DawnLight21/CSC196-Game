#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"

namespace umbra
{
	class Actor
	{
	public:
		Actor(const umbra::Transform transform, const umbra::Model model) :
			m_transform{ transform },
			m_model{ model } {};

		virtual void Update(float dt) = 0; //dt = delta time
		virtual void Draw(umbra::Renderer& renderer);

		class Scene* m_scene; //inline forward declaration

	protected:
		umbra::Transform m_transform;
		umbra::Model m_model;
	};
}