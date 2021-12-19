#pragma once

#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "moduletextures.h"
#include "moduleaudio.h"
#include "pisobody.h"

class Box;

class Enemy : public Module
{
public:
	Enemy(Application* app, bool start_enabled = true);
	virtual ~Enemy();

	bool Start();
	update_status Update(float dt);
	update_status PostUpdate();
	bool CleanUp();
	void SetEnemyLifes(int l);

private:
	int lifes;
	SDL_Texture* graphic;
	Box* enemyBox;
	int enemy_int;
	uint spawnBullet_fx;

};
