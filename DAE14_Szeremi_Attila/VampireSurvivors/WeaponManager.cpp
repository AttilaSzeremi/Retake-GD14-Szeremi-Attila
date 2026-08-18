#include "pch.h"
#include "WeaponManager.h"
#include "Weapon.h"

WeaponManager::WeaponManager(Player* player, ProjectileManager* projectileManager)
{
	Weapon::LoadPLayer(player);
	Weapon::LoadProjectileManager(projectileManager);
}

WeaponManager::~WeaponManager()
{
	for (int idx{ 0 }; idx < m_pWeapons.size(); ++idx) {
		if (m_pWeapons[idx] != nullptr) {
			delete m_pWeapons[idx];
		}
	}
}

void WeaponManager::Draw(const Rectf& viewPort) const {
	for (int idx{ 0 }; idx < m_pWeapons.size(); ++idx) {
		if (m_pWeapons[idx] != nullptr) {
			//m_pWeapons[idx];
		}
	}
}

void WeaponManager::Update(float deltaTime) {
	for (int idx{ 0 }; idx < m_pWeapons.size(); ++idx) {
		if (m_pWeapons[idx] != nullptr) {
			m_pWeapons[idx]->Update(deltaTime);
		}
	}
}

Weapon& WeaponManager::GetWeapon(int idx)
{
	return *m_pWeapons[idx];
}

void WeaponManager::AddWeapon(Weapon* weapon)
{
	m_pWeapons.push_back(weapon);
}
