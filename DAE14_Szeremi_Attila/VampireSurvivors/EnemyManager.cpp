#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "FollowingEnemy.h"
#include "SpriteManager.h"

EnemyManager::EnemyManager(float scale) :
	m_GameScale{ scale }
{
}

EnemyManager::~EnemyManager()
{
	for (int idx{ 0 }; idx < m_pEnemies.size(); ++idx) {
		if (m_pEnemies[idx] != nullptr) {
			delete m_pEnemies[idx];
			m_pEnemies[idx] = nullptr;
		}
	}
}

int EnemyManager::GetEnemyCount() const {
	return m_EnemyCount;
}

void EnemyManager::Draw(const Rectf& viewPort) const {
	for (int idx{ 0 }; idx < m_pEnemies.size(); ++idx) {
		if (m_pEnemies[idx] != nullptr) {
			m_pEnemies[idx]->Draw(viewPort);
		}
	}
}

void EnemyManager::Update(float deltaTime) {
	for (int idx{ 0 }; idx < m_pEnemies.size(); ++idx) {
		if (m_pEnemies[idx] != nullptr) {
			m_pEnemies[idx]->Update(deltaTime);
			if (m_pEnemies[idx]->GetEnemyState() == Enemy::EnemyState::deletable) {
				delete m_pEnemies[idx];
				m_pEnemies[idx] = nullptr;
				--m_EnemyCount;
			}
		}
	}
}

Enemy* EnemyManager::GetEnemy(int idx)
{
	if (idx >= m_pEnemies.size()) {
		return nullptr;
	}
	return m_pEnemies[idx];
}

int EnemyManager::GetSize()
{
	return m_pEnemies.size();
}

void EnemyManager::AddEnemy(Enemy* enemy)
{
	int maxEnemy{ 300 };
	if (m_EnemyCount <= maxEnemy) {
		if (FindFirstEmpty() != -1) {
			m_pEnemies[FindFirstEmpty()] = enemy;
		}
		else {
			m_pEnemies.push_back(enemy);
		}
		++m_EnemyCount;
	}
}

int EnemyManager::FindFirstEmpty()
{
	for (int idx{ 0 }; idx < m_pEnemies.size(); ++idx) {
		if (m_pEnemies[idx] == nullptr) {
			return idx;
		}
	}
	return -1;
}
