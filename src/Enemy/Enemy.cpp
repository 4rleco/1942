#include "Enemy.h"

void InitEnemy(Enemy& enemy)
{
	enemy.posX = 350;
	enemy.posY = 0;

	enemy.width = 110;
	enemy.height = 40;

	enemy.speed = 150.0f;

	enemy.destroyed = false;
}