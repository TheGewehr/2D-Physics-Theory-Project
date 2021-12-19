#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysbodyController.h"
#include "pisobody.h"
#include "moduletextures.h"
#include "Collisions.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	wall01 = NULL;
	wall02 = NULL;
	win_Screen = NULL;
	loose_Screen = NULL;
	background = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;
	App->player->SetPlayerLifes(3);

	App->physics->AddBoxToWorld(0, 0, 100, 2500, 0, 0, 2);

	App->physics->AddBoxToWorld(0, 0, 100, 2500, 0, 0, 2);

	App->physics->AddBoxToWorld(1500, 0, 100, 2500, 0, 0, 2);
	

	//App->audio->PlayMusic("worms/Audio/Thomas_the_Dank_Engine_SFM_Music_Video-lzmWzXLPa6I.ogg");
	App->audio->PlayMusic("worms/Audio/toby-fox-UNDERTALE-Soundtrack-43-Temmie-Village.ogg");
	//App->audio->PlayMusic("worms/Audio/MadWorld-GaryJules.ogg");



	wall01 = App->textures->Load("worms/map/wall.png");
	wall02 = App->textures->Load("worms/map/wall2.png");
	win_Screen = App->textures->Load("worms/map/winscreen.png");
	loose_Screen = App->textures->Load("worms/map/losescreen.png");
	background = App->textures->Load("worms/map/wallpaper.png");


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update(float dt)
{
	App->renderer->Blit(background,0,0 );
	App->renderer->Blit(wall01,0,0);
	App->renderer->Blit(wall01, 1500, 0);
	App->renderer->Blit(wall02, 0,0);
	
	//App->renderer->Blit(win_Screen,0,0 );
	//App->renderer->Blit(loose_Screen,0,0 );

	App->physics->Draw();
	

	return UPDATE_CONTINUE;
}