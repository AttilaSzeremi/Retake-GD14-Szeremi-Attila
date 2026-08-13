#include "pch.h"
#include "StartScreen.h"
#include "Texture.h"
#include "utils.h"
#include <iostream>

void StartScreen::Draw() const
{
	const float
		scale{ GetViewPort().height / m_pBackgroundTexture.GetHeight() },
		ofset{ (m_pBackgroundTexture.GetWidth() * scale - GetViewPort().width) / 2.f };
	const Color4f
		black{ 0.f, 0.f, 0.f, 1.f };
	utils::SetColor(black);
	utils::FillRect(GetViewPort());

	glPushMatrix(); {
		glTranslatef(ofset, 0.f, 0.f);
		glScalef(scale, scale, 0.f);
		m_pBackgroundTexture.Draw();
	}
	glPopMatrix();

	m_Button.Draw();
	//std::cout << "[" << GetViewPort().left << "; " << GetViewPort().bottom << "]\nwidth: " << GetViewPort().width << "\nheight: " << GetViewPort().height << "\n";

}

void StartScreen::Update(float deltaTime, const Uint8* pStates)
{
	if (m_Button.IsClicked()) {
		GameState::ChangeGameState(GameState::gameStates::characterSelect);
	}
}

void StartScreen::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	m_Button.ProcessMouseUpEvent(e);
}

StartScreen::StartScreen() :
	GameState(),
	m_pBackgroundTexture{ GetTextureManager().GetTexture(TextureManager::textureId::startScreenBG) },
	m_Button{ GetTextureManager().GetTexture(TextureManager::textureId::button_blue), Rectf{GetViewPort().width / 2.f, 200.f, 200.f, 168.f}, GetTextureManager().GetTexts(TextureManager::textId::button_start) }
{
}
