#include "Ammo.h"

void InitAmmo(Ammo& ammo, Player player)
{
	for (int i = 0; i < MAX_AMMO; i++)
	{
		InitBullet(ammo.bullet[i], player);
	}

	ammo.speed = 100.0f;
}

void DrawBullet(Ammo ammo, Texture2D& playerBullet)
{
	for (int i = 0; i < MAX_AMMO; i++)
	{
		if (ammo.bullet[i].shooted)
		{
			//DrawCircle(static_cast<int>(ammo.bullet[i].posX), static_cast<int>(ammo.bullet[i].posY), ammo.bullet[i].radius, GREEN);
			DrawTexture(playerBullet, static_cast<int>(ammo.bullet[i].posX), static_cast<int>(ammo.bullet[i].posY), WHITE);
		}
	}
}