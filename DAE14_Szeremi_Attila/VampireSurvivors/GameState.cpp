#include "pch.h"
#include "GameState.h"

GameState::gameStates GameState::m_GameState{ GameState::gameStates::startScreen };
Rectf GameState::m_ViewPort{ Rectf{} };
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
