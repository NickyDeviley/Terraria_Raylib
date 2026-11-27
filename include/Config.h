#include <chrono>
#include <stdint.h>

#ifndef CONFIG_H
#define CONFIG_H

#define NM_WINDOW_WIDTH 1280	// 20
#define NM_WINDOW_HEIGHT 720	// 11,25
#define NM_FPS 60
#define NM_UPS 120
#define NM_ONE_NANOSECOND 1000000000

#define nanoSec std::chrono::nanoseconds

#define internalMethod static
#define internalVar static

// Terraria Oficial sizes
// Player size: 15x24
// Tiles size : 8x8

// Tamanho de tiles e player
#define NM_TILE_SIZE 16
#define NM_PLAYER_SIZE_X 30
#define NM_PLAYER_SIZE_Y 48
#define NM_SIZE_SCALE 4

// Apelidos para tipos existêntes
using timePoint = std::chrono::high_resolution_clock::time_point;
using duration = std::chrono::high_resolution_clock::duration;

// DELTA TIME do FPS e UPS, eles medem quanto tempo 
// entre um quadro ou atualização de lógica ocorre 
// dentro de um segundo
constexpr nanoSec DELTA_FPS {NM_ONE_NANOSECOND / NM_FPS};
constexpr nanoSec DELTA_UPS {NM_ONE_NANOSECOND / NM_UPS};

// Tile Size
constexpr uint8_t tileSize {NM_TILE_SIZE * NM_SIZE_SCALE};

// Worlds Different Sizes
constexpr uint32_t smallWorldSize {4200 * 1200};	//  5.040.000
constexpr uint32_t mediumWorldSize {6400 * 1800};	// 11.520.000
constexpr uint32_t LargerWorldSize {8400 * 2400};	// 20.160.000

#endif