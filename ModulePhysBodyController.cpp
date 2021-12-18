#include "ModulePhysbodyController.h"
#include "PhysBody.h"
#include "Box.h"

PyhsBodyController::PyhsBodyController(Application* app, bool start_enabled)
{

}

PyhsBodyController::~PyhsBodyController()
{
}

update_status PyhsBodyController::PreUpdate()
{

	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		if (Enemies[i] != nullptr && Enemies[i]->pendingToDelete == true)
		{
			delete Enemies[i];
			Enemies[i] = nullptr;
		}
	}
	// Do The preUpdate
	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		// skip empty colliders
		if (Enemies[i] == nullptr)
			continue;

		Enemies[i]->PreUpdate();
	}

	return UPDATE_CONTINUE;
}


update_status PyhsBodyController::Update(float dt)
{
	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		// skip empty colliders
		if (Enemies[i] == nullptr)
			continue;

		Enemies[i]->Update(dt);
	}

	return UPDATE_CONTINUE;
}

update_status PyhsBodyController::PostUpdate()
{
	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		// skip empty colliders
		if (Enemies[i] == nullptr)
			continue;

		Enemies[i]->PostUpdate();

	}
	return UPDATE_CONTINUE;

	if (debug) DebugDraw();
}

bool PyhsBodyController::CleanUp()
{
	//app->coll->RemoveColliderType(Collider::Type::ENEMY);

	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		if (Enemies[i] != nullptr)
		{
			delete Enemies[i];
			Enemies[i] = nullptr;
		}
	}
	return true;
}


PhysBody* PyhsBodyController::AddPhysBody(int x, int y, int w, int h, int enemy)
{
	PhysBody* ret = nullptr;

	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		if (Enemies[i] == nullptr)
		{
			Enemies[i] = new Box(x, y, w, h);
			break;
		}
	}

	return ret;
}

void PyhsBodyController::DebugDraw()
{
	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		// skip empty colliders
		if (Enemies[i] == nullptr)
			continue;
		
		App->renderer->DrawQuad({ Enemies[i]->GetPositionX(), Enemies[i]->GetPositionY(), Enemies[i]->GetHeight(), Enemies[i]->GetWidth() }, 0, 255, 0, 255);

	}
}
