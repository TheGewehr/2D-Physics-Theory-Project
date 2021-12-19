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

	point04 = localPosition.operator+(f);
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
	verletIntegrator = true;

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
	verletIntegrator = true;

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

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		if (verletIntegrator == false)
		{
			verletIntegrator = true;
		}
		else
		{
			verletIntegrator = false;
		}
	}

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

	if (objectType == dynamicBody)
	{
		//	// Compute Gravity force
		float fgx = mass * 0.0f;
		float fgy = mass * 0.00000000001f; // Let's assume gravity is constant and downwards BIG FUIM!
		//
		//// Add gravity force to the total accumulated force of the ball
		force.x += fgx;
		force.y += fgy;


		//// Compute Aerodynamic Lift & Drag forces
		//double speed = ball.speed(ball.vx - atmosphere.windx, ball.vy - atmosphere.windy);
		Vector2D<float> speed;
		speed.x = velocity.x; // There is no wind
		speed.y = velocity.y;
		//double fdrag = 0.5 * atmosphere.density * speed * speed * ball.surface * ball.cd;
		Vector2D<float> fdrag;
		fdrag.x = 0.5f * 1.2041f * speed.x * speed.x * App->PixelToMeter(GetWidth()) * cd.x;
		fdrag.y = 0.5f * 1.2041f * speed.y * speed.y * App->PixelToMeter(GetHeight()) * cd.y;
		//double flift = 0.5 * atmosphere.density * speed * speed * ball.surface * ball.cl;
		float flift = 0.5 * 1.2041f * speed.y * speed.y * App->PixelToMeter(GetWidth()) * cl;
		//double fdx = -fdrag; // Let's assume Drag is aligned with x-axis (in your game, generalize this)
		float fdx = -fdrag.x; // Let's assume Drag is aligned with x-axis (in your game, generalize this)
		float fdy = flift -fdrag.y; // Let's assume Lift is perpendicular with x-axis (in your game, generalize this)
		//
		//// Add aerodynamics force to the total accumulated force of the ball
		force.x += fdx;
		force.y += fdy;
		//


		acceleration.x = force.x / mass;
		acceleration.y = force.y / mass;


		//verletIntegrator = false;
		//// Step #3: Integrate --> from accel to new velocity & new position. 
		//// We will use the 2nd order "Velocity Verlet" method for integration.
		//// You can also move this code into a subroutine: integrator_velocity_verlet(ball, dt);
		if (verletIntegrator == true)
		{
			position.x += velocity.x * dt + 0.5f * acceleration.x * dt * dt;
			position.y += velocity.y * dt + 0.5f * acceleration.y * dt * dt;
			velocity.x += acceleration.x * dt;
			velocity.y += acceleration.y * dt;
		}
		else
		{
			position.x += (velocity.x * dt);
			position.y += (velocity.y * dt);

			velocity.x += acceleration.x;
			velocity.y += acceleration.y ;
		}
		
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
		worldPosition.x = App->MeterToPixel(position.x);
		worldPosition.y = App->MeterToPixel(position.y);
	}
	else if (objectType == staticBody)
	{

	}
	else
	{
		LOG(" Type of object error");
	}
	// Setting hitbox to real position
	if (hitbox != NULL)
	{
		hitbox->SetPos((int)(worldPosition.x - width * 0.5), (int)(worldPosition.y - height * 0.5));
	}

	return UPDATE_CONTINUE;
}

update_status Box::PostUpdate()
{
	App->renderer->DrawQuad({ (int)(worldPosition.x - width * 0.5), (int)(worldPosition.y - height * 0.5), width, height }, 0, 255, 0, 200);
	return UPDATE_CONTINUE;
}
