#include "pch.h"
#include <iostream>
#include "utils.h"
#include "GameLoop.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
#include "FollowingEnemy.h"
#include "SpriteManager.h"
#include "WeaponManager.h"
#include "WhipWeapon.h"
#include "ProjectileManager.h"
#include "Projectile.h"
#include "SoundStream.h"
#include "Texture.h"

#include "utils.h"

GameLoop::GameLoop(Player* player, Map* map, SpriteManager* spriteManager, float scale) :
	m_pMap{ map },
	m_pPlayer{ player },
	m_State{ State::run },
	m_MaxGameTime{ 1800.f },
	m_GameScale{ scale },
	m_pSpriteManager{ spriteManager },
	m_pEnemyManager{ new EnemyManager{scale} },
	m_pWeaponManager{ new WeaponManager{m_pPlayer, m_pProjectileManager} },
	m_pProjectileManager{ new ProjectileManager{} },
	m_pMusic{ new SoundStream{"0102 - Reincarnated Echoes.mp3"} },
	m_pVictoryText{ new Texture{"stageComplete.png"} },
	m_pLoseText{ new Texture{"gameOver.png"} }
{
	m_pWeaponManager->AddWeapon(new WhipWeapon{ 8, 1.35f, 0.1f, 10, "Pipeestrello-3.png" });
	Weapon::LoadPLayer(m_pPlayer);
	Weapon::LoadProjectileManager(m_pProjectileManager);
}

GameLoop::~GameLoop()
{
	delete m_pEnemyManager;
	delete m_pWeaponManager;
	delete m_pProjectileManager;
	delete m_pMusic;
	delete m_pLoseText;
	delete m_pVictoryText;
}

void GameLoop::Draw() const
{
	m_pMap->Draw(GetViewPort());
	m_pPlayer->Draw(GetViewPort(), true);
	m_pEnemyManager->Draw(GetViewPort());
	DrawXPBar();
	m_pWeaponManager->Draw(GetViewPort());
	m_pProjectileManager->Draw(m_pPlayer->GetPosition(), GetViewPort());

	const Color4f
		gray{ 0.2f, 0.2f, 0.2f, 0.4f },
		red{ 0.3f, 0.f,0.f, 0.4f };
	switch (m_State)
	{
	case GameLoop::State::pause:
		utils::SetColor(gray);
		utils::FillRect(GetViewPort());
		break;
	case GameLoop::State::win:
		utils::SetColor(gray);
		utils::FillRect(GetViewPort());
		m_pVictoryText->Draw(Vector2f{ GetViewPort().width / 2.f - m_pVictoryText->GetWidth() / 2.f, GetViewPort().height / 4.f * 2.5f });
		break;
	case GameLoop::State::lose:
		utils::SetColor(red);
		utils::FillRect(GetViewPort());
		m_pLoseText->Draw(Vector2f{ GetViewPort().width / 2.f - m_pLoseText->GetWidth() / 2.f, GetViewPort().height / 4.f * 2.5f });
		break;
	}
}

void GameLoop::Update(float deltaTime, const Uint8* pStates)
{
	switch (m_State)
	{
	case GameLoop::State::run:
		if (!m_MusicStarted) {
			m_MusicStarted = true;
			m_pMusic->Play(true);
		}

		m_GameTime += deltaTime * 60;
		m_EnemySpawnTimer += deltaTime;
		SpawnEnemies();
		m_pEnemyManager->Update(deltaTime);

		m_pWeaponManager->Update(deltaTime);

		m_pPlayer->Update(deltaTime, pStates);
		m_pProjectileManager->Update(deltaTime);
		HandleCollision();

		if (m_pPlayer->GetLeveledUp()) {
			m_pWeaponManager->GetWeapon(0).LevelUpWeapon();
		}

		if (m_pPlayer->IsDead()) {
			m_State = State::lose;
			m_pMusic->Pause();
		}

		if (m_MaxGameTime <= m_GameTime) {
			m_State = State::win;
			m_pMusic->Pause();
		}
		break;
	case GameLoop::State::pause:
		break;
	case GameLoop::State::lose:
		break;
	case GameLoop::State::win:
		break;
	default:
		break;
	}
	std::cout << m_MaxGameTime << " / " << m_GameTime << "\n";
}

void GameLoop::HandleMouseUpEvent(const Vector2f& mousePos)
{
}

void GameLoop::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		if (m_State == State::run) {
			m_State = State::pause;
			m_pMusic->Pause();
		}
		else if (m_State == State::pause) {
			m_State = State::run;
			m_pMusic->Resume();
		}
		break;
	}
}

