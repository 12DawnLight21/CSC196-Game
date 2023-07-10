#pragma once
#include "Core/Core.h"
#include "Renderer.h" 
#include <vector>

namespace umbra
{
	class Model //draws points with lines and lines with points
	{
	public:
		Model() = default;
		Model(const std::vector<vec2>& points) : m_points{ points } {}; //if you dont use a reference, itll copy over the number which is SLOW

		void Draw(Renderer& renderer, const vec2& position, float scale);

	private:
		std::vector<vec2> m_points; //hidden array of points ; vec2 = Vector2 alias
	};
}