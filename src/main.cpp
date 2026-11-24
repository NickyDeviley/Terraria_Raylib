#include "Entities/Player/Player.h"
#include "Config.h"
#include "raylib.h"
#include "Principal/GameLoop.h"

#include <iostream>
#include <chrono>
#include <string>

int main(int argc, char *argv[])
{

	Player player {};
	player.sizeX = 40;
	player.sizeY = 40;
	player.posX = (WINDOW_WIDTH / 2) - (player.sizeX / 2);
	player.posY = (WINDOW_HEIGHT / 2) - (player.sizeY / 2);
	player.lastPosX = player.posX;
	player.lastPosY = player.posY;
	player.collision = false;
	player.speed = 1.5;
	player.hb = {player.posX, player.posY,
				 player.posX + player.sizeX,
				 player.posY + player.sizeY};

	gameLoop(&player);

	return(0);
}
