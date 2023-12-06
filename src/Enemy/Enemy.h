#pragma once

struct Enemy
{
	float posX;
	float posY;

	int width;
	int height;

	bool destroyed;
};

void InitEnemy(Enemy& enemy);