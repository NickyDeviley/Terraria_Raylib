#include "Principal/Managers/EntityManager.h"
#include "Config.h"

#include "Principal/Managers/PhysicsManager.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

Player createPlayer(void)
{
	Player player{};
	player.sizeX = NM_PLAYER_SIZE_X * NM_SIZE_SCALE;
	player.sizeY = NM_PLAYER_SIZE_Y * NM_SIZE_SCALE;
	player.screenPosX = (NM_WINDOW_WIDTH / 2) - (player.sizeX / 2);
	player.screenPosY = (NM_WINDOW_HEIGHT / 2) - (player.sizeY / 2);
	player.worldPosX = (player.sizeX * (-1));
	player.worldPosY = (player.sizeY * (-1));
	player.worldLastPosX = player.worldPosX;
	player.worldLastPosY = player.worldPosY;
	player.isColliding = false;
	player.speed = 1.5;
	player.playerColor = BLACK;
	player.hb = { player.worldPosX, player.worldPosY,
				  player.worldPosX + player.sizeX,
				  player.worldPosY + player.sizeY };
	return(player);
}