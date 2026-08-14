#pragma once
#include "string.h"
class Texture;
class Spritesheet
{
public:
	explicit Spritesheet(const Texture& texture, int numberOfFrames);
	~Spritesheet() = default;

	void Draw(const Vector2f& position = Vector2f{ 0.f, 0.f }, float scale = 1, bool invert = false) const;
	void Update(float deltaTime);

	float GetSpriteHeight() const;
	float GetSpriteWidth() const;

	void Reset();
private:
	Rectf GetSourceRect() const;

	const Texture& m_pSpritesheet;
	const int m_NumberOfFrames{};
	int m_CurrentFrame{ 0 };
	const float m_FrameTime{};
	float m_CurrentFrameTime{ 0.f };
};

