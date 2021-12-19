#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Collisions.h"
#include "ModuleInput.h"
#include "Physics.h"
//#include "PhysBody.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	//App->physics->AddBoxToWorld(100, 100, 100, 100, 1);

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");


	lifes  = 3;
	graphic = App->textures->Load("worms/weapons/Grenade.png");
	
	playerBox;

	spawnBullet_fx;


	return true;
	

}

void ModulePlayer::SetPlayerLifes(int l)
{
	lifes = l;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	return UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	//App->renderer->Blit(graphic,);
	return UPDATE_CONTINUE;
}