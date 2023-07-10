#pragma once
#include <SDL2-2.28.0/include/SDL.h>
#include <string>

namespace umbra 
{
	//void CreateWindow(const std::string& title, int width, int height);

	class Renderer
	{
		public:
			Renderer() = default; // basically empty constructor
			~Renderer() = default; //destroys the constructor/class?

			bool Initialize(); //typically is a bool in industry
			void ShutDown();

			void CreateWindow(const std::string& title, int width, int height);
			void BeginFrame();
			void EndFrame();

			void SetColor(int r, int g, int b, int a); //gets colors using int values
			void DrawLine(int x1, int y1, int x2, int y2); //its LINE time!!
			void DrawLine(float x1, float y1, float x2, float y2); 
			void DrawPoint(int x, int y); //math forever haunts me
			void DrawPoint(float x, float y);

			int GetWidth() const { return m_width; } //returns copy of the value
			int GetHeight() const { return m_height; } //does NOT change value of private variables

		private:
			int m_width = 0;
			int m_height = 0;

			SDL_Renderer* m_renderer{ nullptr };
			SDL_Window* m_window{ nullptr };
			
	};
}