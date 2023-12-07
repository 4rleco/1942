#include "GameLoop.h"

#include "raylib.h"
#include <iostream>

#include "Player/Player.h"
#include "Player/Ammo.h"
#include "Enemy/Enemy.h"

#include "Scenes/Menu.h"
#include "Scenes/Game.h"
#include "Scenes/Options.h"
#include "Scenes/Credits.h"

using namespace std;

namespace game
{
	void InitGame(Player& player, Ammo& ammo, Enemy& enemy)
	{
		srand(static_cast<unsigned int>(time(NULL)));

		const int width = 1024;
		const int height = 768;

		InitWindow(width, height, "1942");

		InitAudioDevice();

		InitPlayer(player);
		InitAmmo(ammo, player);
		InitEnemy(enemy);
	}

	void InitTextures(Texture2D& playerTexture, Texture2D& playerBullet,
	Texture2D& enemyTexture, Texture2D& background)
	{
		playerTexture = LoadTexture("res/assets/player.png");
		playerBullet = LoadTexture("res/assets/bullet.png");
		enemyTexture = LoadTexture("res/assets/enemy.png");
		background = LoadTexture("res/assets/background.png");
	}

	void InitSounds(Music& gameMusic, Sound& keySound)
	{
		gameMusic = LoadMusicStream("res/sounds/just-relax-11157.mp3");
		keySound = LoadSound("sound-1-167181.wav");
	}

	void Gameloop()
	{
		Screen screen = Screen::MENU;

		Texture2D playerTexture;
		Texture2D playerBullet;
		Texture2D enemyTexture;
		Texture2D background;

		Music gameMusic;
		Sound keySound;

		Player player;
		Ammo ammo;

		Enemy enemy;

		float scrollingBack = 0.0f;

		InitGame(player, ammo, enemy);
		InitTextures(playerTexture, playerBullet, enemyTexture, background);
		InitSounds(gameMusic, keySound);

		bool closeGame = false;

		while (!WindowShouldClose() && !closeGame)
		{
			SetExitKey(NULL);

			ExitGame(screen, closeGame);

			switch (screen)
			{
			case Screen::MENU:
				DrawBackground(background, scrollingBack);
				DrawMenu(screen, keySound, closeGame);
				ResetGame(player, ammo, enemy);
				break;
			case Screen::GAME:
				UpdateGame(player,playerTexture, 
					ammo, playerBullet, enemy, enemyTexture,
				background, gameMusic, scrollingBack);
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
				//Drawgame(player, enemy);
				ReturnToMenu(screen);
				break;
			case Screen::OPTIONS:
				DrawOptions();
				ReturnToMenu(screen);
				break;
			case Screen::CREDITS:
				DrawBackground(background, scrollingBack);
				DrawCredits();
				ReturnToMenu(screen);
				break;
			}

			ClearBackground(GRAY);

			EndDrawing();
		}

		UnloadTexture(playerTexture);
		UnloadTexture(playerBullet);
		UnloadTexture(enemyTexture);
		UnloadTexture(background);

		UnloadMusicStream(gameMusic);
		UnloadSound(keySound);

		CloseAudioDevice();

		CloseWindow();

	}
}