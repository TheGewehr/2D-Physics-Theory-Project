#include "Physics.h"
#include "Application.h"
#include "Module.h"
#include "ModuleInput.h"

// PhysBody source code


float PhysBody::GetRotation() const
{

}


int PhysBody::RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const
{

}

int PhysBody::GetId() const
{
	return id;
}

float PhysBody::GetPositionX() const
{
	return position.x;
}

float PhysBody::GetPositionY() const
{
	return position.y;
}

Vector2D<float> PhysBody::GetPositionVector() const
{
	return position;
}

Module* PhysBody::GetListener() const
{
	return listener;
}

ObjType PhysBody::GetType() const
{
	return objectType;
}

void PhysBody::SetType(ObjType type) const
{
	objectType = type;
}




// Physics source code

Physics::Physics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;
}

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

}

update_status Physics::Update()
{

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
		
	if (!debug)
	{
		return UPDATE_CONTINUE;
	}
	else
	{
		// Debug Draw
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