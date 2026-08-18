#include "pch.h"
#include "Game.h"
#include "SpriteManager.h"
#include "Texture.h"
#include "Map.h"
#include "Player.h"
#include "BaseCharacter.h"
#include "StartScreen.h"
#include "GameLoop.h"
#include "Enemy.h"
#include "SoundEffect.h"

Game::Game(const Window& window)
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	GameState::SetViewPort(GetViewPort());
	m_pBaseBackground = new Texture{ "StartScreenBackground.png" };
	m_pStartScreen = new StartScreen{ m_pBaseBackground };

	m_pIntroSound = new SoundEffect{ "0101 - Side A.mp3" };

	const float gameScale{ 2.f };
	m_pSpriteManager = new SpriteManager{};
	m_pSpriteManager->LoadMapTexture("Tilemap-Mad_Forest.png");
	m_pSpriteManager->LoadCharacterSpritesheet("AntonioBelpaese.png");
	m_pSpriteManager->LoadEnemySpritesheet("Pipeestrello-3.png");
	m_pSpriteManager->LoadPickUpTexture("XP_orb.png");
	m_pAntonio = new BaseCharacter{ m_pSpriteManager->GetCharacterSpritesheet(0) };
	m_pPlayer = new Player{ *m_pAntonio, gameScale };
	m_pMadForrest = new Map{ m_pSpriteManager->GetMapTexture(0), gameScale + 1.f, m_pPlayer->GetPosition() };
	Enemy::SetPlayerPos(&m_pPlayer->GetPosition());
	//Enemy::SetPlayerPos(&m_pPlayer->GetPosition());
	//const Vector2f enemyPos{ 0.f,0.f };
	//m_pEnemy = new FollowingEnemy{ 10, 10, 1, enemyPos, m_pSpriteManager->GetCharacterSpritesheet(0) };
	//FollowingEnemy test{ 15, 15, 1, enemyPos, m_pSpriteManager->GetCharacterSpritesheet(0) };
	m_pGameLoop = new GameLoop{ m_pPlayer, m_pMadForrest, m_pSpriteManager, gameScale };
}

void Game::Cleanup()
{
	delete m_pBaseBackground;
	delete m_pSpriteManager;
	delete m_pAntonio;
	delete m_pPlayer;
	delete m_pMadForrest;

	delete m_pStartScreen;
	delete m_pGameLoop;
	//for (int idx{ 0 }; idx < m_Enemies.size(); ++idx) {
	//	delete m_Enemies[idx];
	//}

	//delete m_pEnemy;
	delete m_pIntroSound;
}

void Game::Update(float elapsedSec)
{
	if (!m_IntroSoundPlayed) {
		m_IntroSoundPlayed = true;
		m_pIntroSound->Play(0);
	}
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	// Check keyboard state
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
	//m_pPlayer->Update(elapsedSec, pStates);
	//for (int idx{ 0 }; idx < m_Enemies.size(); ++idx) {
	//	m_Enemies[idx]->Update(elapsedSec);
	//}
	//m_pEnemy->Update(elapsedSec);

	switch (GameState::GetGameState())
	{
	case GameState::gameStates::startScreen:
		//m_pStartScreen->Draw();
		break;
	case GameState::gameStates::gameLoop:
		m_pGameLoop->Update(elapsedSec, pStates);
		break;
	default:
		break;
	}
}

void Game::Draw() const
{
	ClearBackground();

	switch (GameState::GetGameState())
	{
	case GameState::gameStates::startScreen:
		m_pStartScreen->Draw();
		break;
	case GameState::gameStates::gameLoop:
		m_pGameLoop->Draw();
		break;
	default:
		break;
	}

	//m_pMadForrest->Draw(GetViewPort());
	//m_pPlayer->Draw(GetViewPort());
	//m_pEnemy->Draw();
	//for (int idx{ 0 }; idx < m_Enemies.size(); ++idx) {
	//	m_Enemies[idx]->Draw();
	//}
	//m_pMadForrest->Reset();
}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
	switch (GameState::GetGameState())
	{
	case GameState::gameStates::startScreen:
		//m_pStartScreen->Draw();
		break;
	case GameState::gameStates::gameLoop:
		m_pGameLoop->ProcessKeyUpEvent(e);
		break;
	default:
		break;
	}
}

void Game::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}

}

void Game::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	const Vector2f mousePos{ static_cast<float>(e.x), static_cast<float>(e.y) };
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		////std::cout << " left button " << std::endl;
		switch (GameState::GetGameState())
		{
		case GameState::gameStates::startScreen:
			m_pStartScreen->HandleMouseUpEvent(mousePos);
			break;
		case GameState::gameStates::gameLoop:
			m_pGameLoop->HandleMouseUpEvent(mousePos);
			break;
		default:
			break;
		}
		break;
	}
}

void Game::ClearBackground() const
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
