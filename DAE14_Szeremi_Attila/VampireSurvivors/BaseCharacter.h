#pragma once
#include <string>
#include "Texture.h"
class Spritesheet;
class BaseCharacter
{
public:
	explicit BaseCharacter(const Texture& characterTexture);
	virtual ~BaseCharacter();

	void Draw(const Rectf& viewPort, const Vector2f& position = Vector2f{}, float scale = 1.f, bool invert = false) const;
	float GetMoveSpeed() const;
	float GetSpriteWidht() const;
	float GetSpriteHeight() const;
	float GetMagnet() const;

	void Update(float deltaTime);
	void ResetSprite();

	int GetMaxHealth();
protected:

	// Character stats and base values
	int m_MaxHealth{ 100 };
	float m_Recovery{ 0.f };
	int m_Armor{ 0 };
	const int m_MaxArmour{ 50 };
	float m_MoveSpeed{ 1.f };
	float m_Might{ 1.f };
	const float m_MaxMight{ 10.f };
	float m_Area{ 1.f };
	const float m_MaxArea{ 10.f };
	float m_Speed{ 1.f };
	const float m_MaxSpeed{ 5.f };
	int m_Amount{ 0 };
	const int m_MaxAmount{ 10 };
	float m_Cooldown{ 1.f };
	const float m_MinCooldown{ 0.1f };
	float m_Luck{ 1.f };
	float m_Growth{ 1.f };	
	float m_Curse{ 1.f };
	float m_Magnet{ 30.f };
	int m_Revival{ 0 };
private:
	//Texture* m_pCharacterSpriteSheet{};
	Spritesheet* m_pCharacterSpritesheet{};
};

