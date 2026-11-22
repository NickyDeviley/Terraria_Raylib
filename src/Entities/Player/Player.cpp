#include "Entities/Player/Player.h"
#include "raylib.h"

void drawPlayer(Player *player)
{
	DrawRectangle(player->posX, player->posY, player->sizeX, player->sizeY, BLACK);
}

void movePlayer(Player *player)
{
	if (player->direction == RIGHT)
	{
		player->posX += player->speed;
	}
	if (player->direction == LEFT)
	{
		player->posX -= player->speed;
	}
}