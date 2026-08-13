#pragma once
class Texture;
struct ScalableTexture final
{
public:
	//ScalableTexture();
	explicit ScalableTexture(const Texture& texture);

	~ScalableTexture() = default;

	void Draw(const Rectf targerRec) const;
private:
	const Texture& m_pTexture;
};

