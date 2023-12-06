#pragma once

#include "Player.h"

struct Player;

struct Bullet
{
	float posX;
	float posY;

	float radius;

	float speed;
};

void InitBullet(Bullet& bullet, Player player);