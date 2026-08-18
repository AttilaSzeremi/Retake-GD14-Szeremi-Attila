#pragma once
#include <vector>
class Weapon;
class Player;
class ProjectileManager;
class WeaponManager final
{
public:
	explicit WeaponManager(Player* player, ProjectileManager* projectileManager);
	~WeaponManager();

	void Draw(const Rectf& viewPort) const;
	void Update(float deltaTime);

	Weapon& GetWeapon(int idx);

	void AddWeapon(Weapon* weapon);
private:
	const int m_MaxWeaponCount{};
	std::vector<Weapon*> m_pWeapons{};
};

