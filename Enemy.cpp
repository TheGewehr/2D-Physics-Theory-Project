#include "Globals.h"
#include "Application.h"
#include "Enemy.h"
#include "Collisions.h"
#include "ModuleInput.h"
#include "Physics.h"
#include "stdlib.h"
#include "time.h"
#include "Box.h"

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
	//graphic = App->textures->Load("worms/weapons/dorito.png");


	

	spawnBullet_fx;



	enemyBox = App->physics->AddBoxToWorld(14800, 0, 100, 100, 1.0, 0.8, 1, 2);
	srand(time(NULL));

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
	//App->renderer->Blit(graphic, enemyBox->worldPosition.x + enemyBox->point01.x, enemyBox->worldPosition.y + enemyBox->point01.y);
	return UPDATE_CONTINUE;
}