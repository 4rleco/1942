#pragma once

struct Enemy
{
	float posX;
	float posY;

	int width;
	int height;
};

void InitEnemy(Enemy& enemy);