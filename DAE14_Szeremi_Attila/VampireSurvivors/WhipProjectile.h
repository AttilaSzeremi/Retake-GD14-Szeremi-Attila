#pragma once
#include "Projectile.h"

class WhipProjectile final : public Projectile
{
public:
	explicit WhipProjectile(int damage, Texture* texture, const Vector2f& position, float AreaScale = 1.f);
	virtual ~WhipProjectile() override = default;

	virtual void Draw(const Vector2f& playerPosition, const Rectf& viewPort) const override;
	virtual void Update(float deltaTime) override;

	void SetPosition(const Vector2f& pos);
	void SetInverse(bool inverse);
private:
	const static float m_MaxLifeTime;

	bool m_Inverse{ false };
	float m_LifeTime{ 0.f };
};

