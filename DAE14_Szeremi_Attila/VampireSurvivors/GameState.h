#pragma once
#include "TextureManager.h"
class GameState
{
public:
	GameState();
	virtual ~GameState();

	virtual void Draw() const = 0;
	virtual void Update(float deltaTime, const Uint8* pStates) = 0;

	virtual void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e) = 0;

	enum class gameStates
	{
		startScreen,
		characterSelect,
		gameLoop,
		endScreen
	};

	static gameStates GetGameState();
	static void SetViewPort(const Rectf& viewPort);
protected:
	static void ChangeGameState(gameStates gameState);
	static Rectf& GetViewPort();
	TextureManager& GetTextureManager();
private:
	static gameStates m_GameState;
	static Rectf m_ViewPort;
	static TextureManager* m_pTextureManager;
	static int m_NumberOfGameStates;
};

