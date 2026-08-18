#pragma once
#include "Enemy.h"
class FollowingEnemy : public Enemy
{
public:
	explicit FollowingEnemy(int maxHealth, int power, int speed, float scale, const Vector2f& position, Texture& pSpritesheet);
	~FollowingEnemy() = default;

protected:
	virtual void HandleMovement(float deltaTime) override;
private:

};

