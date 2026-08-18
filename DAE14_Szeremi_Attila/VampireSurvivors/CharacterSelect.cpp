#include "pch.h"
#include "utils.h"
#include "CharacterSelect.h"
#include "Texture.h"

CharacterSelect::CharacterSelect(const Rectf& viewPort, Texture* background) :
	m_ViewPort{ viewPort },
	m_pBackgroundTexture{ background },
	m_StartButton{ m_ViewPort.width * 0.5f - 120,  m_ViewPort.height * 0.25f, 240, 60 }
{

}

void CharacterSelect::Draw() const
{
	const float
		scale{ m_ViewPort.height / m_pBackgroundTexture->GetHeight() },
		ofset{ (m_pBackgroundTexture->GetWidth() * scale - m_ViewPort.width) / 2.f };
	const Color4f
		black{ 0.f, 0.f, 0.f, 1.f },
		blue{ 0.f, 0.f, 1.f, 1.f };
	utils::SetColor(black);
	utils::FillRect(Rectf{ 0.f, 0.f, m_ViewPort.width / 2.f, m_ViewPort.height / 2.f });

	glPushMatrix(); {
		glTranslatef(ofset, 0.f, 0.f);
		glScalef(scale, scale, 0.f);
		m_pBackgroundTexture->Draw();
	}
	glPopMatrix();
	//utils::SetColor(blue);
	//utils::FillRect(m_StartButton);
}
void CharacterSelect::Update(float deltaTime, const Uint8* pStates)
{
}

void CharacterSelect::HandleMouseUpEvent(const Vector2f& mousePos)
{
}

void CharacterSelect::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
}

