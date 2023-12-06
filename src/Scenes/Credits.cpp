#include "Credits.h"

#include "raylib.h"

void DrawCredits()
{
	DrawText("Game made by", GetScreenWidth() / 2 - 150, 250, 40, BLACK);
	DrawText("Dev: Joaquin Herrero Lendner", GetScreenWidth() / 2 - 230, 350, 30, BLACK);
	DrawText("Assets: Joaquin Herrero Lendner", GetScreenWidth() / 2 - 230, 385, 30, BLACK);

	DrawText("I took the sounds from: ", 100, 450, 25, BLACK);
	DrawText("pixabay.com/es/music/search/genre/pequeñas emociones", 100, 480, 25, BLACK);
	DrawText("and http://www.sonidosmp3gratis.com", 100, 510, 25, BLACK);
}