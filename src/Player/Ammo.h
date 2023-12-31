#pragma once

#include "Bullet.h"

#include "raylib.h"

#include "Player.h"

const int MAX_AMMO = 20;

struct Ammo
{
	Bullet bullet[MAX_AMMO];

	float speed;
};

void InitAmmo(Ammo& ammo, Player player);

void DrawBullet(Ammo ammo, int i, Texture2D& playerBullet);