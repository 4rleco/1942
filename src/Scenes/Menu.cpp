#include "Menu.h"

#include "raylib.h"

void DrawMenu(Screen& screen, bool& closeGame)
{
	DrawText("Flappy Bird", GetScreenWidth() / 2 - 250, GetScreenHeight() - 600, 100, WHITE);
	DrawText("Use the left button of the mosue to chosse an option", GetScreenWidth() - 750, GetScreenHeight() / 2 - 100, 20, WHITE);
	DrawText("Play", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 30, RED);
	DrawText("Credits", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 30, 30, RED);
	DrawText("Exit", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 60, 30, RED);

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 40
		&& GetMousePosition().y >= GetScreenHeight() / 2 && GetMousePosition().y <= GetScreenHeight() / 2 + 20)
	{
		DrawText("Play", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::GAME;
		}
	}

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 80
		&& GetMousePosition().y >= GetScreenHeight() / 2 + 30 && GetMousePosition().y <= GetScreenHeight() / 2 + 50)
	{
		DrawText("Credits", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 30, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::CREDITS;
		}
	}

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 40
		&& GetMousePosition().y >= GetScreenHeight() / 2 + 60 && GetMousePosition().y <= GetScreenHeight() / 2 + 80)
	{
		DrawText("Exit", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 60, 30, DARKBROWN);
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			closeGame = true;
		}
	}

	DrawText("1.0", GetScreenWidth() - 60, GetScreenHeight() - 40, 40, WHITE);
}

void ReturnToMenu(Screen& screen)
{
	if (screen!=Screen::MENU)
	{
		if (IsKeyPressed(KeyboardKey::KEY_ESCAPE))
		{
			screen = Screen::MENU;
		}
	}
}