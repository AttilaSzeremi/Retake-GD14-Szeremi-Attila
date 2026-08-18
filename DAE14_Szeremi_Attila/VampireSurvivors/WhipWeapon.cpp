#include "pch.h"
#include "WhipWeapon.h"
#include "WhipProjectile.h"
#include "Texture.h"
#include "ProjectileManager.h"
#include "Player.h"

WhipWeapon::WhipWeapon(int maxLevel, float cooldown, float projectileInterval, int baseDamage, const std::string& texturePath) :
	Weapon{ maxLevel, cooldown, projectileInterval, baseDamage, texturePath, "Whip_Attack.png" }
{
}

void WhipWeapon::LevelUpWeapon()
{
	switch (GetCurrentLevel())
	{
	case 1:
		SetProjectileCount(GetProjectileCount() + 1);
		break;
	case 2:
		SetBaseDamage(GetBaseDamage() + 5);
		break;
	case 3:
		SetArea(GetArea() + 0.1f);
		SetBaseDamage(GetBaseDamage() + 5);
		break;
	case 4:
		SetBaseDamage(GetBaseDamage() + 5);
		break;
	case 5:
		SetArea(GetArea() + 0.1f);
		SetBaseDamage(GetBaseDamage() + 5);
		break;
	case 6:
		SetBaseDamage(GetBaseDamage() + 5);
		break;
	case 7:
		SetBaseDamage(GetBaseDamage() + 5);
		break;
	default:
		break;
	}
	LevelUp();
}


//void WhipWeapon::Update(float deltaTime)
//{
//
//}



void WhipWeapon::HandleWeaponBehaviour(float deltaTime)
{
	if (!GetActive()) {
		SetActive(true);
	}

	if (GetDeltaTime() >= GetProjectileInterval()) {
		WhipProjectile* temperary{ new WhipProjectile{ GetBaseDamage(), new Texture{"Whip_Attack.png"}, Vector2f{GetPlayer().GetPosition().x, GetPlayer().GetPosition().y + 10 * GetCurrentProjectileCount()}, GetArea() } };
		if (GetCurrentProjectileCount() % 2 == 0) {
			temperary->SetInverse(GetPlayer().IsInverse());
		}
		else {
			temperary->SetInverse(!GetPlayer().IsInverse());
		}

		GetProjectileManager().AddProjectile(temperary);

		//delete temperary;
		//temperary = nullptr;
		AddToDeltaTime(-GetProjectileInterval());
		AddToCurrentProjectileCount(1);
	}

	if (GetCurrentProjectileCount() == GetProjectileCount()) {
		SetActive(false);
		AddToCurrentProjectileCount(-GetProjectileCount());
	}
}







