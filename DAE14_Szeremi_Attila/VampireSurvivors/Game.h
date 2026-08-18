#pragma once
#include "BaseGame.h"
#include <vector>
class SpriteManager;
class Map;
class Player;
class BaseCharacter;
class Texture;
class StartScreen;
class GameLoop;
class SoundEffect;
class Game : public BaseGame
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update(float elapsedSec) override;
	void Draw() const override;

	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e) override;
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e) override;
	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e) override;
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e) override;
private:
	// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;

	Texture* m_pBaseBackground{};
	StartScreen* m_pStartScreen{};
	GameLoop* m_pGameLoop{};

	SpriteManager* m_pSpriteManager{};
	Map* m_pMadForrest{};
	Player* m_pPlayer{};
	BaseCharacter* m_pAntonio{};

	SoundEffect* m_pIntroSound{};
	bool m_IntroSoundPlayed{ false };
	//std::vector<Enemy*> m_Enemies{};
	//Enemy* m_pEnemy{};
};