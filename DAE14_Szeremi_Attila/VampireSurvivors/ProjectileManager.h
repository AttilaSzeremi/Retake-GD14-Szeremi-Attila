#pragma once
#include <vector>
class Projectile;
class ProjectileManager final
{
public:
	explicit ProjectileManager() = default;
	~ProjectileManager();

	void Draw(const Vector2f& playerPos, const Rectf& viewPort) const;
	void Update(float deltaTime);

	void AddProjectile(Projectile* projectile);
	int GetSize() const;

	Projectile* GetProjectile(int idx);
private:
	int FindFirstEmpty() const;

	std::vector<Projectile*> m_pProjectiles{};

};

