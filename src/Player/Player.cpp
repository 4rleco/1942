#include "Player.h"

#include "raylib.h"

void InitPlayer(Player& player)
{
	player.posX = static_cast<float>(GetScreenWidth() / 2);
	player.posY = static_cast<float>(GetScreenHeight() - 100);

	player.width = 60;
	player.height = 20;

	player.speed = 1.0f;

	player.crashed = false;
}