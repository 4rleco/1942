#pragma once

enum class Screen
{
	MENU,
	GAME,
	CREDITS,
	EXIT
};

// dibuja el menú
void DrawMenu(Screen& screen, bool& closeGame);

void ReturnToMenu(Screen& screen);