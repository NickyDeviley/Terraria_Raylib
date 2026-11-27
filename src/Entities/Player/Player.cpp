#include "Entities/Player/Player.h"
#include "config.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

void drawPlayer(Player* player)
{
	DrawRectangle(player->screenPosX,
				  player->screenPosY,
				  player->sizeX,
				  player->sizeY,
				  player->playerColor);
}

void movePlayer(Player* player)
{
	// NOTE (Nicky): Atualizar metodo para utilizar
	// um map e os códigos da tecla em um único
	if (IsKeyDown(KEY_RIGHT))
	{
		player->direction = Direction::RIGHT;
		player->worldPosX += player->speed;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		player->direction = Direction::LEFT;
		player->worldPosX -= player->speed;
	}
	if (IsKeyDown(KEY_UP))
	{
		player->direction = Direction::UP;
		player->worldPosY -= player->speed;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		player->direction = Direction::DOWN;
		player->worldPosY += player->speed;
	}

	updateCollision(player);
}

