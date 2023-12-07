#include "Game.h"

#include <iostream>

using namespace std;

namespace game
{
	void DrawBackground(Texture2D& background, float& scrollingBack)
	{
		DrawTextureEx(background, Vector2{ 20, +scrollingBack }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(background, Vector2{ 20, background.height * 2 + scrollingBack, }, 0.0f, 2.0f, WHITE);

		background.height = GetScreenHeight();
		background.width = GetScreenWidth();
	}

	void Drawgame(Player player, Enemy enemy)
	{
		DrawRectangle(static_cast<int>(player.posX), static_cast<int>(player.posY), player.width, player.height, YELLOW);

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

	void Shoot(Ammo& ammo, Player player)
	{
		for (int i = 0; i < MAX_AMMO; i++)
		{
			if (!ammo.bullet[i].shooted)
			{
				if (IsKeyPressed(KeyboardKey::KEY_SPACE))
				{
					ammo.bullet[i].posX = player.posX + player.width / 2;
					ammo.bullet[i].posY = player.posY;

					ammo.bullet[i].shooted = true;					

					//cout << "can shoot " << i << endl;
				}

			}

			if (ammo.bullet[i].shooted)
			{
				ammo.bullet[i].posY -= ammo.speed * GetFrameTime();

				//cout << "Shoot " << i << endl;
			}
		}
	}

	void BulletScreenLimits(Ammo& ammo)
	{
		for (int i = 0; i < MAX_AMMO; i++)
		{
			if (ammo.bullet[i].shooted)
			{
				if (ammo.bullet[i].posY <= 0)
				{
					ammo.bullet[i].shooted = false;
				}
			}
		}
	}

	void BulletEnemyCollision(Ammo& ammo, Enemy& enemy)
	{
		for (int i = 0; i < MAX_AMMO; i++)
		{
			if (ammo.bullet[i].shooted)
			{
				float bulletWidth = ammo.bullet[i].radius * 2;
				float bulletHeight = ammo.bullet[i].radius * 2;

				if ((enemy.posX + enemy.width >= ammo.bullet[i].posX) &&
					(enemy.posX <= (ammo.bullet[i].posX - ammo.bullet[i].radius) + bulletWidth) &&
					(enemy.posY + enemy.height >= ammo.bullet[i].posY) &&
					(enemy.posY <= (ammo.bullet[i].posY - ammo.bullet[i].radius) + bulletHeight))
				{
					enemy.posY = -5;

					enemy.posX = static_cast<float>(rand() % GetScreenWidth());

					if (enemy.posX <= 0)
					{
						enemy.posX += static_cast<float>(0 + enemy.width);
					}

					if (enemy.posX >= GetScreenWidth())
					{
						enemy.posX -= static_cast<float>(GetScreenWidth() - enemy.width);
					}

					ammo.bullet[i].shooted = false;
				}
			}
		}
	}

	void EnemyMovement(Enemy& enemy, Texture2D& enemyTexture)
	{
		enemy.posY += enemy.speed * GetFrameTime();

		enemyTexture.width = enemy.width;
		enemyTexture.height = enemy.height;
	}

	void EnemyScreenlimits(Enemy& enemy)
	{
		if (enemy.posY >= GetScreenHeight())
		{
			enemy.posY = -5;

			enemy.posX = static_cast<float>(rand() % GetScreenWidth());

			if (enemy.posX <= 0)
			{
				enemy.posX += static_cast<float>(0 + enemy.width);
			}

			if (enemy.posX >= GetScreenWidth())
			{
				enemy.posX -= static_cast<float>(GetScreenWidth() - enemy.width);
			}
		}
	}

	void ResetGame(Player& player, Ammo& ammo, Enemy& enemy)
	{
		player.posX = static_cast<float>(GetScreenWidth() / 2);
		player.posY = static_cast<float>(GetScreenHeight() - 100);

		player.crashed = false;

		enemy.posX = 350;
		enemy.posY = 0;

		for (int i = 0; i < MAX_AMMO; i++)
		{
			ammo.bullet[i].shooted = false;
		}
	}

	void UpdateGame(Player& player, Texture2D& playerTexture,
		Ammo& ammo, Texture2D& playerBullet, Enemy& enemy, Texture2D& enemyTexture,
		Texture2D& background, Music& gameMusic, float& scrollingBack)
	{
		DrawBackground(background, scrollingBack);

		DrawTexture(playerTexture, static_cast<int>(player.posX), static_cast<int>(player.posY), WHITE);

		DrawTexture(enemyTexture, static_cast<int>(enemy.posX), static_cast<int>(enemy.posY), WHITE);


		if (!player.crashed)
		{
			scrollingBack -= 50.0f * GetFrameTime();

			if (scrollingBack <= -background.height * 2) scrollingBack = 0;

			PlayMusicStream(gameMusic);

			PlayerMovement(player);

			PlayerScreenLimits(player);

			Shoot(ammo, player);

			DrawBullet(ammo, playerBullet);

			EnemyMovement(enemy, enemyTexture);

			EnemyScreenlimits(enemy);

			BulletScreenLimits(ammo);

			BulletEnemyCollision(ammo, enemy);

			PlayerEnemyColision(player, enemy);

			UpdateMusicStream(gameMusic);
		}

		if (player.crashed)
		{
			DrawText("GAME OVER", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 50, BLACK);

			DrawText("Press esc to return to the menu", GetScreenWidth() / 2-50, GetScreenHeight() / 2 + 60, 25, BLACK);
		
			DrawText("Or press enter to play again", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 25, BLACK);

			if (IsKeyPressed(KeyboardKey::KEY_ENTER))
			{
				ResetGame(player, ammo, enemy);
			}
		}
	}
}