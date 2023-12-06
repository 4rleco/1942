#include "Options.h"

#include "raylib.h"

void DrawOptions()
{
	DrawText("To Move the player use the arrow keys", 40, 20, 25, WHITE);
	DrawText("To shoot use the sapce bar", 40, 50, 25, WHITE);
	DrawText("The game ends when you collide with an enemy", 40, 130, 25, WHITE);
	DrawText("To return to the menu use the esc key,", 40, 240, 25, WHITE);
	DrawText("it aplies to every scene, but in the menu, closes the game", 40, 280, 25, WHITE);
}