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

	AddBoxToWorld(2800, 400, 100, 100, 1.0, 0.8, 1);

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

update_status Physics::Draw()
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

Box* Physics::AddBoxToWorld(int x, int y, int w, int h, float mass_, float rc_, int type)
{
	
	Box* a = new Box(x, y, w, h, mass_, rc_, type);
	World.add(a);
	return a;
	
}

void Physics::OnCollision(Collider* body1, Collider* body2)
{
	// BETTER STYLE
	if (body1->point->objectType == staticBody)
	{
		if (body1->point->position.x - App->PixelToMeter(body1->point->width*0.5) < body2->point->position.x)
		{
			body2->point->velocity.y *= -1 * body2->point->rc;
			body2->point->force.y = 0;
			body2->point->position.y = body1->point->position.y - App->PixelToMeter(body1->point->height * 0.5) - App->PixelToMeter(body2->point->height * 0.5) - 3;
			if (body2->point->velocity.y > -0.00001 && body2->point->velocity.y < 0.00001) body2->point->velocity.y = 0;
		}
		else
		{
			body2->point->velocity.y *= -1 * body2->point->rc;;
			
			body2->point->position.x = body1->point->position.x - App->PixelToMeter(body1->point->width * 0.5) - App->PixelToMeter(body2->point->width * 0.5);
			if (body2->point->velocity.x > -0.00001 && body2->point->velocity.x < 0.00001) body2->point->velocity.x = 0;
		}
	}
	else if (body2->point->objectType == staticBody)
	{
		if (body2->point->position.x - App->PixelToMeter(body2->point->width * 0.5) < body1->point->position.x)
		{
			body1->point->velocity.y *= -1 * body1->point->rc;
			body1->point->force.y *= 0.8;
			body1->point->position.y = body2->point->position.y - App->PixelToMeter(body2->point->height * 0.5) - App->PixelToMeter(body1->point->height * 0.5) - 3;
			if (body1->point->velocity.y > -0.00001 && body1->point->velocity.y < 0.00001) body1->point->velocity.y = 0;
		}
		else
		{
			body1->point->velocity.x *= -1 * body1->point->rc;
			body1->point->force.x *= 0.8;
			body1->point->position.x = body2->point->position.x - App->PixelToMeter(body2->point->width * 0.5) - App->PixelToMeter(body1->point->width * 0.5);
			if (body1->point->velocity.x > -0.00001 && body1->point->velocity.x < 0.00001) body1->point->velocity.x = 0;
		}
	}
	else
	{
		//PERFECT ELASTIC COLITIONS STUPID WAY FUIM
		float aux = 0;
		aux = body1->point->velocity.x;
		body1->point->velocity.x = body2->point->velocity.x;
		body2->point->velocity.x = aux;

		aux = body1->point->velocity.y;
		body1->point->velocity.y = body2->point->velocity.y;
		body2->point->velocity.y = aux;

		if (body2->point->position.x < body1->point->position.x) //&& body1->point->position.y - App->PixelToMeter(body1->point->height * 0.5) < body2->point->position.y)
		{
			body1->point->position.x = body2->point->position.x + App->PixelToMeter(body1->point->width * 0.5) + App->PixelToMeter(body1->point->width * 0.5);
		}
		else if (body2->point->position.y < body1->point->position.y)
		{
			body1->point->position.y = body2->point->position.y + App->PixelToMeter(body1->point->height * 0.5) + App->PixelToMeter(body1->point->height * 0.5);
			body1->point->force.y = 0;
		}
		else //if(body2->point->position.y - App->PixelToMeter(body2->point->height * 0.5) < body1->point->position.y)
		{
			body1->point->position.x = body2->point->position.x - App->PixelToMeter(body1->point->width * 0.5) - App->PixelToMeter(body1->point->width * 0.5);
		}
		//else
		//{
		//	body1->point->position.y = body2->point->position.y - App->PixelToMeter(body1->point->height * 0.5) - App->PixelToMeter(body1->point->height * 0.5)+ 3;
		//}
	}
	
}

//if (body1->point->objectType == staticBody)
//{
//	if (body2->point->velocity.y < 1 && body2->point->velocity.y > -1)
//	{
//		body2->point->velocity.y = 0;
//		body2->point->acceleration.y = 0;
//		body2->point->position.y = body1->point->position.x + App->PixelToMeter(body2->point->GetHeight());
//	}
//	else
//	{
//		body2->point->velocity.y *= -1 * 0.8;
//		body2->point->acceleration.y = 0;
//		body2->point->position.y = body1->point->position.x + App->PixelToMeter(body2->point->GetHeight());
//	}
//}
//else if (body2->point->objectType == staticBody)
//{
//	/*if (body2->point->velocity.y < 0.000000000000000000000000000000005 && body2->point->velocity.y > -0.000000000000000000000000000005)
//	{
//		body1->point->velocity.y = 0;
//		body1->point->acceleration.y = 0;
//		body1->point->worldPosition.y = body2->point->position.x + App->PixelToMeter(body1->point->GetHeight());
//	}
//	else*/
//	{
//		body1->point->force.x = 0;
//		body1->point->force.y = 0;
//		body1->point->velocity.y *= -1 * 0;
//		body1->point->acceleration.y = 0;
//		body1->point->position.y = body2->point->position.x;
//	}

//	// STUPID STYLE
//if (body1->point->objectType == staticBody)
//{
//	if (body2->point->position.x > body1->point->position.x - body2->point->width * 0.5 && body2->point->position.x < body1->point->position.x + body1->point->width * 0.5)
//	{
//		body2->point->velocity.y *= -1 * 0.8;
//		body2->point->force.y = 0;
//
//	}
//}
//else if (body2->point->objectType == staticBody)
//{
//	if (body1->point->position.x > body2->point->position.x - body2->point->width * 0.5 && body1->point->position.x < body2->point->position.x + body2->point->width * 0.5)
//	{
//		body1->point->velocity.y *= -1 * 0.8;
//		body2->point->force.y = 0;
//	}
//}