#include "pch.h"
#include "BaseCharacter.h"
#include "Spritesheet.h"



BaseCharacter::BaseCharacter(const Texture& characterTexture) :
	m_pCharacterSpritesheet{ new Spritesheet{characterTexture, 4} }
{
}

BaseCharacter::~BaseCharacter()
{
	delete m_pCharacterSpritesheet;
}

void BaseCharacter::Draw(const Rectf& viewPort, const Vector2f& position, float scale, bool invert) const
{
	m_pCharacterSpritesheet->Draw(position, scale, invert);
}

void BaseCharacter::Update(float deltaTime)
{
	m_pCharacterSpritesheet->Update(deltaTime);
}

void BaseCharacter::ResetSprite()
{
	m_pCharacterSpritesheet->Reset();
}

int BaseCharacter::GetMaxHealth()
{
	return 100;
	//m_MaxHealth;
}

float BaseCharacter::GetMoveSpeed() const
{
	return m_MoveSpeed;
}

float BaseCharacter::GetSpriteWidht() const
{
	return m_pCharacterSpritesheet->GetSpriteWidth();
}

float BaseCharacter::GetSpriteHeight() const
{
	return m_pCharacterSpritesheet->GetSpriteHeight();
}

float BaseCharacter::GetMagnet() const
{
	return m_Magnet;
}