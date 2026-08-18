#pragma once
class BaseCharacter;
class Player final
{
public:
	//explicit Player(const Vector2f& position);
	//explicit Player(BaseCharacter* character, const Vector2f& position = Vector2f{ 0.f, 0.f });
	explicit Player(BaseCharacter& character, const float scale = 1.f, const Vector2f& position = Vector2f{ 0.f, 0.f });

	void Draw(const Rectf& viewPort, bool drawHealthbar = false) const;
	Vector2f& GetPosition();
	int GetXpRequirment() const;
	int GetCurrentXP() const;
	float GetMagnet() const;
	bool IsInverse() const;

	void AddXP(int xpValue);
	void TakeDamage(int damage);
	bool IsDead() const;
	Rectf GetHitBox() const;

	void Update(float deltaTime, const Uint8* pstate);
	bool GetLeveledUp();
private:
	bool LevelUp();

	bool m_leveledUp{ false };
	int m_CurrentLevel{ 1 };
	int m_CurrentXP{ 0 };
	int m_CurrentHealth{};

	float m_Invulnerability{ 0.1f };
	float m_InvulnerabilityTimer{ 0.f };

	Vector2f m_Position{};
	float m_BaseMoveSpeed{ 160.f };
	float m_Scale{ 1.f };
	bool m_InverseSprite{ false };

	BaseCharacter& m_pCharacter;
};

