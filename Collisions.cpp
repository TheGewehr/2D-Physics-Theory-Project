#include "Collisions.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "Collider.h"
#include "Pisobody.h"
#include "Globals.h"
#include "SDL/include/SDL_Scancode.h"
#include "iostream"

Collisions::Collisions(Application* app, bool start_enabled) : Module(app, start_enabled)
{

	//name.Create("collisions");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[Collider::Type::WALL][Collider::Type::WALL] = false;
	matrix[Collider::Type::WALL][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::WALL][Collider::Type::PLAT] = false;
	
	matrix[Collider::Type::WALL][Collider::Type::CAM] = false;
	matrix[Collider::Type::WALL][Collider::Type::WIN] = false;
	matrix[Collider::Type::WALL][Collider::Type::LOSE] = false;
	matrix[Collider::Type::WALL][Collider::Type::ENEMY] = true;


	matrix[Collider::Type::PLAYER][Collider::Type::WALL] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAT] = true;
	
	matrix[Collider::Type::PLAYER][Collider::Type::CAM] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::WIN] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::LOSE] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY] = true;


	matrix[Collider::Type::PLAT][Collider::Type::WALL] = false;
	matrix[Collider::Type::PLAT][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::PLAT][Collider::Type::PLAT] = false;
	
	matrix[Collider::Type::PLAT][Collider::Type::CAM] = false;
	matrix[Collider::Type::PLAT][Collider::Type::WIN] = false;
	matrix[Collider::Type::PLAT][Collider::Type::LOSE] = false;
	matrix[Collider::Type::PLAT][Collider::Type::ENEMY] = true;

	

	matrix[Collider::Type::CAM][Collider::Type::WALL] = false;
	matrix[Collider::Type::CAM][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::CAM][Collider::Type::PLAT] = false;
	
	matrix[Collider::Type::CAM][Collider::Type::CAM] = false;
	matrix[Collider::Type::CAM][Collider::Type::WIN] = false;
	matrix[Collider::Type::CAM][Collider::Type::LOSE] = false;
	matrix[Collider::Type::CAM][Collider::Type::ENEMY] = false;

	matrix[Collider::Type::WIN][Collider::Type::WALL] = false;
	matrix[Collider::Type::WIN][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::WIN][Collider::Type::PLAT] = false;
	
	matrix[Collider::Type::WIN][Collider::Type::CAM] = false;
	matrix[Collider::Type::WIN][Collider::Type::WIN] = false;
	matrix[Collider::Type::WIN][Collider::Type::LOSE] = false;
	matrix[Collider::Type::WIN][Collider::Type::ENEMY] = false;

	matrix[Collider::Type::LOSE][Collider::Type::WALL] = false;
	matrix[Collider::Type::LOSE][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::LOSE][Collider::Type::PLAT] = false;
	
	matrix[Collider::Type::LOSE][Collider::Type::CAM] = false;
	matrix[Collider::Type::LOSE][Collider::Type::WIN] = false;
	matrix[Collider::Type::LOSE][Collider::Type::LOSE] = false;
	matrix[Collider::Type::LOSE][Collider::Type::ENEMY] = false;

	matrix[Collider::Type::ENEMY][Collider::Type::WALL] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::PLAT] = true;
	
	matrix[Collider::Type::ENEMY][Collider::Type::CAM] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::WIN] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::LOSE] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY] = true;;
}

// Destructor
Collisions::~Collisions()
{

}

update_status Collisions::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->pendingToDelete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (matrix[c1->type][c2->type] && c1->Intersects(c2->rect) && (c2 != nullptr) && c1 != nullptr)
			{
				for (uint i = 0; i < MAX_LISTENERS; ++i) {}
				//	if (c1->listeners[i] != nullptr) c1->listeners[i]->OnCollision(c1, c2);
					for (uint i = 0; i < MAX_LISTENERS; ++i) {}
				//	if (c2->listeners[i] != nullptr) c2->listeners[i]->OnCollision(c2, c1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

update_status Collisions::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_F9) == KEY_DOWN)
	{
		debug = !debug;

	}
	return UPDATE_CONTINUE;
}

update_status Collisions::PostUpdate()
{
	if (debug)
		DebugDraw();

	return UPDATE_CONTINUE;
}

void Collisions::DebugDraw()
{
	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case Collider::Type::NONE: // white
			App->renderer->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case Collider::Type::WALL: // blue
			App->renderer->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case Collider::Type::PLAYER: // green
			App->renderer->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case Collider::Type::PLAT: // red
			App->renderer->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::CAM: // yellow
			App->renderer->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case Collider::Type::WIN: // white
			App->renderer->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case Collider::Type::LOSE: // turquoise
			App->renderer->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::ENEMY: // light purple
			App->renderer->DrawQuad(colliders[i]->rect, 200, 150, 255, alpha);
			break;
		}

	}

}

// Called before quitting
bool Collisions::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

void Collisions::OnCollision(PhysBody* c1, PhysBody* c2)
{
}

//void Collisions::OnCollision(Collider* c1, Collider* c2) // adaptar a physbody?
//{
//}

Collider* Collisions::AddCollider(SDL_Rect rect, Collider::Type type, PhysBody* point_, Module* listener)
{
	Collider* ret = nullptr;

	if (point_ == nullptr) {




		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (colliders[i] == nullptr)
			{
				ret = colliders[i] = new Collider(rect, type, listener);
				break;
			}
		}
	}
	else
	{


		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (colliders[i] == nullptr)
			{
				ret = colliders[i] = new Collider(rect, type, point_, listener);
				break;
			}
		}
	}

	return ret;
}

void Collisions::RemoveCollider(Collider* collider)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == collider)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}
}

void Collisions::RemoveColliderType(Collider::Type type)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != NULL)
		{
			if (colliders[i]->type == type)
			{
				delete colliders[i];
				colliders[i] = nullptr;
			}
		}
	}
}