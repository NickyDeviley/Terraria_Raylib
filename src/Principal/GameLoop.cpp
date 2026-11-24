#include "Entities/Player/Player.h"
#include "Config.h"
#include "Tiles/Dirt.h"
#include "Principal/GameLoop.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

internalMethod
void createWindow()   
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Terraria Clone");
}

internalMethod
void drawPosition(Player *player)
{
	// NOTE (Nicholas): Método para Debug que desenha a posição X e Y
	// do jogador na tela
	DrawText(TextFormat("PosX: %.2f \nPosY: %.2f",
		player->posX, player->posY),
		50, 50, 10, DARKGRAY);
}

internalMethod
void draw(Player *player, dirt *tile)
{
	// NOTE (Nicholas): Método que desenha todos os sprites do jogo
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawPosition(player);

	DrawRectangle(tile->posX, tile->posY, tile->size, tile->size, BROWN);

	drawPlayer(player);

	EndDrawing();
}

internalMethod
bool colidiu(Player *player, dirt *tile)
{
	return(player->hb.X <= tile->hb.supD &&
		   player->hb.supD >= tile->hb.X &&
		   player->hb.Y <= tile->hb.infE &&
		   player->hb.infE >= tile->hb.Y);
}

void gameLoop(Player* player)
{
	createWindow();

	// std::chrono::steady_clock::time_point
	timePoint actualTime{ std::chrono::high_resolution_clock::now() };
	timePoint lastFrame{ std::chrono::high_resolution_clock::now() };
	timePoint lastUpdate{ std::chrono::high_resolution_clock::now() };
	duration timePassedF{};
	duration timePassedU{};

	timePoint lastCheck{ std::chrono::high_resolution_clock::now() };
	uint8_t FPSCounter{ 0 };
	uint8_t UPSCounter{ 0 };

	dirt tile {};
	tile.posX = 200;
	tile.posY = 200;
	tile.size = 40;
	tile.hb = {tile.posX, tile.posY,
			   tile.posX + tile.size,
			   tile.posY + tile.size};

	while (!WindowShouldClose())
	{
		actualTime = std::chrono::high_resolution_clock::now();

		timePassedF = actualTime - lastFrame;
		timePassedU = actualTime - lastUpdate;

		if (timePassedU >= DELTA_UPS)
		{
			// atualiza a lógica

			// DEBUG
			//std::cout << colidiu(player, &tile) << std::endl;

			// Movement Logic:

				// MOVE
			player->isMoving = false;
			if (IsKeyDown(KEY_RIGHT))
			{
				player->direction = Direction::RIGHT;
				//player->isMoving = true;
				movePlayer(player);
			}
			if (IsKeyDown(KEY_LEFT))
			{
				player->direction = Direction::LEFT;
				//player->isMoving = true;
				movePlayer(player);
			}
			if (IsKeyDown(KEY_UP))
			{
				player->direction = Direction::UP;
				//player->isMoving = true;
				movePlayer(player);
			}
			if (IsKeyDown(KEY_DOWN))
			{
				player->direction = Direction::DOWN;
				//player->isMoving = true;
				movePlayer(player);
			}

				// Check Collision
			player->collision = colidiu(player, &tile);

				// if Collision is true (Teleport Player and hitbox)
			if (player->collision == true)
			{
				player->posX = player->lastPosX;
				player->posY = player->lastPosY;

				updateCollision(player);
			}

				// if Collision is false (update lastPosX and lastPosY)
			player->lastPosX = player->posX;
			player->lastPosY = player->posY;
			player->collision = false;

			lastUpdate = actualTime;
			++UPSCounter;
		}

		if (timePassedF >= DELTA_FPS)	// atualiza o frame
		{

			draw(player, &tile);

			lastFrame = actualTime;
			++FPSCounter;
		}


		if ((std::chrono::steady_clock::now() - lastCheck) >= (nanoSec)ONE_NANOSECOND)
		{
			lastCheck = std::chrono::steady_clock::now();
			//std::cout << "FPS: " << static_cast<int>(FPSCounter) << std::endl;
			//std::cout << "UPS: " << static_cast<int>(UPSCounter) << std::endl;
			FPSCounter = 0;
			UPSCounter = 0;

		}
	}

	CloseWindow();
}