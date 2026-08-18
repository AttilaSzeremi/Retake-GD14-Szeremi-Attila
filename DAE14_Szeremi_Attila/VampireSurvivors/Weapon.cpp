#include "pch.h"
#include "Weapon.h"
#include "Texture.h"
#include "ProjectileManager.h"
#include "Player.h"

ProjectileManager* Weapon::m_pProjectileManager{};
Player* Weapon::m_pPlayer{};
Weapon::Weapon(int maxLevel, float cooldown, float projectileInterval, int baseDamage, const std::string& texturePath, const std::string& projectileTexturePath) :
	m_MaxLevel{ maxLevel },
	m_CurrentLevel{ 1 },
	m_Cooldown{ cooldown },
	m_ProjectileInterval{ projectileInterval },
	m_pTexture{ new Texture{texturePath} },
	m_BaseDamage{ baseDamage },
	m_ProjectileCount{ 1 },
	m_DeltaTime{ 0.f },
	m_pProjetlieTexture{ new Texture{projectileTexturePath} }
{
}

Weapon::~Weapon()
{
	delete m_pTexture;
	delete m_pProjetlieTexture;
}

void Weapon::Update(float deltaTime)
{
	m_DeltaTime += deltaTime;
	m_LifeTime += deltaTime;

	if (m_DeltaTime >= m_Cooldown || m_Active) {
		HandleWeaponBehaviour(deltaTime);

		//m_Active = true;
		if (!m_Active) {
			m_DeltaTime -= m_Cooldown;
		}
	}
}

float Weapon::GetLifeTime()
{
	return m_LifeTime;
}

int Weapon::GetCurrentLevel() const
{
	return m_CurrentLevel;
}

int Weapon::GetProjectileCount() const
{
	return m_ProjectileCount;
}

bool Weapon::GetActive() const
{
	return m_Active;
}

int Weapon::GetCurrentProjectileCount() const
{
	return m_CurrentProjectileCount;
}

float Weapon::GetProjectileInterval() const
{
	return m_ProjectileInterval;
}

float Weapon::GetArea() const
{
	return m_Area;
}

ProjectileManager& Weapon::GetProjectileManager()
{
	return *m_pProjectileManager;
}

Player& Weapon::GetPlayer()
{
	return *m_pPlayer;
}

int Weapon::GetBaseDamage()
{
	return m_BaseDamage;
}

void Weapon::SetProjectileCount(int projectileCount)
{
	m_ProjectileCount = projectileCount;
}

void Weapon::SetBaseDamage(int damage)
{
	m_BaseDamage = damage;
}

void Weapon::SetArea(float area)
{
	m_Area = area;
}

void Weapon::LevelUp() {
	if (m_CurrentLevel < m_MaxLevel) {
		++m_CurrentLevel;
	}
}

float Weapon::GetCooldown() const
{
	return m_Cooldown;
}

float Weapon::GetDeltaTime() const
{
	return m_DeltaTime;
}

void Weapon::SetActive(bool status)
{
	m_Active = status;
}

void Weapon::AddToCurrentProjectileCount(int projectileCount)
{
	m_CurrentProjectileCount += projectileCount;
}

void Weapon::AddToDeltaTime(float difference)
{
	m_DeltaTime += difference;
}

void Weapon::LoadProjectileManager(ProjectileManager* projectileManager)
{
	m_pProjectileManager = projectileManager;
}

void Weapon::LoadPLayer(Player* player)
{
	m_pPlayer = player;
}
