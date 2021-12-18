#include "pisobody.h"

PhysBody::PhysBody(Application* app, bool start_enabled)
{
}

PhysBody::PhysBody(int x, int y, int w, int h)
{
}

PhysBody::PhysBody()
{
}

float PhysBody::GetRotation() const
{
	return float();
}


int PhysBody::RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const
{
	return int();
}

int PhysBody::GetId() const
{
	return id;
}

int PhysBody::GetPositionX() const
{
	return worldPosition.x;
}

int PhysBody::GetPositionY() const
{
	return worldPosition.y;
}

Vector2D<int> PhysBody::GetPositionVector() const
{
	return worldPosition;
}

Module* PhysBody::GetListener() const
{
	return listener;
}

ObjType PhysBody::GetType() const
{
	return objectType;
}

void PhysBody::SetType(ObjType type)
{
	objectType = type;
}

void PhysBody::SetWorldPosition(int x, int y)
{
	Vector2D<int>* v = new Vector2D<int>;

	v->x = x;
	v->y = y;

	worldPosition = *v;

	delete v;

}

void PhysBody::SetListener(Module* lis)
{
	listener = lis;
}
