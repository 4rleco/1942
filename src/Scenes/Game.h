#pragma once

#include "Player/Player.h"
#include "Player/Ammo.h"
#include "Enemy/Enemy.h"
#include "Menu.h"

#include "raylib.h"

namespace game
{
	void DrawBackground(Texture2D& background, float& scrollingBack);

	void Drawgame(Player player, Enemy enemy);

	void ResetGame(Player& player, Ammo& ammo, Enemy& enemy);

	void UpdateGame(Player& player, Texture2D& playerTexture,
		Ammo& ammo, Texture2D& playerBullet, Enemy& enemy, Texture2D& enemyTexture,
		Texture2D& background, Music& gameMusic, float& scrollingBack);
}