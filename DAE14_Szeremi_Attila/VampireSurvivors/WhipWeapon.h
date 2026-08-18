#pragma once
#include "Weapon.h"
class WhipWeapon : public Weapon
{
public:
	explicit WhipWeapon(int maxLevel, float cooldown, float projectileInterval, int baseDamage, const std::string& texturePath);
	virtual ~WhipWeapon() override = default;

	virtual void LevelUpWeapon() override;
	//virtual void Update(float deltaTime) override;
protected:
	//virtual bool SpawnProjectile() override;
	virtual void HandleWeaponBehaviour(float deltaTime) override;
private:


};

