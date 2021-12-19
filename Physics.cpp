#include "Physics.h"
#include "Box.h"
//#include "Application.h"
//#include "Module.h"
//#include "ModuleInput.h"

// PhysBody source code



// Physics source code

Physics::Physics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

Physics::~Physics()
{
}

bool Physics::Start()
{
	LOG(" Starting the Physics Engyne! ");

	AddBoxToWorld(800, 100, 100, 100, 1);

	return true;
}

update_status Physics::PreUpdate()
{
	p2List_item<PhysBody*>* node = World.getFirst();
	if (node != NULL)
	{
		while (node != NULL)
		{
			node->data->PreUpdate();
			node = node->next;
		}
	}
	return UPDATE_CONTINUE;
}

update_status Physics::Update(float dt)
{
	p2List_item<PhysBody*> *node = World.getFirst();
	if (node != nullptr)
	{
		while (node != NULL)
		{
			node->data->Update(dt);
			node = node->next;
		}
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
	
	if (node != nullptr)
	{
		
		while (node != NULL)
		{
			node->data->PostUpdate();
			node = node->next;
		}
	}

	if (!debug)
	{
		return UPDATE_CONTINUE;
	}
	else
	{
		p2List_item<PhysBody*>* node = World.getFirst();
		if (node != nullptr)
		{
			while (node->next != NULL)
			{
				node->data->DebugDraw();
			}
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

void Physics::AddBoxToWorld(int x, int y, int w, int h, int type)
{

	Box * a = new Box(x, y, w, h, type);
	World.add(a);
}

void Physics::OnCollision(Collider* body1, Collider* body2)
{
	if (body1->point->objectType == staticBody)
	{
		body2->point->velocity.y *= -1;
		body2->point->acceleration.y = 0;
		body2->point->worldPosition.y = body1->point->worldPosition.y + body2->point->GetWidth();
		body2->point->worldPosition.y = 0;
		body2->point->position.y = 0;
	}
	else if (body1->point->objectType == staticBody)
	{
		body1->point->velocity.y *= -1;
		body1->point->acceleration.y = 0;
		body1->point->worldPosition.y = body2->point->worldPosition.y + body1->point->GetWidth();
	}
}

