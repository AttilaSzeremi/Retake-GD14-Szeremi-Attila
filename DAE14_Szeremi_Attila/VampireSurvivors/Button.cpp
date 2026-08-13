#include "pch.h"
#include "Button.h"
#include "utils.h"
#include <iostream>
#include "BaseGame.h"

//Button::Button()
//{
//}


Button::Button(const Texture& texture, const Rectf& bounds, const Texture& text) :
	m_Texture{ texture },
	m_Bounds{ bounds },
	m_pButtonText{ text }
{
}

bool Button::IsClicked() const
{
	return m_IsClicked;
}

void Button::Draw() const
{
	m_Texture.Draw(m_Bounds);

	const Vector2f ofset{
		(m_Bounds.width - m_pButtonText.GetWidth()) / 2.f,
		(m_Bounds.height - m_pButtonText.GetHeight()) / 2.f
	};

	m_pButtonText.Draw(Vector2f(m_Bounds.left, m_Bounds.bottom) + ofset);
}

void Button::Reset()
{
	m_IsClicked = false;
}

void Button::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	if (utils::IsPointInRect(Vector2f{ static_cast<float>(e.x), static_cast<float>(e.y), }, m_Bounds)) {
		m_IsClicked = !m_IsClicked;
	}
}

void Button::ChangeBounds(const Rectf& bounds)
{
	m_Bounds = bounds;
}
