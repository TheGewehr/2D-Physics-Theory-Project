#include "Physics.h"
//#include "Application.h"
//#include "Module.h"
//#include "ModuleInput.h"

// PhysBody source code


float PhysBody::GetRotation() const
{
	return float();
}


int PhysBody::RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const
{
	return int();
}

int PhysBody::GetId() const
{
	return id;
}

int PhysBody::GetPositionX() const
{
	return worldPosition.x;
}

int PhysBody::GetPositionY() const
{
	return worldPosition.y;
}

Vector2D<int> PhysBody::GetPositionVector() const
{
	return worldPosition;
}

Module* PhysBody::GetListener() const
{
	return listener;
}

ObjType PhysBody::GetType() const
{
	return objectType;
}

void PhysBody::SetType(ObjType type)
{
	objectType = type;
}

void PhysBody::SetWorldPosition(int x, int y)
{
	Vector2D<int>* v = new Vector2D<int>;

	v->x = x;
	v->y = y;

	worldPosition = *v;

	delete v;
	
}

void PhysBody::SetListener(Module* lis)
{
	listener = lis;
}


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

update_status Physics::Update()
{
	p2List_item<PhysBody*> *node = World.getFirst();
	while(node->next != NULL)
	{
		node->data->Update();
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

