#pragma once
#include <vector>
class Texture;
class Projectile;
class ProjectileManager;
class Player;
class Weapon
{
public:
	explicit Weapon(int maxLevel, float cooldown, float projectileInterval, int baseDamage, const std::string& texturePath, const std::string& projectileTexturePath);
	virtual ~Weapon();

	virtual void Update(float deltaTime);
	virtual void LevelUpWeapon() = 0;
	float GetLifeTime();
	static void LoadProjectileManager(ProjectileManager* projectileManager);
	static void LoadPLayer(Player* player);
protected:
	int GetCurrentLevel() const;
	int GetProjectileCount() const;
	bool GetActive() const;
	int GetCurrentProjectileCount() const;
	float GetProjectileInterval() const;
	float GetArea() const;
	ProjectileManager& GetProjectileManager();
	Player& GetPlayer();
	int GetBaseDamage();

	void SetProjectileCount(int projectileCount);
	void SetBaseDamage(int damage);
	void SetArea(float area);
	void LevelUp();
	float GetCooldown() const;
	float GetDeltaTime() const;
	void SetActive(bool status);
	void AddToCurrentProjectileCount(int projectileCount);
	void AddToDeltaTime(float difference);
	void AddProjectile(Projectile* projectile);

	virtual void HandleWeaponBehaviour(float deltaTime) = 0;

private:
	const int m_MaxLevel{};
	int m_CurrentLevel{};
	float m_Cooldown{};
	float m_DeltaTime{};
	float m_LifeTime{};
	int m_DamageDealt{};
	float m_ProjectileInterval{};
	bool m_Active{};
	int m_ProjectileCount{};
	int m_CurrentProjectileCount{};
	int m_BaseDamage{};
	float m_Area{ 1.f };

	static Player* m_pPlayer;
	static ProjectileManager* m_pProjectileManager;
	Texture* m_pTexture{};
	Texture* m_pProjetlieTexture{};
};

