#include "Entities/Direction.h"
#include <stdint.h>

#ifndef PLAYER_H
#define PLAYER_H

typedef struct GamePlayer 
{
	
	int8_t sizeX;
	int8_t sizeY;
	float posX;
	float posY;
	int8_t speed;
	
	Direction direction {RIGHT};

} Player;

void drawPlayer(Player *);
void movePlayer(Player *);

#endif
