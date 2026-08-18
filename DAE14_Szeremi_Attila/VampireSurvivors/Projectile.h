#pragma once
class Texture;
class Projectile
{
public:

	explicit Projectile(int damage, Texture* texture, const Vector2f& position, const Rectf hitbox, float areaScale = 1.f);
	virtual ~Projectile();

	virtual void Draw(const Vector2f& playerPosition, const Rectf& viewPort) const = 0;
	virtual void Update(float deltaTime) = 0;
	bool GetDelete() const;
	int GetDamage() const;
	Rectf& GetHitBox();
protected:
	void SetToDelete();
	Texture& GetTexture() const;
	float GetScale() const;
	Rectf m_HitBox{};
private:
	Vector2f m_Position{};
	bool m_ToDelete{ false };
	float m_AreaScale{};

	const int m_Damage{};
	Texture* m_pTexture{};

};

