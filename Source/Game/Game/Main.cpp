#include "Core/Core.h" //linked to a bunch of directories
#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"
#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include <thread>
#include <iostream> //searches the system instead
#include <vector>

using namespace std;

class Star
{
public:
	Star(const umbra::Vector2& pos, const umbra::Vector2& vel):
		m_pos{pos},
		m_vel{vel}
	{}

	void Update()
	{
		m_pos += m_vel * umbra::g_time.GetDeltaTime();
	}

	void Draw(umbra::Renderer& renderer)
	{
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}

public:
	umbra::vec2 m_pos;
	umbra::vec2 m_vel;
};

//adds literally too many things at once
/*
void func()
{
	int* p = new int[1000000000]; 
}

void funcs() //will crash your shit with a stack overflow
{
	int i[100000];
	funcs();
}
*/

int main(int argc, char* argv[])
{
	umbra::MemoryTracker::Initialize();

	umbra::seedRandom((unsigned int)time(nullptr));
	umbra::setFilePath("assets");

	int* p = new int;
	//delete p;

	//our window setup
	umbra::g_renderer.Initialize();
	umbra::g_renderer.CreateWindow("CSC196", 800, 600);

	umbra::g_inputSystem.Initialize();

	umbra::g_audioSystem.Initialize();
	umbra::g_audioSystem.AddAudio("shoot", "shoot.wav"); //instead of using shoot.wav, we can just call shoot

	umbra::vec2 v{5, 5};
	v.Normalize();

	vector<Star> stars; //not in a namespace so its fine
	for (int i = 0; i < 500; i++) //makes the star background ;3
	{
		umbra::Vector2 pos(umbra::Vector2(umbra::random(umbra::g_renderer.GetWidth()), umbra::random(umbra::g_renderer.GetHeight())));
		umbra::Vector2 vel(umbra::randomf(1, 8), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	umbra::Scene scene;
	std::unique_ptr<Player> player = make_unique<Player>(200.0f, umbra::Pi, umbra::Transform{ {400, 300}, 0, 6 }, umbra::g_manager.Get("player.txt"));
	player->m_tag = "Player";
	scene.Add(std::move(player)); //creates player in main part of memory

	for (int i = 0; i < 10; i++)
	{
		std::unique_ptr<Enemy> enemy = make_unique<Enemy>(umbra::randomf(75.0f, 150.0f), umbra::Pi, umbra::Transform{ { umbra::random(800), umbra::random(600)}, umbra::randomf(umbra::TwoPi), 6 }, umbra::g_manager.Get("ship.txt"));
		enemy->m_tag = "Enemy";
		scene.Add(std::move(enemy));
	}

	//create font / text objects
	std::shared_ptr<umbra::Font> font = std::make_shared<umbra::Font>("MinecraftRegular.ttf", 24);

	std::unique_ptr<umbra::Text> text = std::make_unique<umbra::Text>(font);
	text->Create(umbra::g_renderer, "NEUMONT", umbra::Color{1, 1, 1, 1});


	bool quit = false;
	// Main GAME LOOP
	while (!quit)
	{
		//update engine
		umbra::g_time.Tick();
		umbra::g_inputSystem.Update(); //checks for input updates 
		umbra::g_audioSystem.Update(); //updates the audio systems

		//update game
		scene.Update(umbra::g_time.GetDeltaTime());
		umbra::g_renderer.SetColor(0, 0, 0, 0); //sets color to black
		umbra::g_renderer.BeginFrame(); //clears the screen, allows for less static


		if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_ESCAPE)) //if esc is pressed, end the thing
		{
			quit = true;
		}

		if (umbra::g_inputSystem.GetMouseButtonDown(0)) //if mouse clicked, clicked the mouse
		{
			cout << "Mouse pressed." << endl;
		}

		if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_M))
		{
			umbra::g_audioSystem.PlayOneShot("shoot");
		}

		//update draw
		umbra::Vector2 vel(1.0f, 0.3f);

		for (auto& star : stars) //literally just made space screensaver
		{
			star.Update();

			if (star.m_pos.x >= umbra::g_renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= umbra::g_renderer.GetHeight()) star.m_pos.y = 0;

			umbra::g_renderer.SetColor(umbra::random(256), umbra::random(256), umbra::random(256), 255);
			umbra::g_renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}
		
		scene.Draw(umbra::g_renderer);
		text->Draw(umbra::g_renderer, 400, 300);

		umbra::g_renderer.EndFrame();
	}

	stars.clear();
	scene.RemoveAll();

	return 0; 
}



// taxi game??
// chaos simulator (youre shadow the hedgehog. enough said)
	//shadow the ehdgehog game but lines and its way better
// replicate that penguin asteroids game you saw on that one youtube channel
// legend of zelda with OG sword mechanics? 


	
	/*
	//umbra::CreateWindow("CSC196", 800, 600);
	//cin.get(); // is a pause, prevents window from opening/closing too fast
	//memory time fellas
	umbra::g_memoryTracker.DisplayInfo();
	int* p = new int; //holds the ADDRESS of an int
	umbra::g_memoryTracker.DisplayInfo();
	delete p;
	umbra::g_memoryTracker.DisplayInfo();
	umbra::Time timer;
	for (int i = 0; i < 10000000000000000000; i++) {}
	cout << timer.GetElapsedSeconds() << endl;
	//chrono time, literally	
	//auto start = std::chrono::high_resolution_clock::now(); //auto - figures out the datatype by the code assignment
	//for (int i = 0; i < 10000000000000000000; i++) {}
	//auto end = std::chrono::high_resolution_clock::now();
	//cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl; //<casts> it into microsecodns
	cout << umbra::getFilePath() << endl;
	umbra::setFilePath("Assets"); //not case sensitive
	cout << umbra::getFilePath() << endl;
	size_t size;
	umbra::getFileSize("game.txt", size);
	cout << size << endl;
	std::string s;
	umbra::readFile("game.txt", s);
	cout << s << endl;
	// ../ goes back a SINGLE directory, can nagivate the entire directory
	umbra::seedRandom((unsigned int)time(nullptr)); //returns system time in seconds starting // () is a cast
	for (int i = 0; i < 10; i++)
	{
		cout << umbra::random(10, 20) << endl;
	}
	*/