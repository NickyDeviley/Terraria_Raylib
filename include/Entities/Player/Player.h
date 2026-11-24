#include "Entities/Direction.h"
#include "Tiles/Dirt.h"
#include "HitBox.h"

#include <stdint.h>

#ifndef PLAYER_H
#define PLAYER_H

typedef struct GamePlayer 
{
	
	int8_t sizeX;
	int8_t sizeY;
	float posX;
	float posY;
	float lastPosX;
	float lastPosY;
	bool isMoving;
	bool collision;
	int8_t speed;
	Hitbox hb;
	
	Direction direction {RIGHT};

} Player;

void drawPlayer(Player *);
void movePlayer(Player *);
void updateCollision(Player *);

#endif
