#include "Entities/Player/Player.h"
#include "Config.h"
#include "raylib.h"

#include <iostream>
#include <chrono>
#include <string>

#define internalMethod static

internalMethod void gameLoop(Player *);

int main(int argc, char *argv[])
{

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Terraria Clone");

	Player player {};
	player.sizeX = 40;
	player.sizeY = 40;
	player.posX = (WINDOW_WIDTH / 2) - (player.sizeX / 2);
	player.posY = (WINDOW_HEIGHT / 2) - (player.sizeY / 2);
	player.speed = 1.5;

	gameLoop(&player);

	return(0);
}


internalMethod 
void gameLoop(Player *player)
{

	// std::chrono::steady_clock::time_point
	timePoint actualTime {std::chrono::high_resolution_clock::now()};
	timePoint lastFrame {std::chrono::high_resolution_clock::now()};
	timePoint lastUpdate {std::chrono::high_resolution_clock::now()};
	duration timePassedF {};
	duration timePassedU {};
	
	timePoint lastCheck {std::chrono::high_resolution_clock::now()};
	uint8_t FPSCounter {0};
	uint8_t UPSCounter {0};

	while (!WindowShouldClose())
	{

		actualTime = std::chrono::high_resolution_clock::now();

		timePassedF = actualTime - lastFrame;
		timePassedU = actualTime - lastUpdate;

		if (timePassedU >= DELTA_UPS)
		{
			// atualiza a lógica

			if (IsKeyDown(KEY_RIGHT))
			{
				player->direction = Direction::RIGHT;
				movePlayer(player);
			}
			if (IsKeyDown(KEY_LEFT))
			{
				player->direction = Direction::LEFT;
				movePlayer(player);
			}
			if (IsKeyDown(KEY_UP)) player->posY--;
			if (IsKeyDown(KEY_DOWN)) player->posY++;

			lastUpdate = actualTime;
			++UPSCounter;
		}

		if (timePassedF >= DELTA_FPS)
		{
			// atualiza o frame
			
			BeginDrawing();
			ClearBackground(RAYWHITE);

			/*
			DrawText(TextFormat("FPS: %d \nUPS: %d", 
								static_cast<int>(FPSCounter), 
								static_cast<int>(UPSCounter)), 
								50, 50, 10, DARKGRAY);
			*/
			DrawText(TextFormat("PosX: %.2f \nPosY: %.2f",
								player->posX,
								player->posY),
								50, 50, 10, DARKGRAY);

			drawPlayer(player);



			EndDrawing();

			lastFrame = actualTime;
			++FPSCounter;
		}


		if ((std::chrono::steady_clock::now() - lastCheck) >= (nanoSec) ONE_NANOSECOND)
		{
			lastCheck = std::chrono::steady_clock::now();
			std::cout << "FPS: " << static_cast<int>(FPSCounter) << std::endl;
			std::cout << "UPS: " << static_cast<int>(UPSCounter) << std::endl;
			FPSCounter = 0;
			UPSCounter = 0;
		
		}
	}

	CloseWindow();

}