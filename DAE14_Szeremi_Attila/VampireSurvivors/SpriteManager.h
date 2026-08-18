#pragma once
#include <vector>
class Texture;
class SpriteManager final
{
public:
	explicit SpriteManager();
	~SpriteManager();

	Texture& GetEnemySpritesheet(int idx) const;
	Texture& GetCharacterSpritesheet(int idx) const;
	Texture& GetMapTexture(int idx) const;
	Texture& GetPickUpTexture(int idx) const;

	void LoadEnemySpritesheet(const std::string& path);
	void LoadCharacterSpritesheet(const std::string& path);
	void LoadMapTexture(const std::string& path);
	void LoadPickUpTexture(const std::string& path);
private:
	std::vector<Texture*> m_pEnemySpritesheets{};
	std::vector<Texture*> m_pCharacterSpritesheet{};
	std::vector<Texture*>m_pMaps{};
	std::vector<Texture*> m_pPickUps{};
};

