#include "GameLoop.h"

#include "raylib.h"

#include "Player/Player.h"
#include "Player/Ammo.h"
#include "Enemy/Enemy.h"

#include "Scenes/Menu.h"
#include "Scenes/Game.h"
#include "Scenes/Credits.h"

namespace game
{
	void InitGame(Player& player, Ammo& ammo, Enemy& enemy)
	{
		const int width = 1024;
		const int height = 768;

		InitWindow(width, height, "1942");

		InitPlayer(player);
		InitAmmo(ammo, player);
		InitEnemy(enemy);
	}

	void Gameloop()
	{
		Screen screen = Screen::MENU;

		Player player;
		Ammo ammo;

		Enemy enemy;

		InitGame(player, ammo, enemy);

		bool closeGame = false;

		while (!WindowShouldClose() && !closeGame)
		{
			SetExitKey(NULL);

			ExitGame(screen, closeGame);

			switch (screen)
			{
			case Screen::MENU:
				DrawMenu(screen, closeGame);
				break;
			case Screen::GAME:
				UpdateGame(player, ammo, enemy);
				break;
			case Screen::OPTIONS:
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
				Drawgame(player, enemy);
				ReturnToMenu(screen);
				break;
			case Screen::OPTIONS:
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