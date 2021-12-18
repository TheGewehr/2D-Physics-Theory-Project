#include "Physics.h"
#include "Box.h"
//#include "Application.h"
//#include "Module.h"
//#include "ModuleInput.h"

// PhysBody source code



// Physics source code

Physics::~Physics()
{
}

bool Physics::Start()
{
	LOG(" Starting the Physics Engyne! ");

	return true;
}

update_status Physics::PreUpdate()
{
	p2List_item<PhysBody*>* node = World.getFirst();
	while (node->next != NULL)
	{
		node->data->PreUpdate();
	}

	return UPDATE_CONTINUE;
}

update_status Physics::Update(float dt)
{
	p2List_item<PhysBody*> *node = World.getFirst();
	while(node->next != NULL)
	{
		node->data->Update(dt);
	}

	return UPDATE_CONTINUE;
}

update_status Physics::PostUpdate()
{

	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
	{
		if (debug)
		{
			debug = false;
		}
		else
		{
			debug = true;
		}
	}
		
	p2List_item<PhysBody*>* node = World.getFirst();
	while (node->next != NULL)
	{
		node->data->PostUpdate();
	}
	
	if (!debug)
	{
		return UPDATE_CONTINUE;
	}
	else
	{
		p2List_item<PhysBody*>* node = World.getFirst();
		while (node->next != NULL)
		{
			node->data->DebugDraw();
		}
	}

	return UPDATE_CONTINUE;
}

bool Physics::CleanUp()
{
	LOG(" Stopping the Physics Engyne! ");
	//delete(&World);
	return true;
}

bool Physics::GetDebug()
{
	return debug;
}

void Physics::SetDebug(bool d)
{
	debug = d;
}

p2List<PhysBody*> Physics::GetWorld()
{
	return World;
}

void Physics::AddBoxToWorld(int x, int y, int w, int h)
{
	Box box(x, y, w, h);
	World.add(&box);
}

