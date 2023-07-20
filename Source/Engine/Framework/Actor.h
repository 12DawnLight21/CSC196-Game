#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"
#include <memory>

namespace umbra
{
	class Actor
	{
	public:
		Actor(const umbra::Transform transform, const std::shared_ptr<Model> model) :
			m_transform{ transform },
			m_model{ model } {};

		virtual void Update(float dt); //dt = delta time
		virtual void Draw(umbra::Renderer& renderer);

		float GetRadius() { return m_model->GetRadius() * m_transform.scale; };
		virtual void OnCollision(Actor* other) {};

		class Scene* m_scene = nullptr; //inline forward declaration
		friend class Scene;

		umbra::Transform m_transform;
		std::string m_tag;

	protected:
		bool m_destroyed = false; //a flag
		float m_lifespan = -1.0f;

		std::shared_ptr<Model> m_model;
	};
}