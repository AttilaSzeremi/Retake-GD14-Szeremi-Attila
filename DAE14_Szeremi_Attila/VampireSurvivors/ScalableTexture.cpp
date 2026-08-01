#include "pch.h"
#include "ScalableTexture.h"
#include "Texture.h"

#include "utils.h"
#include <iostream>

//ScalableTexture::ScalableTexture() :
//	m_pTexture{};
//{
//}

ScalableTexture::ScalableTexture(Texture& texture) :
	m_pTexture{ texture }
{
}

void ScalableTexture::Draw(const Rectf targetRec) const
{
	glPushMatrix(); {
		glTranslatef(targetRec.left, targetRec.bottom, 0.f);
		m_pTexture.Draw(Rectf{ 0.f,0.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f }, Rectf{ 0.f,-m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ m_pTexture.GetWidth() / 3.f,0.f, targetRec.width - m_pTexture.GetWidth() / 3.f * 2, m_pTexture.GetHeight() / 3.f }, Rectf{ m_pTexture.GetWidth() / 3.f,-m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ targetRec.width - m_pTexture.GetWidth() / 3.f,0.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f }, Rectf{ m_pTexture.GetWidth() / 3.f * 2.f,-m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ 0.f,m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, targetRec.height - m_pTexture.GetHeight() / 3.f * 2.f }, Rectf{ 0.f,m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ 0.f,targetRec.height - m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f }, Rectf{ 0.f,0.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f, targetRec.width - m_pTexture.GetWidth() / 3.f * 2, targetRec.height - m_pTexture.GetHeight() / 3.f * 2.f }, Rectf{ m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ targetRec.width - m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, targetRec.height - m_pTexture.GetHeight() / 3.f * 2.f }, Rectf{ m_pTexture.GetWidth() / 3.f * 2.f, m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ m_pTexture.GetWidth() / 3.f, targetRec.height - m_pTexture.GetHeight() / 3.f, targetRec.width - m_pTexture.GetWidth() / 3.f * 2, m_pTexture.GetHeight() / 3.f }, Rectf{ m_pTexture.GetWidth() / 3.f, 0, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		m_pTexture.Draw(Rectf{ targetRec.width - m_pTexture.GetWidth() / 3.f, targetRec.height - m_pTexture.GetHeight() / 3.f, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f }, Rectf{ m_pTexture.GetWidth() / 3.f * 2.f, 0, m_pTexture.GetWidth() / 3.f, m_pTexture.GetHeight() / 3.f });
		//m_pTexture.Draw(targetRec);
	}
	glPopMatrix();
	// Bottom Left corner
}

