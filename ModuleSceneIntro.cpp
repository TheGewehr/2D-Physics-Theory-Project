#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysbodyController.h"
#include "pisobody.h"
#include "Collisions.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
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
	App->physics->AddBoxToWorld(2200, 8200, 2000, 300, 0, 0, 2);

	

	//App->audio->PlayMusic("worms/Audio/Thomas_the_Dank_Engine_SFM_Music_Video-lzmWzXLPa6I.ogg");
	//App->audio->PlayMusic("worms/Audio/toby-fox-UNDERTALE-Soundtrack-43-Temmie-Village.ogg");
	App->audio->PlayMusic("worms/Audio/MadWorld-GaryJules.ogg");

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
	
	App->physics->Draw();

	return UPDATE_CONTINUE;
}