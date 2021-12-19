#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Collisions.h"
#include "ModuleInput.h"
#include "Physics.h"
#include "Box.h"
#include "pisobody.h"

//#include "PhysBody.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");


	lifes  = 3;
	graphic = App->textures->Load("worms/weapons/Projectile.png");
	

	spawnBullet_fx;
	playerBox =	App->physics->AddBoxToWorld(5000, 000, 100, 100, 1.0, 0.4, 1, 1);

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
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		playerBox->impulseForce.x = 0.00001;
	}
	else if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		playerBox->impulseForce.x = -0.00001;
	}
	else
	{
		playerBox->impulseForce.x = 0.0;
	}

	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
	{
		playerBox->impulseForce.y = -0.000000000001;
	}
	else
	{
		playerBox->impulseForce.y = 0.0;
	}

	if (App->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN)
	{
		App->physics->AddBoxToWorld(playerBox->worldPosition.x + playerBox->width * 0.5 + 10, playerBox->worldPosition.y - playerBox->height * 0.5 - 100, 20, 20, 10, 0.6, 1, 3);
	}
	return UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	App->renderer->Blit(graphic, playerBox->worldPosition.x + playerBox->point01.x, playerBox->worldPosition.y + playerBox->point01.y);
	return UPDATE_CONTINUE;
}