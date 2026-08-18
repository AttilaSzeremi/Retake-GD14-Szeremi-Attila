#include "pch.h"
#include "SpriteManager.h"
//#include "Spritesheet.h"
#include "Texture.h"

SpriteManager::SpriteManager()
{
}

SpriteManager::~SpriteManager()
{
	for (int idx{ 0 }; idx < m_pEnemySpritesheets.size(); ++idx) {
		delete m_pEnemySpritesheets[idx];
		m_pEnemySpritesheets[idx] = nullptr;
	}
	for (int idx{ 0 }; idx < m_pCharacterSpritesheet.size(); ++idx) {
		delete m_pCharacterSpritesheet[idx];
		m_pCharacterSpritesheet[idx] = nullptr;
	}
	for (int idx{ 0 }; idx < m_pMaps.size(); ++idx) {
		delete m_pMaps[idx];
		m_pMaps[idx] = nullptr;
	}
	for (int idx{ 0 }; idx < m_pPickUps.size(); ++idx) {
		delete m_pPickUps[idx];
		m_pPickUps[idx] = nullptr;
	}
}

Texture& SpriteManager::GetEnemySpritesheet(int idx) const
{
	return *m_pEnemySpritesheets[idx];
}

Texture& SpriteManager::GetCharacterSpritesheet(int idx) const
{
	return *m_pCharacterSpritesheet[idx];
}

Texture& SpriteManager::GetMapTexture(int idx) const
{
	return *m_pMaps[idx];
}

Texture& SpriteManager::GetPickUpTexture(int idx) const
{
	return *m_pPickUps[idx];
}

void SpriteManager::LoadEnemySpritesheet(const std::string& path)
{
	m_pEnemySpritesheets.push_back((new Texture{ path }));
}

void SpriteManager::LoadCharacterSpritesheet(const std::string& path)
{

	m_pCharacterSpritesheet.push_back((new Texture{ path }));
}

void SpriteManager::LoadMapTexture(const std::string& path)
{
	m_pMaps.push_back((new Texture{ path }));
}

void SpriteManager::LoadPickUpTexture(const std::string& path)
{
	m_pPickUps.push_back(new Texture{ path });
}
