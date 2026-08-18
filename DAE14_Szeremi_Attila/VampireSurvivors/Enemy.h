#pragma once
class Spritesheet;
class Texture;
class Enemy
{
public:
	static void SetPlayerPos(Vector2f* playerPos);
	enum class EnemyState
	{
		alive,
		dead,
		deletable
	};

	explicit Enemy(int maxHealth, int power, int speed, float scale, const Vector2f& position, Texture& pSpritesheet);
	explicit Enemy(Enemy& rhs);
	explicit Enemy(Enemy&& rhs) noexcept;
	~Enemy();

	virtual void Draw(const Rectf& viewPort) const;
	virtual void Update(float deltaTime);
	void TakeDamage(int damage);
	const EnemyState GetEnemyState();
	Vector2f& GetPosition();
	int GetPower();
	int GetCurrentHealth();


	Enemy& operator=(Enemy& rhs);
	Enemy& operator=(Enemy&& rhs) noexcept;
protected:
	const Vector2f& GetPlayerPosition() const;
	int GetSpeed() const;
	void SetPosition(const Vector2f& pos);
	virtual void HandleMovement(float deltaTime) = 0;
private:
	static Vector2f* m_pPlayerPosition;
	Vector2f m_Position{};
	Spritesheet* m_pSpriteSheet{};
	EnemyState m_EnemyState{};

	int m_MaxHealth;
	int m_Health;
	int m_Power;
	int m_Speed;
	bool m_ResistFreeze{ false };
	bool m_ResistInstantKill{ false };
	bool m_ResistDebuf{ false };
	float m_Scale{};

};

