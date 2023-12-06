#include "Menu.h"

void DrawMenu(Screen& screen, Sound& keySound, bool& closeGame)
{
	DrawText("1942", GetScreenWidth() / 2 - 50, GetScreenHeight() - 600, 100, BLACK);
	DrawText("Use the left button of the mosue to chosse an option", GetScreenWidth() - 750, GetScreenHeight() / 2 - 100, 20, BLACK);
	DrawText("Play", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 30, RED);
	DrawText("Options", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 30, 30, RED);
	DrawText("Credits", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 60, 30, RED);
	DrawText("Exit", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 90, 30, RED);

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 40
		&& GetMousePosition().y >= GetScreenHeight() / 2 && GetMousePosition().y <= GetScreenHeight() / 2 + 20)
	{
		DrawText("Play", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::GAME;
			PlaySound(keySound);
		}
	}

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 70
		&& GetMousePosition().y >= GetScreenHeight() / 2 + 30 && GetMousePosition().y <= GetScreenHeight() / 2 + 50)
	{
		DrawText("Options", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 30, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::OPTIONS;
		}
	}

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 80
		&& GetMousePosition().y >= GetScreenHeight() / 2 + 60 && GetMousePosition().y <= GetScreenHeight() / 2 + 80)
	{
		DrawText("Credits", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 60, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::CREDITS;
		}
	}

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 40
		&& GetMousePosition().y >= GetScreenHeight() / 2 + 90 && GetMousePosition().y <= GetScreenHeight() / 2 + 110)
	{
		DrawText("Exit", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 90, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			closeGame = true;
		}
	}

	DrawText("1.0", GetScreenWidth() - 60, GetScreenHeight() - 40, 40, WHITE);
}

void ReturnToMenu(Screen& screen)
{
	if (screen != Screen::MENU)
	{
		if (IsKeyPressed(KeyboardKey::KEY_ESCAPE))
		{
			screen = Screen::MENU;
		}
	}
}

void ExitGame(Screen screen, bool& closeGame)
{
	if (screen == Screen::MENU && IsKeyPressed(KeyboardKey::KEY_ESCAPE))
	{
		closeGame = true;
	}
}