#include "pch.h"
#include "Spritesheet.h"
#include "Texture.h"
#include "utils.h"

Spritesheet::Spritesheet(const Texture& texture, int numberOfFrames) :
	m_pSpritesheet{ texture },
	m_NumberOfFrames{ numberOfFrames },
	m_FrameTime{ 0.2f }
{
}

void Spritesheet::Draw(const Vector2f& position, float scale, bool invert) const
{
	glPushMatrix(); {
		glTranslatef(position.x, position.y, 0.f);
		glScalef(scale, scale, 0.f);
		if (invert) {
			//glScalef(-1.f, 1.f, 0.f);
			glRotatef(180.f, 0.f, 1.f, 0.f);
		}
		m_pSpritesheet.Draw(Vector2f{ -GetSpriteWidth() / 2.f ,  -GetSpriteHeight() / 2.f }, GetSourceRect());
		//utils::FillRect(Vector2f{}, 100, 100);
	}
	glPopMatrix();
}

void Spritesheet::Update(float deltaTime)
{
	m_CurrentFrameTime += deltaTime;
	if (m_CurrentFrameTime >= m_FrameTime) {
		++m_CurrentFrame;
		m_CurrentFrameTime -= m_FrameTime;
	}
}

float Spritesheet::GetSpriteHeight() const
{
	return m_pSpritesheet.GetHeight();
}

float Spritesheet::GetSpriteWidth() const
{
	return m_pSpritesheet.GetWidth() / m_NumberOfFrames;
}

void Spritesheet::Reset()
{
	m_CurrentFrame = 0;
	m_CurrentFrameTime = 0;
}

Rectf Spritesheet::GetSourceRect() const
{
	const float width{ m_pSpritesheet.GetWidth() / m_NumberOfFrames };

	const Rectf result{
		width * (m_CurrentFrame % m_NumberOfFrames), 0.f,
		width, m_pSpritesheet.GetHeight()
	};

	return result;
}

