#include "Config.h"

#include "Entities/Player/Player.h"
#include "Principal/Managers/TileManager.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

// EXP (Nicky): Struct que armazena informações 
// sobre os tiles em cada posição do mapa
typedef struct MapTile
{
	uint8_t tileID;	// Identificador do tile (256)
	uint8_t wallID;	// Identificador da wall (256)

} InfoTile;

void generateWorld(InfoTile *);
void drawWorld(Player *, ObjectTile *, int32_t *);

#endif