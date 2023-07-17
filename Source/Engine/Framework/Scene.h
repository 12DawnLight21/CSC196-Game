#pragma once
#include "Actor.h"

#include <list>
//unity calls these scenes too

namespace umbra
{
	//forward declaration - tells the compiler that it doesnt need to know shit bout the renderer's reference
		//doesnt work with functions, can only declare variables
	class Renderer;

	class Scene
	{
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(Renderer& renderer);

		void Add(Actor* actor);
		void Remove(Actor* actor);
		void RemoveAll();

	private:
		std::list<Actor*> m_actors; //contains POINTER of actors, more optimal for constantly changing
	};
}