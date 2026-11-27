#include "Principal/Managers/TileManager.h"
#include "Config.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

ObjectTile createTile(void)
{
	ObjectTile tile{};
	tile.ID = 1;
	tile.tColor = BROWN;
	
	return(tile);
}

void inputTiles(void)
{
	
}