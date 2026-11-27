#include "Entities/Direction.h"

#include "Principal/Managers/PhysicsManager.h"

#include "raylib.h"
#include <stdint.h>

#ifndef PLAYER_H
#define PLAYER_H

// EXP (Nicky): Struct que representa o player no jogo
typedef struct GamePlayer
{
	uint8_t sizeX;
	uint8_t sizeY;
	uint16_t screenPosX;
	uint16_t screenPosY;
	float worldPosX;
	float worldPosY;
	float worldLastPosX;
	float worldLastPosY;
	bool isColliding;
	int8_t speed;
	Color playerColor;

	PlayerHitbox hb;
	Direction direction {RIGHT};

} Player;

void drawPlayer(Player *);
void movePlayer(Player *);

// INLINE METHODS
inline void updateCollision(Player* player)
{
	player->hb = { player->worldPosX, player->worldPosY,
				   player->worldPosX + player->sizeX,
				   player->worldPosY + player->sizeY };
}

#endif
