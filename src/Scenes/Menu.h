#pragma once

enum class Screen
{
	MENU,
	GAME,
	CREDITS,
	EXIT
};

// dibuja el men�
void DrawMenu(Screen& screen);