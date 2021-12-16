#include "ModulePhysbodyController.h"
#include "PhysBody.h"
#include "Box.h"



update_status PyhsBodyController::PreUpdate()
{
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


update_status PyhsBodyController::Update()
{
	for (uint i = 0; i < MAX_ENTITIES; ++i)
	{
		// skip empty colliders
		if (Enemies[i] == nullptr)
			continue;

		Enemies[i]->Update();
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