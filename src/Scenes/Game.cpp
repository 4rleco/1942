#include "Game.h"

#include "raylib.h"

void Drawgame(Player player, Bullet bullet, Enemy enemy)
{
	DrawRectangle(static_cast<int>(player.posX), static_cast<int>(player.posY), player.width, player.height, YELLOW);

	DrawCircle(static_cast<int>(bullet.posX), static_cast<int>(bullet.posY), bullet.radius, GREEN);

	DrawRectangle(static_cast<int>(enemy.posX), static_cast<int>(enemy.posY), enemy.width, enemy.height, RED);
}

void PlayerMovement(Player& player)
{
	if (IsKeyDown(KeyboardKey::KEY_UP))
	{
		player.posY -= player.speed * GetFrameTime();
	}

	if (IsKeyDown(KeyboardKey::KEY_DOWN))
	{
		player.posY += player.speed * GetFrameTime();
	}

	if (IsKeyDown(KeyboardKey::KEY_RIGHT))
	{
		player.posX += player.speed * GetFrameTime();
	}

	if (IsKeyDown(KeyboardKey::KEY_LEFT))
	{
		player.posX -= player.speed * GetFrameTime();
	}
}

void PlayerScreenLimits(Player& player)
{
	if (player.posX <= 0)
	{
		player.posX = 0;
	}

	if (player.posX + player.width >= GetScreenWidth())
	{
		player.posX = static_cast<float>(GetScreenWidth() - player.width);
	}

	if (player.posY <= 0)
	{
		player.posY = 0;
	}

	if (player.posY + player.height >= GetScreenHeight())
	{
		player.posY = static_cast<float>(GetScreenHeight() - player.height);
	}
}

void PlayerEnemyColision(Player& player, Enemy enemy)
{
	if ((player.posX + player.width >= enemy.posX) &&
		(player.posX <= enemy.posX + enemy.width) &&
		(player.posY + player.height >= enemy.posY) &&
		(player.posY <= enemy.posY + enemy.height))
	{
		player.crashed = true;
	}
}

void UpdateGame(Player& player, Enemy& enemy)
{
	if (!player.crashed)
	{
		PlayerMovement(player);

		PlayerScreenLimits(player);

		PlayerEnemyColision(player, enemy);
	}

	if (player.crashed)
	{
		DrawText("GAME OVER", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 50, BLACK);
	}
}