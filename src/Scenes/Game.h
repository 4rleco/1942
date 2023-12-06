#pragma once

#include "Player/Player.h"
#include "Player/Ammo.h"
#include "Enemy/Enemy.h"
#include "Menu.h"

namespace game
{
	void Drawgame(Player player, Enemy enemy);

	void UpdateGame(Player& player, Ammo& ammo, Enemy& enemy);
}