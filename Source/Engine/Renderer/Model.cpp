#include "Model.h"
#include <sstream>

namespace umbra
{
	bool Model::Load(const std::string& filename)
	{
		std::string buffer; //fancy name for block of data
		umbra::readFile(filename, buffer);

		std::istringstream stream(buffer); //turns the buffer into a string

		std::string line;
		std::getline(stream, line);

		int numPoints = std::stoi(line); //converts string to int
		for (int i = 0; i < numPoints; i++)
		{
			vec2 point;

			stream >> point;

			m_points.push_back(point); //assigns point to vec even tho theres no data
		}

		return true;
	}
	void Model::Draw(Renderer& renderer, const vec2& position, float scale)
	{
		if (m_points.empty()) return; //if there's no points, don't draw

		for (int i = 0; i < m_points.size() - 1; i++) //prevents me from going outside the index
		{

			vec2 p1 = (m_points[i] * scale) + position;
			vec2 p2 = (m_points[i + 1] * scale) + position;
			
			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}

		
	}
}