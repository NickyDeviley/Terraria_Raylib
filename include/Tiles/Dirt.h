#include "HitBox.h"

#include <stdint.h>

#ifndef DIRT_H
#define DIRT_H

typedef struct DirtTile
{

	float posX;
	float posY;
	float size;
	Hitbox hb;

} dirt;

#endif