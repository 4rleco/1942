#include "Enemy.h"

void InitEnemy(Enemy& enemy)
{
	enemy.posX = 30;
	enemy.posY = 20;

	enemy.width = 110;
	enemy.height = 40;

	enemy.destroyed = false;
}