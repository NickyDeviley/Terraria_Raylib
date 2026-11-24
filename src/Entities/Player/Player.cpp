#include "Entities/Player/Player.h"
#include "Tiles/Dirt.h"
#include "raylib.h"

void drawPlayer(Player* player)
{
	DrawRectangle(player->posX, player->posY, player->sizeX, player->sizeY, BLACK);
}

void movePlayer(Player* player)
{
	if (player->direction == RIGHT) { player->posX += player->speed; }
	if (player->direction == LEFT) { player->posX -= player->speed; }
	if (player->direction == UP) { player->posY -= player->speed; }
	if (player->direction == DOWN) { player->posY += player->speed; }

	updateCollision(player);
}

void updateCollision(Player *player)
{
	player->hb = { player->posX, player->posY,
				   player->posX + player->sizeX,
				   player->posY + player->sizeY };
}