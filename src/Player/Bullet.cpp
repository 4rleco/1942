#include "Bullet.h"

void InitBullet(Bullet& bullet, Player player)
{
	bullet.posX = player.posX + player.width / 2;
	bullet.posY = player.posY;

	bullet.radius = 10.0f;

	bullet.speed = 1.0f;
}