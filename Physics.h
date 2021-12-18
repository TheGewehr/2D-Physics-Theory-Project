#pragma once
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Vector2D.h"
#include "p2Point.h"
#include "ModuleInput.h"

//struct ObjType
//{
//	int b2_staticBody = -1;
//	int b2_kinematicBody = 1;
//	int b2_dynamicBody = 0;
//
//};

enum ObjType
{
	 staticBody = 0,
	 
	 dynamicBody = 1

};

// Como voy a medir las distancias?


class Physics : public Module
{
public:
	
	
	Physics(Application* app, bool start_enabled = true) {};
	Physics() {};

	~Physics();

	

	bool Start();
	update_status PreUpdate();
	update_status Update(float dt);
	update_status PostUpdate();
	bool CleanUp();
	bool GetDebug();
	void SetDebug(bool d);
	p2List<PhysBody*> GetWorld();

	void AddBoxToWorld(int x, int y, int w, int h);

private:

	bool debug;

	p2List<PhysBody*> World;



};

class PhysBody : public Physics
{
public:
	PhysBody() : listener(nullptr) //, body(NULL)
	{}

	~PhysBody()
	{}

	float GetRotation() const;

	virtual int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;
	int GetId() const;

	int GetPositionX() const;
	int GetPositionY() const;

	virtual void DebugDraw() {
	};

	virtual int GetWidth() {
		return int();
	};

	virtual int GetHeight() {
		return int();
	};

	Vector2D<int> GetPositionVector() const;
	Module* GetListener() const;
	void SetListener(Module* lis);
	ObjType GetType() const;
	void SetType(ObjType type);
	void SetWorldPosition(int x, int y);

	update_status PreUpdate() {

		p2List_item<PhysBody*>* node = App->physics->GetWorld().getFirst();

		while (node->next != NULL)
		{
			node->data->acceleration.x = 0.0f;
			node->data->acceleration.y = 0.0f;
			node->data->force.x = 0.0f;
			node->data->force.y = 0.0f;
		}


		return UPDATE_CONTINUE;
	}

	update_status Update(float dt) {

		//// Step #0: Reset total acceleration and total accumulated force of the ball (clear old values)
		//ball.fx = ball.fy = 0.0;
		//ball.ax = ball.ay = 0.0;
		//
		//// Step #1: Compute forces
		//
		//	// Compute Gravity force
		//double fgx = ball.mass * 0.0;
		//double fgy = ball.mass * -10.0; // Let's assume gravity is constant and downwards
		//
		//// Add gravity force to the total accumulated force of the ball
		//ball.fx += fgx;
		//ball.fy += fgy;
		//
		//// Compute Aerodynamic Lift & Drag forces
		//double speed = ball.speed(ball.vx - atmosphere.windx, ball.vy - atmosphere.windy);
		//double fdrag = 0.5 * atmosphere.density * speed * speed * ball.surface * ball.cd;
		//double flift = 0.5 * atmosphere.density * speed * speed * ball.surface * ball.cl;
		//double fdx = -fdrag; // Let's assume Drag is aligned with x-axis (in your game, generalize this)
		//double fdy = flift; // Let's assume Lift is perpendicular with x-axis (in your game, generalize this)
		//
		//// Add gravity force to the total accumulated force of the ball
		//ball.fx += fdx;
		//ball.fy += fdy;
		//
		//// Other forces
		//// ...

		//// Step #2: 2nd Newton's Law: SUM_Forces = mass * accel --> accel = SUM_Forces / mass
		//ball.ax = ball.fx / ball.mass;
		//ball.ay = ball.fy / ball.mass;
		//
		//// Step #3: Integrate --> from accel to new velocity & new position. 
		//// We will use the 2nd order "Velocity Verlet" method for integration.
		//// You can also move this code into a subroutine: integrator_velocity_verlet(ball, dt);
		//ball.x += ball.vx * dt + 0.5 * ball.ax * dt * dt;
		//ball.y += ball.vy * dt + 0.5 * ball.ay * dt * dt;
		//ball.vx += ball.ax * dt;
		//ball.vy += ball.ay * dt;
		//
		//// Step #4: solve collisions
		//if (ball.y < ground.y)
		//{
		//	// For now, just stop the ball when it reaches the ground.
		//	ball.vx = ball.vy = 0.0;
		//	ball.ax = ball.ay = 0.0;
		//	ball.fx = ball.fy = 0.0;
		//	ball.physics_enabled = false;
		//}
		return UPDATE_CONTINUE;
	}
	update_status PostUpdate() {
		return UPDATE_CONTINUE;
	}


	bool pendingToDelete = false;

public:

	// Position
	// You could also use an array/vector
	
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
	float cd; // Drag coefficient

	int id;
	Vector2D<int> worldPosition; // Pixels
	ObjType objectType;

	Module* listener;
};

