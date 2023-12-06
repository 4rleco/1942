#pragma once

struct Enemy
{
	float posX;
	float posY;

	int width;
	int height;

	float speed;

	bool destroyed;
};

void InitEnemy(Enemy& enemy);