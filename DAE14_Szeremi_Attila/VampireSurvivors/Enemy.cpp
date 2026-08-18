#include "pch.h"
#include "Enemy.h"
#include "Spritesheet.h"
#include "utils.h";
#include <iostream>

Vector2f* Enemy::m_pPlayerPosition{};
Enemy::Enemy(int maxHealth, int power, int speed, float scale, const Vector2f& position, Texture& pSpritesheet) :
	m_MaxHealth{ maxHealth },
	m_Health{ maxHealth },
	m_Power{ power },
	m_Speed{ speed },
	m_Position{ position },
	m_pSpriteSheet{ new Spritesheet{pSpritesheet, 4} },
	m_EnemyState{ EnemyState::alive },
	m_Scale{ scale }
{
	std::cout << m_Scale << "\n";
}

Enemy::Enemy(Enemy& rhs) :
	m_MaxHealth{ rhs.m_MaxHealth },
	m_Health{ rhs.m_Health },
	m_Power{ rhs.m_Power },
	m_Speed{ rhs.m_Speed },
	m_pSpriteSheet{ new Spritesheet{*rhs.m_pSpriteSheet} },
	m_EnemyState{ rhs.m_EnemyState },
	m_Scale{ rhs.m_Scale },
	m_Position{ rhs.m_Position }
{
}

Enemy::Enemy(Enemy&& rhs) noexcept :
	m_MaxHealth{ rhs.m_MaxHealth },
	m_Health{ rhs.m_Health },
	m_Power{ rhs.m_Power },
	m_Speed{ rhs.m_Speed },
	m_pSpriteSheet{ rhs.m_pSpriteSheet },
	m_EnemyState{ rhs.m_EnemyState },
	m_Scale{ rhs.m_Scale },
	m_Position{ rhs.m_Position }
{
	rhs.m_pSpriteSheet = nullptr;
}

Enemy::~Enemy()
{
	delete m_pSpriteSheet;
}

void Enemy::Draw(const Rectf& viewPort) const {
	const Vector2f relativePosition{ m_Position.x - (m_pPlayerPosition->x - viewPort.width / 2.f),m_Position.y - (m_pPlayerPosition->y - viewPort.height / 2.f) };
	bool inverse{ false };
	if (relativePosition.x > viewPort.width / 2.f) {
		inverse = true;
	}
	//std::cout << relativePosition << "\n";
	//utils::DrawPoint(relativePosition, 10.f);
	//std::cout << m_Scale << "\n";

	m_pSpriteSheet->Draw(relativePosition, m_Scale, inverse);

}

void Enemy::Update(float deltaTime) {
	HandleMovement(deltaTime);
	m_pSpriteSheet->Update(deltaTime);
	if (m_Health <= 0) {
		m_EnemyState = EnemyState::deletable;
	}
}

void Enemy::TakeDamage(int damage)
{
	m_Health -= damage;

}

const Enemy::EnemyState Enemy::GetEnemyState()
{
	return m_EnemyState;
}

void Enemy::SetPlayerPos(Vector2f* playerPos)
{
	m_pPlayerPosition = playerPos;
}

Enemy& Enemy::operator=(Enemy& rhs)
{
	if (this != &rhs) {
		delete this->m_pSpriteSheet;
		m_pSpriteSheet = nullptr;
		m_MaxHealth = rhs.m_MaxHealth;
		m_Health = rhs.m_Health;
		m_Power = rhs.m_Power;
		m_Speed = rhs.m_Speed;
		m_pSpriteSheet = new Spritesheet{ *rhs.m_pSpriteSheet };
		m_EnemyState = rhs.m_EnemyState;
		m_Scale = rhs.m_Scale;
		m_Position = rhs.m_Position;
	}
	return *this;
}

const Vector2f& Enemy::GetPlayerPosition() const
{
	return *m_pPlayerPosition;
}

Vector2f& Enemy::GetPosition()
{
	return m_Position;
}

int Enemy::GetPower()
{
	return m_Power;
}

int Enemy::GetCurrentHealth()
{
	return m_Health;
}

int Enemy::GetSpeed() const
{
	return m_Speed;
}

void Enemy::SetPosition(const Vector2f& pos)
{
	m_Position = pos;
}