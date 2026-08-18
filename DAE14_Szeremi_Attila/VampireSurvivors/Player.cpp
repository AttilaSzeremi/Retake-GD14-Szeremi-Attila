#include "pch.h"
#include "Player.h"
#include "utils.h"
#include <iostream>
#include "BaseCharacter.h"

//Player::Player(const Vector2f& position) :
//	m_Position{ position }
//{
//}

//Player::Player(BaseCharacter* character, const Vector2f& position) :
//	m_Position{ position },
//	m_pCharacter{ character }
//{
//}

Player::Player(BaseCharacter& character, const float scale, const Vector2f& position) :
	m_Position{ position },
	m_pCharacter{ character },
	m_Scale{ scale },
	m_CurrentHealth{ m_pCharacter.GetMaxHealth() }
{
}

void Player::Draw(const Rectf& viewPort, bool drawHealthbar) const
{
	const Vector2f center{ viewPort.width / 2.f, viewPort.height / 2.f };
	m_pCharacter.Draw(viewPort, center, m_Scale, m_InverseSprite);

	if (drawHealthbar) {

		const float ofset{ 20.f };
		const Color4f
			black{ 0.f, 0.f, 0.f, 1.f },
			red{ 1.f, 0.f, 0.f, 1.f };
		const Rectf
			healthBarBase{
			viewPort.width / 2.f - m_pCharacter.GetSpriteWidht() / 2.f * m_Scale,
			viewPort.height / 2.f - m_pCharacter.GetSpriteHeight() / 2.f * m_Scale - ofset,
			m_pCharacter.GetSpriteWidht() * m_Scale,
			5.f * m_Scale
		},
			healthBar{ healthBarBase.left, healthBarBase.bottom, healthBarBase.width * (m_CurrentHealth / static_cast<float>(m_pCharacter.GetMaxHealth())), healthBarBase.height };
		utils::SetColor(black);
		utils::FillRect(healthBarBase);
		utils::SetColor(red);
		utils::FillRect(healthBar);
	}
}

Vector2f& Player::GetPosition()
{
	return m_Position;
}

void Player::Update(float deltaTime, const Uint8* pState)
{
	Vector2f movement{};
	if (pState[SDL_SCANCODE_LEFT] || pState[SDL_SCANCODE_A]) {
		movement.x = 1;
		m_InverseSprite = true;
	}
	if (pState[SDL_SCANCODE_RIGHT] || pState[SDL_SCANCODE_D]) {
		movement.x = -1;
		m_InverseSprite = false;
	}
	if (pState[SDL_SCANCODE_DOWN] || pState[SDL_SCANCODE_S]) {
		movement.y = 1;
	}
	if (pState[SDL_SCANCODE_UP] || pState[SDL_SCANCODE_W]) {
		movement.y = -1;
	}
	movement = movement.Normalized();
	//std::cout << movement << "\n";
	//std::cout << m_InverseSprite << "\n";

	movement *= m_BaseMoveSpeed * m_pCharacter.GetMoveSpeed() * deltaTime;
	//std::cout << m_Position << "\n";
	m_Position -= movement;

	m_InvulnerabilityTimer += deltaTime;

	if (!movement.Equals(Vector2f{})) {
		m_pCharacter.Update(deltaTime);
	}
	else {
		m_pCharacter.ResetSprite();
	}
	if (m_CurrentXP >= GetXpRequirment()) {
		m_leveledUp = LevelUp();
	}
}

bool Player::GetLeveledUp()
{
	if (m_leveledUp) {
		m_leveledUp = false;
		return true;
	}
	return false;
}

bool Player::LevelUp()
{
	if (m_CurrentXP >= GetXpRequirment()) {
		m_CurrentXP -= GetXpRequirment();
		++m_CurrentLevel;
		return true;
	}
	return false;
}

int Player::GetXpRequirment() const
{
	int result{};
	if (m_CurrentLevel <= 20) {
		result = (m_CurrentLevel * 10) + 5;
		if (m_CurrentLevel == 20) {
			result += 600;
		}
	}
	else if (m_CurrentLevel > 20 && m_CurrentLevel <= 40) {
		result = (m_CurrentLevel * 13) - 6;
		if (m_CurrentLevel == 40) {
			result += 2400;
		}
	}
	else {
		(m_CurrentLevel * 16) - 8;
	}
	return result;
}

int Player::GetCurrentXP() const
{
	return m_CurrentXP;
}

float Player::GetMagnet() const
{
	return m_pCharacter.GetMagnet();
}

bool Player::IsInverse() const
{
	return m_InverseSprite;
}

void Player::TakeDamage(int damage) {
	if (m_InvulnerabilityTimer >= m_Invulnerability) {
		m_CurrentHealth -= damage;
		m_InvulnerabilityTimer = 0.f;
	}
}

bool Player::IsDead() const
{
	if (m_CurrentHealth <= 0) {
		return true;
	}
	return false;
}

Rectf Player::GetHitBox() const {
	return Rectf{ m_Position.x - m_pCharacter.GetSpriteWidht() / 2.f, m_Position.y - m_pCharacter.GetSpriteHeight() / 2.f, m_pCharacter.GetSpriteWidht(), m_pCharacter.GetSpriteHeight() };
}

void Player::AddXP(int xpValue)
{
	m_CurrentXP += xpValue;
}

