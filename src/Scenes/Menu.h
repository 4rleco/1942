#pragma once

enum class Screen
{
	MENU,
	GAME,
	OPTIONS,
	CREDITS,
	EXIT
};

// dibuja el men�
void DrawMenu(Screen& screen, bool& closeGame);

void ReturnToMenu(Screen& screen);

void ExitGame(Screen screen, bool& closeGame);