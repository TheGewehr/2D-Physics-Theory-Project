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

void Box::AddKinematicBox(int x, int y, int width, int height, int rotation, Module* lis)
{
	Box* b = new Box;

	b->SetDimensions(width, height);
	b->SetType(kinematicBody);
	b->shouldCollide = true;
	b->SetWorldPosition(x, y);
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

}

int Box::GetWidth()
{
	return width;
}

int Box::GetHeight()
{
	return	height;
}
