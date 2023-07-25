#pragma once
#include "Framework/Game.h"
#include "Renderer/Text.h"

class SpaceRanch : public umbra::Game
{
public:
	enum eState
	{
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver
	};

public:
	virtual bool Initialize() override;
	virtual bool Shutdown() override;

	virtual void Update(float dt) override;
	virtual void Draw(umbra::Renderer& renderer) override;

	void SetState(eState state) { m_state = state; }

private:
	eState m_state = eState::Title;
	float m_spawnTimer = 0;
	float m_spawnTime = 3.0f; //every 3 secs, spawn enemy

	std::shared_ptr<umbra::Font> m_font;
	std::unique_ptr<umbra::Text> m_scoreText;
	std::unique_ptr<umbra::Text> m_titleText;
};