#ifndef __COLLISIONS_H__
#define __COLLISIONS_H__

#define MAX_COLLIDERS 300

#include "Module.h"
#include "Application.h"
//#include "Enemy.h"
#include "Collider.h"

class Collisions : public Module
{
public:
	// Constructor
	// Fills all collision matrix data
	Collisions(Application* app, bool start_enabled = true);

	// Destructor
	~Collisions();

	// Called at the beginning of the application loop
	// Removes all colliders pending to delete
	// Checks for new collisions and calls its listeners
	update_status PreUpdate() override;

	// Called at the middle of the application loop
	// Switches the debug mode on/off
	update_status Update(float dt) override;

	// Called at the end of the application loop
	// Draw all colliders (if debug mode is enabled)
	update_status PostUpdate() override;

	// Removes all existing colliders
	bool CleanUp() override;

	void OnCollision(Collider* body1, Collider* body2) override; // adaptar la definicion a physbody o añadir un collider a box?

	// Adds a new collider to the list
	Collider* AddCollider(SDL_Rect rect, Collider::Type type, PhysBody* point_ = nullptr, Module* listener = nullptr);

	// Removes the collider memory and removes it from the colliders array
	void RemoveCollider(Collider* collider);

	void RemoveColliderType(Collider::Type type);

	// Draws all existing colliders with some transparency
	void DebugDraw();

	// All existing colliders in the scene
	Collider* colliders[MAX_COLLIDERS] = { nullptr };

	// The collision matrix. Defines the interaction for two collider types
	// If set two false, collider 1 will ignore collider 2
	bool matrix[Collider::Type::MAX][Collider::Type::MAX];

	// Simple debugging flag to draw all colliders
	bool debug = false;
};

#endif // __MODULE_COLLISIONS_H__
