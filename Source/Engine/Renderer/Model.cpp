#include "Model.h"

namespace umbra
{
	void Model::Draw(Renderer& renderer, const vec2& position, float scale)
	{
		if (m_points.empty()) return; //if there's no points, dont draw

		for (int i = 0; i < m_points.size() - 1; i++) //prevents me from going outside the index
		{

			vec2 p1 = (m_points[i] * scale) + position;
			vec2 p2 = (m_points[i + 1] * scale) + position;
			
			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}

		
	}
}