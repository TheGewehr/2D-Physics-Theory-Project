#include "Box.h"
#include "Globals.h"
#include "Application.h"
#include "Physics.h"

int Box::GetWidth()const // In pixels
{
	return width;
}

int Box::GetHeight()const // In pixels
{
	return height;
}

void Box::SetDimensions(int x, int y) // In pixels
{
	width = x;
	height = y;

	Vector2D<int> f;

	f.x = (-0.5 * width);
	f.y = (-0.5 * height);

	// Intern rounding is made to fit it in pixels

	point01 = localPosition.operator+(f);

	f.x = (0.5 * width);
	f.y = (-0.5 * height);

	point02 = localPosition.operator+(f);

	f.x = (-0.5 * width);
	f.y = (0.5 * height);

	point03 = localPosition.operator+(f);

	f.x = (0.5 * width);
	f.y = (0.5 * height);

	point03 = localPosition.operator+(f);
}

void Box::AddStaticBox(int x, int y, int width, int height, int rotation, Module* lis)
{
	Box* b = new Box;

	b->SetDimensions(width, height);
	b->SetType(staticBody);
	b->shouldCollide = true;
	b->SetWorldPosition(x,y);
	// Apply rotation to b
	b->SetListener(lis);

	delete b;
}



void Box::AddDynamicBox(int x, int y, int width, int height, int rotation, Module* lis)
{
	Box* b = new Box;

	b->SetDimensions(width, height);
	b->SetType(dynamicBody);
	b->shouldCollide = true;
	b->SetWorldPosition(x, y);
	// Apply rotation to b
	b->SetListener(lis);

	delete b;
}

void Box::DebugDraw()
{
	//App->renderer->DrawQuad({App->});

}

int Box::GetWidth()
{
	return width;
}

int Box::GetHeight()
{
	return	height;
}

update_status Box::PreUpdate()
{
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
	force.x = 0.0f;
	force.y = 0.0f;

	return UPDATE_CONTINUE;
}

update_status Box::Update(float dt)
{

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


	// ESTO YA ES ITERATIVO, SSOLO IMPLEMENTAR PARA UNA CAJA YA QUE ESTA FUNCION SWE LLAMA PARA CADA CAJA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	
		if (objectType == dynamicBody)
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
		else if (objectType == staticBody)
		{

		}
		else
		{
			LOG(" Type of object error");
		}



	return UPDATE_CONTINUE;
}

update_status Box::PostUpdate()
{
	App->renderer->DrawQuad({ (int)position.x, (int)position.y, width, height }, 0, 255, 0, 255);
	return UPDATE_CONTINUE;
}
