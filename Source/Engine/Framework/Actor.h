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

		virtual void Update(float dt); //dt = delta time
		virtual void Draw(umbra::Renderer& renderer);

		class Scene* m_scene = nullptr; //inline forward declaration
		friend class Scene;

		//BAD CODE BAD MAPLE >:3
		umbra::Transform m_transform;

	protected:
		bool m_destroyed = false; //a flag
		float m_lifespan = -1.0f;

		umbra::Model m_model;
	};
}