void GameLoop::SpawnEnemies()
{
	//FollowingEnemy* pipestrello{  } };
	if (m_EnemySpawnTimer >= 1.f || m_pEnemyManager->GetEnemyCount() <= 15) {
		m_pEnemyManager->AddEnemy(new FollowingEnemy{ 5, 5, 140, m_GameScale, GetRandomEnemySpawnLoaction(), m_pSpriteManager->GetEnemySpritesheet(0) });

		m_EnemySpawnTimer -= 1.f;
		if (m_EnemySpawnTimer < 0.f) {
			m_EnemySpawnTimer = 0.f;
		}
		//PickUp* temp{ } };
		//m_pPickUpManager->AddPickUp(temp);
	}
}

void GameLoop::DrawXPBar() const
{
	const Color4f
		gold{ 1.f, 215.f / 255.f, 0.f, 1.f },
		black{ 0.f, 0.f,0.f,1.f },
		blue{ 44.f / 255.f, 101.f / 255.f, 214.f / 255.f, 1.f };

	float xpBarLengthPrecent{ std::min(static_cast<float>(m_pPlayer->GetCurrentXP()) / static_cast<float>(m_pPlayer->GetXpRequirment()), 1.f) };
	const Rectf
		outline{ 2.f, GetViewPort().height - 44.f, GetViewPort().width - 4.f, 40 },
		blackBar{ 6.f, GetViewPort().height - 40.f, GetViewPort().width - 12.f, 32.f },
		xpBar{ 6.f, GetViewPort().height - 38.f, (GetViewPort().width - 12.f) * xpBarLengthPrecent, 28.f };

	utils::SetColor(gold);
	utils::FillRect(outline);
	utils::SetColor(black);
	utils::FillRect(blackBar);
	utils::SetColor(blue);
	utils::FillRect(xpBar);
}

Vector2f GameLoop::GetRandomEnemySpawnLoaction()
{
	// 0 vertical side, 1 horizontal side
	int spawnSide{ rand() % 2 };
	// 0 negative, 1 positive
	int spawnDirection{ rand() % 2 };
	Vector2f spawnLocationOfSet{};
	if (spawnSide == 0) {
		spawnLocationOfSet.x = (rand() % static_cast<int>(GetViewPort().width) - GetViewPort().width);
		spawnLocationOfSet.y = GetViewPort().height / 2.f + 30.f;
		if (spawnDirection == 1) {
			spawnLocationOfSet.y *= -1;
		}
	}
	else {
		spawnLocationOfSet.y = (rand() % static_cast<int>(GetViewPort().height) - GetViewPort().height);
		spawnLocationOfSet.x = GetViewPort().width / 2.f + 30.f;
		if (spawnDirection == 1) {
			spawnLocationOfSet.x *= -1;
		}
	}
	return m_pPlayer->GetPosition() + spawnLocationOfSet;
}

void GameLoop::HandleCollision()
{
	for (int enemyIDX{ 0 }; enemyIDX < m_pEnemyManager->GetSize(); ++enemyIDX) {
		if (m_pEnemyManager->GetEnemy(enemyIDX) != nullptr) {
			for (int projectileIDX{ 0 }; projectileIDX < m_pProjectileManager->GetSize(); ++projectileIDX) {
				if (m_pProjectileManager->GetProjectile(projectileIDX) != nullptr) {
					if (utils::IsPointInRect(m_pEnemyManager->GetEnemy(enemyIDX)->GetPosition(), m_pProjectileManager->GetProjectile(projectileIDX)->GetHitBox())) {
						m_pEnemyManager->GetEnemy(enemyIDX)->TakeDamage(m_pProjectileManager->GetProjectile(projectileIDX)->GetDamage());
						if (m_pEnemyManager->GetEnemy(enemyIDX)->GetCurrentHealth() <= 0) {
							m_pPlayer->AddXP(1);
						}
					}
				}
			}
			if (utils::IsPointInRect(m_pEnemyManager->GetEnemy(enemyIDX)->GetPosition(), m_pPlayer->GetHitBox())) {
				m_pPlayer->TakeDamage(m_pEnemyManager->GetEnemy(enemyIDX)->GetPower());
			}
		}
	}
}

//void GameLoop::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
//{
//	switch (e.keysym.sym)
//	{
//	case SDLK_ESCAPE:
//		if (m_State == State::run) {
//			m_State = State::pause;
//		}
//		else if (m_State == State::pause) {
//			m_State = State::run;
//		}
//		break;
//	}
//}
