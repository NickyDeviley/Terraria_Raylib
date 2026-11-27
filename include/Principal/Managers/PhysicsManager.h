#include "Config.h"

#include "Principal/Managers/TileManager.h"

#include "raylib.h"
#include <iostream>
#include <stdint.h>

#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

// EXP (Nicky): struct que representa as hitbox dos tiles e entidades
typedef struct GenericHitBox
{
	float X;
	float Y;
	float supD;
	float infE;

} Hitbox, PlayerHitbox, TileHitbox, MonsterHitbox, NPCHitbox, BossHitbox, AttackHitbox, ProjectileHitbox;

// EXP (Nicky): Método que cria e retorna as hitbox dos tiles
// usando seus índices no array do mundo como base.
inline TileHitbox calcWorldHitBox(int32_t X, int32_t Y)
{
	TileHitbox hitbox{(float)X * tileSize,
					  (float)Y * tileSize,
					  (float)(X * tileSize) + tileSize,
					  (float)(Y * tileSize) + tileSize};

	return(hitbox);
}

// EXP (Nicky): Método que calcula se duas hitbox se colidiram
inline bool CheckCollision(Hitbox* hitbox1, Hitbox* hitbox2)
{
	return(hitbox1->X <= hitbox2->supD &&
		hitbox1->supD >= hitbox2->X &&
		hitbox1->Y <= hitbox2->infE &&
		hitbox1->infE >= hitbox2->Y);
}

#endif