#include "Globals.h"
#include "Application.h"
#include "Enemy.h"
#include "Collisions.h"
#include "ModuleInput.h"
#include "Physics.h"
//#include "PhysBody.h"

Enemy::Enemy(Application* app, bool start_enabled) : Module(app, start_enabled)
{


}

Enemy::~Enemy()
{}

// Load assets
bool Enemy::Start()
{
	LOG("Loading player");


	lifes = 3;
	//graphic = App->textures->Load("worms/weapons/Grenade.png");


	enemyBox;

	spawnBullet_fx;



	App->physics->AddBoxToWorld(5000, 000, 100, 100, 1.0, 0.4, 1);

	return true;


}

void Enemy::SetEnemyLifes(int l)
{
	lifes = l;
}

// Unload assets
bool Enemy::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status Enemy::Update(float dt)
{
	return UPDATE_CONTINUE;
}

update_status Enemy::PostUpdate()
{
	//App->renderer->Blit(graphic,);
	return UPDATE_CONTINUE;
}