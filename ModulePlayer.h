#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "moduletextures.h"
#include "moduleaudio.h"
#include "pisobody.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	update_status PostUpdate();
	bool CleanUp();
	void SetPlayerLifes(int l);

private:
	int lifes;
	SDL_Texture* graphic;
	PhysBody* playerBox;

	uint spawnBullet_fx;

};