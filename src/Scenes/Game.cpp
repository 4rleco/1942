#include "Game.h"

#include "raylib.h"

void Drawgame(Player player, Bullet bullet, Enemy enemy)
{
	DrawRectangle(static_cast<int>(player.posX), static_cast<int>(player.posY), player.width, player.height, YELLOW);

	DrawCircle(static_cast<int>(bullet.posX), static_cast<int>(bullet.posY), bullet.radius, GREEN);

	DrawRectangle(static_cast<int>(enemy.posX), static_cast<int>(enemy.posY), enemy.width, enemy.height, RED);
}