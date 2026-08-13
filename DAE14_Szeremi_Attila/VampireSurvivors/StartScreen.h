#pragma once
#include "GameState.h"
#include "Button.h"
class Texture;
class StartScreen : public GameState
{
public:
	// Inherited via GameState
	void Draw() const override;
	void Update(float deltaTime, const Uint8* pStates) override;

	virtual void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e) override;

	StartScreen();
	~StartScreen() override = default;

private:
	Texture& m_pBackgroundTexture;
	Button m_Button;
};

