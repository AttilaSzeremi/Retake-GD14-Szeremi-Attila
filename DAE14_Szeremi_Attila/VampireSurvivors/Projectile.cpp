#include "pch.h"
#include "Projectile.h"
#include "Texture.h"

Projectile::Projectile(int damage, Texture* texture, const Vector2f& position, const Rectf hitbox, float areaScale) :
	m_Damage{ damage },
	m_pTexture{ texture },
	m_Position{ position },
	m_HitBox{ hitbox },
	m_AreaScale{ areaScale }
{
}

Projectile::~Projectile()
{
	delete m_pTexture;
}

void Projectile::SetToDelete()
{
	m_ToDelete = true;
}

Texture& Projectile::GetTexture() const
{
	return *m_pTexture;
}

float Projectile::GetScale() const
{
	return m_AreaScale;
}

bool Projectile::GetDelete() const
{
	return m_ToDelete;
}

int Projectile::GetDamage() const
{
	return m_Damage;
}

Rectf& Projectile::GetHitBox()
{
	return m_HitBox;
}