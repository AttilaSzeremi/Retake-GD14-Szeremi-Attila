#include "pch.h"
#include "Map.h"
#include "Texture.h"
//#include "utils.h"
#include <iostream>



Map::Map(const Texture& texture, float scale, const Vector2f& playerPosition) :
	m_pMapTexture{ texture },
	m_Scale{ scale },
	m_pPlayerPosition{ playerPosition }
{
}

Map::~Map()
{
}

void Map::Draw(const Rectf& viewPort) const {
	const Vector2f position{ m_pPlayerPosition };
	// Calculates which map section each corner of the viewport is
	const int numberOfCorners{ 4 };
	Vector2f viewPortCorner[numberOfCorners]{};
	viewPortCorner[0] = Vector2f{
		std::floorf((position.x - viewPort.width / 2.f) / m_Scale / (m_pMapTexture.GetWidth())),
		std::floorf((position.y - viewPort.height / 2.f) / m_Scale / (m_pMapTexture.GetHeight()))
	};
	viewPortCorner[1] = Vector2f{
		std::floorf((position.x - viewPort.width / 2.f) / m_Scale / (m_pMapTexture.GetWidth())),
		std::floorf((position.y + viewPort.height / 2.f) / m_Scale / (m_pMapTexture.GetHeight()))
	};
	viewPortCorner[2] = Vector2f{
		std::floorf((position.x + viewPort.width / 2.f) / m_Scale / (m_pMapTexture.GetWidth())),
		std::floorf((position.y - viewPort.height / 2.f) / m_Scale / (m_pMapTexture.GetHeight()))
	};
	viewPortCorner[3] = Vector2f{
		std::floorf((position.x + viewPort.width / 2.f) / m_Scale / (m_pMapTexture.GetWidth())),
		std::floorf((position.y + viewPort.height / 2.f) / m_Scale / (m_pMapTexture.GetHeight()))
	};

	glPushMatrix(); {
		glTranslatef(-position.x + viewPort.width / 2.f, -position.y + viewPort.height / 2.f, 0);
		glScalef(m_Scale, m_Scale, 0);
		for (int idx{ 0 }; idx < numberOfCorners; ++idx) {
			bool render{ true };
			for (int checkIdx{ 0 }; checkIdx < idx; ++checkIdx) {
				if (viewPortCorner[idx].x == viewPortCorner[checkIdx].x && viewPortCorner[idx].y == viewPortCorner[checkIdx].y) {
					render = false;
				}
			}
			if (render) {
				m_pMapTexture.Draw(
					Vector2f{
						viewPortCorner[idx].x * m_pMapTexture.GetWidth(),
						viewPortCorner[idx].y * m_pMapTexture.GetHeight()
					}
				);
			}
		}
	}
	glPopMatrix();
}
