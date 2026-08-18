#include "pch.h"
#include "ProjectileManager.h"
#include "Projectile.h"

ProjectileManager::~ProjectileManager()
{
	for (int idx{ 0 }; idx < m_pProjectiles.size(); ++idx) {
		if (m_pProjectiles[idx] != nullptr) {
			delete m_pProjectiles[idx];
		}
	}
}

void ProjectileManager::Draw(const Vector2f& playerPos, const Rectf& viewPort) const
{
	for (int idx{ 0 }; idx < m_pProjectiles.size(); ++idx) {
		if (m_pProjectiles[idx] != nullptr) {
			m_pProjectiles[idx]->Draw(playerPos, viewPort);
		}
	}
}

void ProjectileManager::Update(float deltaTime)
{
	for (int idx{ 0 }; idx < m_pProjectiles.size(); ++idx) {
		if (m_pProjectiles[idx] != nullptr) {
			m_pProjectiles[idx]->Update(deltaTime);
			if (m_pProjectiles[idx]->GetDelete()) {
				delete m_pProjectiles[idx];
				m_pProjectiles[idx] = nullptr;
			}
		}
	}
}

void ProjectileManager::AddProjectile(Projectile* projectile)
{
	if (FindFirstEmpty() != -1) {
		m_pProjectiles[FindFirstEmpty()] = projectile;
	}
	else {
		m_pProjectiles.push_back(projectile);
	}
}

int ProjectileManager::GetSize() const
{
	return m_pProjectiles.size();
}

Projectile* ProjectileManager::GetProjectile(int idx)
{
	if (idx >= m_pProjectiles.size()) {
		return nullptr;
	}
	return m_pProjectiles[idx];
}

int ProjectileManager::FindFirstEmpty() const
{
	for (int idx{ 0 }; idx < m_pProjectiles.size(); ++idx) {
		if (m_pProjectiles[idx] == nullptr) {
			return idx;
		}
	}
	return -1;
}