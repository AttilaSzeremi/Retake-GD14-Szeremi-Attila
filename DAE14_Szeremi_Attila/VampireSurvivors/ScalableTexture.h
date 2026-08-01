#pragma once
class Texture;
struct ScalableTexture final
{
public:
	//ScalableTexture();
	explicit ScalableTexture(Texture& texture);

	~ScalableTexture() = default;

	void Draw(const Rectf targerRec) const;
private:
	Texture& m_pTexture;
};

