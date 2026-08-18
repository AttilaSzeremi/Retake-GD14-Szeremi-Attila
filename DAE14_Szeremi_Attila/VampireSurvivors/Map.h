#pragma once
class Texture;
class Map
{
public:
	//explicit Map(std::string path, float scale, const Vector2f* playerPosition);
	explicit Map(const Texture& texture, float scale, const Vector2f& playerPosition);
	virtual ~Map();

	void Draw(const Rectf& viewPort) const;

private:
	const Texture& m_pMapTexture;
	const Vector2f& m_pPlayerPosition{};
	float m_Scale{};
};

