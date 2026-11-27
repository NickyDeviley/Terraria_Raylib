#include "Config.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

#ifndef TILEMANAGER_H
#define TILEMANAGER_H

// EXP (Nicky): Struct que representa os tiles individuais
typedef struct IndividualTile
{
	uint8_t ID;				// Identificador do tile (65.536)
	bool isSolid;			// O bloco é sólido
	uint8_t rigidValue;		// O quão difícil é quebrar esse tile

	Color tColor;			// Cor que presenta o tile (Temporário)

} ObjectTile, Tile;

ObjectTile createTile(void);
void inputTiles(void);

#endif