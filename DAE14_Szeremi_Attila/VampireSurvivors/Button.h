#pragma once
#include "ScalableTexture.h"
#include "Texture.h"
class Button final
{
public:
	//Button();
	explicit Button(const Texture& texture, const Rectf& bounds, const Texture& text);
	~Button() = default;

	bool IsClicked() const;
	void Draw() const;

	void Reset();
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e);
	void ChangeBounds(const Rectf& bounds);


private:
	const ScalableTexture m_Texture;
	const Texture& m_pButtonText;
	Rectf m_Bounds;

	bool m_IsClicked{ false };
};

