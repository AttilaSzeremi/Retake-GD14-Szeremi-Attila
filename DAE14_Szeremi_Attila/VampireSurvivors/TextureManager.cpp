#include "pch.h"
#include "TextureManager.h"
#include "Texture.h"

TextureManager::TextureManager()
{
	LoadTextures();
	LoadTexts();
}

TextureManager::~TextureManager()
{
	for (int idx{ 0 }; idx < m_pTextures.size(); ++idx) {
		if (m_pTextures[idx] != nullptr) {
			delete m_pTextures[idx];
			m_pTextures[idx] = nullptr;
		}
	}
	for (int idx{ 0 }; idx < m_pTexts.size(); ++idx) {
		if (m_pTexts[idx] != nullptr) {
			delete m_pTexts[idx];
			m_pTexts[idx] = nullptr;
		}
	}
}


Texture& TextureManager::GetTexture(textureId texture)
{
	return *m_pTextures[static_cast<int>(texture)];
}

Texture& TextureManager::GetTexts(textId text)
{
	return *m_pTexts[static_cast<int>(text)];
}

void TextureManager::LoadTextures()
{
	m_pTextures.push_back(new Texture("StartScreenBackground.png"));
	m_pTextures.push_back(new Texture("Button_Blue.png"));
}

void TextureManager::LoadTexts()
{
}

