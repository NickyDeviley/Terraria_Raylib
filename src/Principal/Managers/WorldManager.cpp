#include "Principal/Managers/WorldManager.h"

#include "Config.h"

#include "Entities/Player/Player.h"
#include "Principal/Managers/TileManager.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

// EXP (Nicky): Método que gera o mundo do jogo
void generateWorld(InfoTile *WorldMap)
{
	// Lógica para a geração do mundo
}

// EXP (Nicky): Método que desenha o mundo do jogo utilizando
// condicionais e laços para desenhar apenas os tiles na tela
void drawWorld(Player *player, ObjectTile *tile, int32_t *test)
{
	// Camera
	uint32_t camX = player->worldPosX - player->screenPosX;
	uint32_t camY = player->worldPosY - player->screenPosY;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			// Calc position of the tiles on world
			uint32_t tileWorldPosX = j * tileSize;
			uint32_t tileWorldPosY = i * tileSize;

			// Calc position of the tiles on screen
			uint32_t tileScreenX = tileWorldPosX - camX;
			uint32_t tileScreenY = tileWorldPosY - camY;

			// NOTE (Nicky): Substituir condicional
			// por um map de tiles com ID
			if (tile->ID == test[i])
			{
				// Draw Tiles with color
				DrawRectangle(tileScreenX,
							  tileScreenY,
							  tileSize,
							  tileSize,
							  tile->tColor);
			}
		}
	}
}