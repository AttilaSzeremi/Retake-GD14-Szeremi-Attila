#include "pch.h"
#include "StartScreen.h"
#include "Texture.h"
#include "utils.h"
//#include "Game.h"

StartScreen::StartScreen(Texture* background) :
	m_pBackgroundTexture{ background },
	m_StartButton{ GetViewPort().width * 0.5f - 120,  GetViewPort().height * 0.25f, 240, 60 }
{
}

void StartScreen::Draw() const {
	const float
		scale{ GetViewPort().height / m_pBackgroundTexture->GetHeight() },
		ofset{ (m_pBackgroundTexture->GetWidth() * scale - GetViewPort().width) / 2.f };
	const Color4f
		black{ 0.f, 0.f, 0.f, 1.f },
		blue{ 0.f, 0.f, 1.f, 1.f };
	utils::SetColor(black);
	utils::FillRect(Rectf{ 0.f, 0.f, GetViewPort().width / 2.f, GetViewPort().height / 2.f });

	glPushMatrix(); {
		glTranslatef(ofset, 0.f, 0.f);
		glScalef(scale, scale, 0.f);
		m_pBackgroundTexture->Draw();
	}
	glPopMatrix();
	utils::SetColor(blue);
	utils::FillRect(m_StartButton);
}

void StartScreen::Update(float deltaTime, const Uint8* pStates)
{
}

void StartScreen::HandleMouseUpEvent(const Vector2f& mousePos)
{
	if (utils::IsPointInRect(mousePos, m_StartButton)) {
		ChangeGameState(gameStates::gameLoop);
	}
}

void StartScreen::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
}


