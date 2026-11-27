#include "Principal/GameLoop.h"
#include "Config.h"

// DEBUG/TEST
#include "Entities/Player/Player.h"
#include "World/WorldInput.h"

// Managers
#include "Principal/Managers/PhysicsManager.h"
#include "Principal/Managers/EntityManager.h"
#include "Principal/Managers/WorldManager.h"
#include "Principal/Managers/TileManager.h"

// Libraries
#include "raylib.h"
#include <iostream>
#include <stdint.h>

internalMethod void createWindow();
internalMethod void drawPosition(Player *);
internalMethod void draw(Player *, ObjectTile *);
internalMethod void update(Player *);

// Temporary
internalVar int32_t test[100]{};
internalVar uint8_t worldIsOpen { openWorld(test) };
internalVar TileHitbox TileHitBox[100] {};
internalVar uint8_t TempIndex {0};
internalVar uint32_t TColisao {0};
// Temporary

// EXP (Nicky): Método principal que controla o loop do jogo,
// taxa de quadros e taxa de atualização
void gameLoop(void)
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

	Player player {createPlayer()};
	ObjectTile tile {createTile()};

	// NOTE (Nicky): GameLoop
	while (!WindowShouldClose())
	{
		actualTime = std::chrono::high_resolution_clock::now();
		timePassedF = actualTime - lastFrame;
		timePassedU = actualTime - lastUpdate;

		// NOTE (Nicky): Condicional que atualiza a lógica do jogo
		if (timePassedU >= DELTA_UPS)
		{
		
			update(&player);

			lastUpdate = actualTime;
			++UPSCounter;
		}

		// NOTE (Nicky): Condicional que atualiza os gráficos
		if (timePassedF >= DELTA_FPS)
		{
			draw(&player, &tile);

			lastFrame = actualTime;
			++FPSCounter;
		}

		if ((std::chrono::steady_clock::now() - lastCheck) >= (nanoSec)NM_ONE_NANOSECOND)
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

// NOTE (Nicky): Método que cria a janela
internalMethod
void createWindow()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(NM_WINDOW_WIDTH, NM_WINDOW_HEIGHT, "Terraria Clone");
}

// NOTE (Nicky): Método para Debug que
// desenha a posição X e Y do jogador na tela
internalMethod
void drawPosition(Player* player)
{
	DrawText(TextFormat("PosX: %.2f \nPosY: %.2f \n\nColisões: %d",
			 player->worldPosX, player->worldPosY, TColisao),
			 50, 50, 10, DARKGRAY);
}

// NOTE (Nicky): Método que desenha todos os sprites do jogo
internalMethod
void draw(Player* player, ObjectTile* tile)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Desenha o mundo do jogo
	drawWorld(player, tile, test);
	
	// Desenha a posição X e Y do jogador (DEBUG)
	drawPosition(player);

	// Desenha o Jogador
	drawPlayer(player);

	EndDrawing();
}

internalMethod 
void update(Player *player)
{
// WORLD LOGIC/PHYSICS

	// Get Player Position
	int32_t playerCenterX {(int32_t) player->worldPosX + player->sizeX};
	int32_t playerCenterY {(int32_t) player->worldPosY + player->sizeY};

	int32_t playerIndexPositionX {(playerCenterX + (tileSize / 2)) / tileSize};
	int32_t playerIndexPositionY {(playerCenterY + (tileSize / 2)) / tileSize};

	// Identify the tiles Next to the Player
	

	// Calculate the hitbox
	TempIndex = 0;
	for (uint8_t i = 0; i < 10; ++i)
	{
		for (uint8_t j = 0; j < 10; ++j)
		{
			TileHitBox[TempIndex] = calcWorldHitBox(j, i);
			++TempIndex;
		}
	}
// WORLD LOGIC/PHYSICS

// PLAYER LOGIC/PHYSICS
	// Move
	movePlayer(player);

	// Check Collision
	for (int i = 0; i < 100; ++i)
	{
		player->isColliding = CheckCollision(&(player->hb), &(TileHitBox[i]));
		if (player->isColliding)
		{
			++TColisao;
			break;
		}
	}

	// if Collision is true (Teleport Player and hitbox)
	if (player->isColliding == true)
	{
		player->worldPosX = player->worldLastPosX;
		player->worldPosY = player->worldLastPosY;

		updateCollision(player);
	}

	// update lastPosX and lastPosY, reset collision
	player->worldLastPosX = player->worldPosX;
	player->worldLastPosY = player->worldPosY;
	player->isColliding = false;
// PLAYER LOGIC/PHYSICS

}