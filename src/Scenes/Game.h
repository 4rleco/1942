#pragma once

#include "Player/Player.h"
#include "Player/Ammo.h"
#include "Enemy/Enemy.h"
#include "Menu.h"

#include "raylib.h"

namespace game
{
	void Drawgame(Player player, Enemy enemy);

	void UpdateGame(Player& player, Texture2D& playerTexture, Ammo& ammo, Enemy& enemy);
}