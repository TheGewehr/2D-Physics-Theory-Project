#pragma once

#include "module.h"
#include "Physics.h"
#include "pisobody.h"
#include "Application.h"
#include "Collider.h"
#include "Collisions.h"

class Box : public PhysBody
{
public:

	Box(int x, int y, int w, int h, int type) : PhysBody(x, y, w, h)
	{

		width = w;
		height = h;

		localPosition.x = 0;
		localPosition.y = 0;

		point01.x = x;
		point01.y = y;
		point02.x = x + w;
		point02.y = y;
		point03.x = x;
		point03.y = y - h;
		point04.x = x + w;
		point04.y = y - h;

		shouldCollide = true;

		// Position
	// You could also use an array/vector

		position.x = x;
		position.y = y;
		// Velocity

		velocity.x = 0;

		velocity.y = 0;
		// Acceleration

		acceleration.x = 0;
		acceleration.y = 0;
		// Force (total) applied to the ball

		force.x = 0;
		force.y = 0;
		// Mass
		mass = 1;

		// Aerodynamics stuff
		surface=1; // Effective wet surface
		cl = 1; // Lift coefficient
		cd.x = 1.5f; // Drag coefficient
		cd.y = 1.0f;

		id=-1;
		worldPosition.x = App->MeterToPixel(position.x); // Pixels
		worldPosition.y = App->MeterToPixel(position.y);
		if (type == 1)
		{
			objectType = dynamicBody;
		}
		else if (type == 2)
		{
			objectType = staticBody;
		}
		

		listener = nullptr;

		// HITBOX
		Start();
	}

	Box() : PhysBody()
	{
		width = 1;
		height = 1;

		localPosition.x = 0;
		localPosition.y = 0;

		shouldCollide = true;

		// Position
// You could also use an array/vector

		position.x = 0;
		position.y = 0;
		// Velocity

		velocity.x = 0;

		velocity.y = 0;
		// Acceleration

		acceleration.x = 0;
		acceleration.y = 0;
		// Force (total) applied to the ball

		force.x = 0;
		force.y = 0;
		// Mass
		mass = 1;

		// Aerodynamics stuff
		surface = 1; // Effective wet surface
		cl = 0.5; // Lift coefficient
		cd.x = 1;
		cd.y = 0.5; // Drag coefficient

		id = -1;
		worldPosition.x = App->MeterToPixel(position.x); // Pixels
		worldPosition.y = App->MeterToPixel(position.y);
		objectType = staticBody;

		listener = nullptr;
	
	};

	~Box() {};
	bool Start();
	int GetWidth()const;
	int GetHeight()const;
    void SetDimensions(int x, int y);
	void AddStaticBox(int x,int y, int width, int height, int rotation, Module* lis);
	void AddKinematicBox(int x, int y, int width, int height, int rotation, Module* lis);
	void AddDynamicBox(int x, int y, int width, int height, int rotation, Module* lis);
	void DebugDraw();
	int GetWidth();
	int GetHeight();

	update_status PreUpdate();

	update_status Update(float dt);

	update_status PostUpdate();

private:

	int width, height; //Pixels
	bool shouldCollide;

	Collider* hitbox;

	Vector2D<int> localPosition;
	Vector2D<float> position;
	// Velocity

	Vector2D<float> velocity;
	// Acceleration

	Vector2D<float> acceleration;
	// Force (total) applied to the ball

	Vector2D<float> force;
	// Mass
	float mass;

	// Aerodynamics stuff
	float surface; // Effective wet surface
	float cl; // Lift coefficient
	Vector2D<float> cd; // Drag coefficient

	int id;
	Vector2D<int> worldPosition; // Pixels

	Vector2D<int> point01, point02, point03, point04; // Pixels
};
