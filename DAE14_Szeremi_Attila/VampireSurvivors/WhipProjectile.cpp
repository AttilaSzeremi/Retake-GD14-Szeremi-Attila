#include "pch.h"
#include "WhipProjectile.h"
#include "utils.h"
#include <iostream>
#include "Texture.h"

const float WhipProjectile::m_MaxLifeTime{ 0.1f };
WhipProjectile::WhipProjectile(int damage, Texture* texture, const Vector2f& position, float AreaScale) :
	Projectile(damage, texture, position, Rectf{ position.x, position.y - texture->GetHeight() / 2.f * AreaScale, texture->GetWidth() * AreaScale, texture->GetHeight() * AreaScale })
{
}

void WhipProjectile::Draw(const Vector2f& playerPosition, const Rectf& viewPort) const
{
	glPushMatrix(); {
		glTranslatef(viewPort.width / 2.f, viewPort.height / 2.f - GetTexture().GetHeight() / 2.f, 0.f);
		glScalef(GetScale(), GetScale(), 0.f);
		if (m_Inverse) {
			glScalef(-1.f, 1.f, 0.f);
		}
		GetTexture().Draw();
	}
	glPopMatrix();
}

void WhipProjectile::Update(float deltaTime)
{
	m_LifeTime += deltaTime;
	if (m_LifeTime >= m_MaxLifeTime) {
		SetToDelete();
	}
}

void WhipProjectile::SetPosition(const Vector2f& position) {
	m_HitBox.left = position.x;
	m_HitBox.bottom = position.y;
}

void WhipProjectile::SetInverse(bool inverse)
{
	if (inverse) {
		m_HitBox.left -= GetHitBox().width;
	}
	m_Inverse = inverse;
}


