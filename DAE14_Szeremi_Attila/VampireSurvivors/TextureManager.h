#pragma once
#include <vector>
class Texture;
class TextureManager final
{
public:
	enum class textureId
	{
		startScreenBG = 0,
		button_blue
	};
	enum class textId
	{
		button_start = 0
	};

	TextureManager();
	~TextureManager();

	Texture& GetTexture(textureId texture);
	Texture& GetTexts(textId text);
private:
	std::vector<Texture*> m_pTextures;
	std::vector<Texture*> m_pTexts;


	void LoadTextures();
	void LoadTexts();
};

