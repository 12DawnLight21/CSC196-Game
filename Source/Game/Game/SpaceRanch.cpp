#include "SpaceRanch.h"
#include "Player.h"
#include "Enemy.h"

#include "Framework/Scene.h"

#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"

bool SpaceRanch::Initialize()
{
	//create font / text
	m_font = std::make_shared<umbra::Font>("MinecraftRegular.ttf", 24);
	m_scoreText = std::make_unique<umbra::Text>(m_font);
	m_scoreText->Create(umbra::g_renderer, "SCORE 0000", umbra::Color{1, 0, 1, 1});

	m_titleText = std::make_unique<umbra::Text>(m_font);
	m_titleText->Create(umbra::g_renderer, "S P A C E   R A N C H", umbra::Color{1, 1, 1, 1});

	//load audio
	umbra::g_audioSystem.AddAudio("shoot", "shoot.wav"); 

	m_scene = std::make_unique<umbra::Scene>();

	return true;
}

bool SpaceRanch::Shutdown()
{

	return false;
}

void SpaceRanch::Update(float dt)
{
	switch (m_state)
	{
	case SpaceRanch::Title:
		if (umbra::g_inputSystem.getKeyDown(SDL_SCANCODE_SPACE))
		{
			m_state = eState::StartGame;
		}
		break;

	case SpaceRanch::StartGame:
		m_score = 0;
		m_lives = 3;

		m_state = eState::StartLevel;
		break;

	case SpaceRanch::StartLevel:
		m_scene->RemoveAll();
		{
			std::unique_ptr<Player> player = std::make_unique<Player>(200.0f, umbra::Pi, umbra::Transform{ {400, 300}, 0, 6 }, umbra::g_manager.Get("player.txt"));
			player->m_tag = "Player";
			player->m_game = this;
			m_scene->Add(std::move(player));
		}
			m_state = eState::Game;
		break;

	case SpaceRanch::Game:
		m_spawnTimer += dt;
		if (m_spawnTimer >= m_spawnTime)
		{
			m_spawnTimer = 0;
			std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(umbra::randomf(75.0f, 150.0f), umbra::Pi, umbra::Transform{ { umbra::random(800), umbra::random(600)}, umbra::randomf(umbra::TwoPi), 6 }, umbra::g_manager.Get("ship.txt"));
			enemy->m_tag = "Enemy";
			enemy->m_game = this;
			m_scene->Add(std::move(enemy));
		}

		break;

	case SpaceRanch::PlayerDead:
		if (m_lives == 0) m_state = eState::GameOver;
		else m_state = eState::StartLevel;


		break;

	case SpaceRanch::GameOver:
		break;

	default:
		break;
	}

	m_scoreText->Create(umbra::g_renderer, std::to_string(m_score), {1, 1, 1, 1});
	m_scene->Update(dt);
}

void SpaceRanch::Draw(umbra::Renderer& renderer)
{
	if (m_state == eState::Title)
	{
		m_titleText->Draw(renderer, 400, 300);
	}
	
	m_scoreText->Draw(renderer, 40, 40);
	m_scene->Draw(renderer);
}
