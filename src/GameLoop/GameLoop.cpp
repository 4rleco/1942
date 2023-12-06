#include "GameLoop.h"

#include "raylib.h"

#include "Player/Player.h"
#include "Player/Bullet.h"
#include "Enemy/Enemy.h"

#include "Scenes/Menu.h"
#include "Scenes/Game.h"
#include "Scenes/Credits.h"

namespace game
{
	void InitGame(Player& player, Bullet& bullet, Enemy& enemy)
	{
		const int width = 1024;
		const int height = 768;

		InitWindow(width, height, "1942");

		InitPlayer(player);
		InitBullet(bullet, player);
		InitEnemy(enemy);
	}

	void Gameloop()
	{
		Screen screen = Screen::MENU;

		Player player;
		Bullet bullet;

		Enemy enemy;

		InitGame(player, bullet, enemy);

		bool closeGame = false;

		while (!WindowShouldClose() && !closeGame)
		{
			SetExitKey(NULL);

			switch (screen)
			{
			case Screen::MENU:
				DrawMenu(screen, closeGame);
				break;
			case Screen::GAME:
				UpdateGame(player, enemy);
				break;
			case Screen::CREDITS:
				break;
			}

			BeginDrawing();

			switch (screen)
			{
			case Screen::MENU:
				break;
			case Screen::GAME:
				Drawgame(player, bullet,  enemy);
				ReturnToMenu(screen);
				break;
			case Screen::CREDITS:
				DrawCredits();
				ReturnToMenu(screen);
				break;
			}

			ClearBackground(GRAY);

			EndDrawing();
		}

		CloseWindow();

	}
}