#pragma once
#include "GameState.h"
class Map;
class Player;
class EnemyManager;
class WeaponManager;
class SpriteManager;
class ProjectileManager;
class SoundStream;
class Texture;
class GameLoop final : public GameState
{
public:
	explicit GameLoop(Player* player, Map* map, SpriteManager* spriteManager, float scale);
	~GameLoop();

	virtual void Draw() const override;
	virtual void Update(float deltaTime, const Uint8* pStates) override;
	virtual void HandleMouseUpEvent(const Vector2f& mousePos) override;
	virtual void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
	//void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
private:
	enum class State
	{
		run,
		pause,
		lose,
		win
	};

	void SpawnEnemies();
	void DrawXPBar() const;
	Vector2f GetRandomEnemySpawnLoaction();
	void HandleCollision();

	State m_State{};

	SpriteManager* m_pSpriteManager{};
	Player* m_pPlayer{};
	Map* m_pMap{};
	EnemyManager* m_pEnemyManager{};
	WeaponManager* m_pWeaponManager{};
	ProjectileManager* m_pProjectileManager{};
	float m_GameTime{};
	const float m_MaxGameTime{};
	float m_EnemySpawnTimer{};
	float m_GameScale{};


	Texture* m_pVictoryText{};
	Texture* m_pLoseText{};
	SoundStream* m_pMusic{};
	bool m_MusicStarted{ false };
};

