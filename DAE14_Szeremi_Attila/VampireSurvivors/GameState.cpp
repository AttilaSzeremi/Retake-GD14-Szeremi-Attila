#include "pch.h"
#include "GameState.h"

GameState::gameStates GameState::m_GameState{ GameState::gameStates::startScreen };
Rectf GameState::m_ViewPort{ Rectf{} };
TextureManager* GameState::m_pTextureManager{ nullptr };
int GameState::m_NumberOfGameStates{ 0 };

GameState::GameState()
{
	if (m_pTextureManager == nullptr) {
		m_pTextureManager = new TextureManager{};
	}
	++m_NumberOfGameStates;
}

GameState::~GameState()
{
	if (m_NumberOfGameStates == 1) {
		delete m_pTextureManager;
		m_pTextureManager = nullptr;
	}
	--m_NumberOfGameStates;
}

GameState::gameStates GameState::GetGameState()
{
	return m_GameState;
}
void GameState::SetViewPort(const Rectf& viewPort)
{
	m_ViewPort = viewPort;
}
void GameState::ChangeGameState(gameStates gameState)
{
	m_GameState = gameState;
}

Rectf& GameState::GetViewPort()
{
	return m_ViewPort;
}

TextureManager& GameState::GetTextureManager()
{
	return *m_pTextureManager;
}
