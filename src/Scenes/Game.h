#pragma once

#include "Player/Player.h"
#include "Player/Bullet.h"
#include "Enemy/Enemy.h"
#include "Menu.h"

void Drawgame(Player player, Bullet bullet, Enemy enemy);

void UpdateGame(Player& player, Enemy& enemy);