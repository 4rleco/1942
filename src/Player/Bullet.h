#pragma once

#include "Player.h"

struct Player;

struct Bullet
{
	float posX;
	float posY;

	float radius;

	bool shooted;
};

void InitBullet(Bullet& bullet, Player player);