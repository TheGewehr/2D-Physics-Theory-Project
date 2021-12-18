#pragma once
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Vector2D.h"
#include "p2Point.h"
#include "ModuleInput.h"

#include "Physics.h"


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



		p2List_item<PhysBody*>* node = App->physics->GetWorld().getFirst();

		while (node->next != NULL)
		{
			if (node->data->objectType == dynamicBody)
			{

				//	// Compute Gravity force
				float fgx = node->data->mass * 0.0f;
				float fgy = node->data->mass * -9.81f; // Let's assume gravity is constant and downwards
				//
				//// Add gravity force to the total accumulated force of the ball
				node->data->force.x += fgx;
				node->data->force.y += fgy;
			
				
				
				//// Compute Aerodynamic Lift & Drag forces
				//double speed = ball.speed(ball.vx - atmosphere.windx, ball.vy - atmosphere.windy);
				float speed = node->data->velocity.x  + node->data->velocity.y; // There is no wind
				//double fdrag = 0.5 * atmosphere.density * speed * speed * ball.surface * ball.cd;
				float fdrag = 0.5f * 1.2041f * speed * speed * App->PixelToMeter(node->data->GetHeight()) * node->data->cd;
				//double flift = 0.5 * atmosphere.density * speed * speed * ball.surface * ball.cl;
				float flift = 0.5 * 1.2041f * speed * speed * App->PixelToMeter(node->data->GetWidth()) * node->data->cl;
				//double fdx = -fdrag; // Let's assume Drag is aligned with x-axis (in your game, generalize this)
				float fdx = -fdrag; // Let's assume Drag is aligned with x-axis (in your game, generalize this)
				float fdy = flift; // Let's assume Lift is perpendicular with x-axis (in your game, generalize this)
				//
				//// Add aerodynamics force to the total accumulated force of the ball
				node->data->force.x += fdx;
				node->data->force.y += fdy;
				//


				node->data->acceleration.x = node->data->force.x / node->data->mass;
				node->data->acceleration.y = node->data->force.y / node->data->mass;






				//// Step #3: Integrate --> from accel to new velocity & new position. 
				//// We will use the 2nd order "Velocity Verlet" method for integration.
				//// You can also move this code into a subroutine: integrator_velocity_verlet(ball, dt);
				node->data->position.x += node->data->velocity.x * dt + 0.5f * node->data->acceleration.x * dt * dt;
				node->data->position.y += node->data->velocity.y * dt + 0.5f * node->data->acceleration.y * dt * dt;
				node->data->velocity.x += node->data->acceleration.x * dt;
				node->data->velocity.y += node->data->acceleration.y * dt;
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
			}
			else if (node->data->objectType == staticBody)
			{

			}
			else
			{
				LOG(" Type of object error");
			}
		}


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

