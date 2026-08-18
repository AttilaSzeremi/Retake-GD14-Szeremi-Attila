#include "pch.h"
#include "FollowingEnemy.h"



FollowingEnemy::FollowingEnemy(int maxHealth, int power, int speed, float scale, const Vector2f& position, Texture& pSpritesheet) :
	Enemy(maxHealth, power, speed, scale, position, pSpritesheet)
{
}

void FollowingEnemy::HandleMovement(float deltaTime)
{
	Vector2f deltaMove{ Vector2f{GetPosition(), GetPlayerPosition()}.Normalized() * static_cast<float>(GetSpeed()) * deltaTime };
	SetPosition(GetPosition() + deltaMove);
}
