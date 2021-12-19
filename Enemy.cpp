#include "Globals.h"
#include "Application.h"
#include "Enemy.h"
#include "Collisions.h"
#include "ModuleInput.h"
#include "Physics.h"
#include "stdlib.h"
#include "time.h"

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



	enemyBox = App->physics->AddBoxToWorld(2800, 400, 100, 100, 1.0, 0.8, 1);
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
	enemy_int = rand() % 10;

	if (enemy_int == 1) // MOVE RIGHT
	{
		enemyBox->impulseForce.x = -0.00001;
	}
	else if (enemy_int == 2) //MOVE LEFT
	{
		enemyBox->impulseForce.x = 0.00001;
	}
	else if (enemy_int == 3) // JUMP
	{
		enemyBox->impulseForce.x = 0;
		enemyBox->impulseForce.y = -0.000000000001;
	}
	else if (enemy_int == 4) //SHOOT
	{

	}
	else //DO NOTHING
	{
		enemy->impulseForce.x = 0;
	}
	return UPDATE_CONTINUE;
}

update_status Enemy::PostUpdate()
{
	//App->renderer->Blit(graphic,);
	return UPDATE_CONTINUE;
}