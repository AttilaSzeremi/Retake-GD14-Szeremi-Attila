#pragma once
#include "GameState.h"
class Texture;
class StartScreen final : public GameState
{
public:
	explicit StartScreen(Texture* background);
	~StartScreen() = default;

	virtual void Draw() const override;
	virtual void Update(float deltaTime, const Uint8* pStates) override;

	virtual void HandleMouseUpEvent(const Vector2f& mousePos) override;
	virtual void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
private:
	const Rectf m_StartButton{};

	Texture* m_pBackgroundTexture{};
};

