#pragma once
#include <vector>
class Enemy;
class FollowingEnemy;
class SpriteManager;
class EnemyManager final
{
public:
	explicit EnemyManager(float scale);
	~EnemyManager();

	int GetEnemyCount() const;
	void Draw(const Rectf& viewPort) const;
	void Update(float deltaTime);

	Enemy* GetEnemy(int idx);
	int GetSize();

	void AddEnemy(Enemy* enemy);
private:
	int FindFirstEmpty();

	std::vector<Enemy*> m_pEnemies{};
	int m_EnemyCount{ 0 };
	float m_GameScale{};
};

