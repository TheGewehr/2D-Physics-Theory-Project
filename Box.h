#pragma once

#include "module.h"
#include "Physics.h"
#include "pisobody.h"
#include "Application.h"


class Box : public PhysBody
{
public:

	Box(int x, int y, int w, int h) : PhysBody(x, y, w, h)
	{
		width = w;
		height = h;

		localPosition.x = x;
		localPosition.y = y;

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
		cl=1; // Lift coefficient
		cd=1; // Drag coefficient

		id=-1;
		worldPosition.x = App->MeterToPixel(position.x); // Pixels
		worldPosition.y = App->MeterToPixel(position.y);
		objectType = staticBody;

		listener = nullptr;
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
		cl = 1; // Lift coefficient
		cd = 1; // Drag coefficient

		id = -1;
		worldPosition.x = App->MeterToPixel(position.x); // Pixels
		worldPosition.y = App->MeterToPixel(position.y);
		objectType = staticBody;

		listener = nullptr;
	};

	~Box() {};

	int GetWidth()const;
	int GetHeight()const;
    void SetDimensions(int x, int y);
	void AddStaticBox(int x,int y, int width, int height, int rotation, Module* lis);
	void AddKinematicBox(int x, int y, int width, int height, int rotation, Module* lis);
	void AddDynamicBox(int x, int y, int width, int height, int rotation, Module* lis);
	void DebugDraw();
	int GetWidth();
	int GetHeight();

	update_status PreUpdate() override{

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

	update_status Update(float dt) override {

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
				//float fgx = node->data.mass * 0.0;
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

	update_status PostUpdate() override {
		return UPDATE_CONTINUE;
	}

private:

	int width, height; //Pixels
	bool shouldCollide;


	Vector2D<int> localPosition;


	Vector2D<int> point01, point02, point03, point04; // Pixels
};
