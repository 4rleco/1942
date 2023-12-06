#pragma once

#include "Bullet.h"

struct Player
{
	float posX;
	float posY;

	int width;
	int height;

	float speed;

	bool crashed;
};

void InitPlayer(Player& player);