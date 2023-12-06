#include "GameLoop.h"

#include "raylib.h"
#include <iostream>

#include "Enemy/Enemy.h"
#include "Scenes/Menu.h"

namespace game
{
	void InitGame(Enemy& enemy)
	{
		const int width = 1024;
		const int height = 768;

		InitWindow(width, height, "1942");

		InitEnemy(enemy);
	}

	void Drawgame(Enemy enemy)
	{
		DrawRectangle(static_cast<int>(enemy.posX), static_cast<int>(enemy.posY), enemy.width, enemy.height, RED);
	}

	void Gameloop()
	{
		Screen screen = Screen::MENU;

		Enemy enemy;

		InitGame(enemy);

		while (!WindowShouldClose())
		{
			SetExitKey(NULL);

			switch (screen)
			{
			case Screen::MENU:
				DrawMenu(screen);
				break;
			case Screen::GAME:
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
				Drawgame(enemy);
				break;
			case Screen::CREDITS:
				break;
			}

			ClearBackground(GRAY);

			EndDrawing();
		}

		CloseWindow();

	}
}