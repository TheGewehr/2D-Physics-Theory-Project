#pragma once

#include "module.h"
#include "Physics.h"

class Box : public PhysBody
{
public:
	Box()
	{
		width = 1;
		height = 1;

		localPosition.x = 0;
		localPosition.y = 0;

		shouldCollide = true;
	};

	~Box() {};

	int GetWidth()const;
	int GetHeight()const;
    void SetDimensions(int x, int y);
	void AddStaticBox(int x,int y, int width, int height, int rotation, Module* lis);
	void AddKinematicBox(int x, int y, int width, int height, int rotation, Module* lis);
	void AddDynamicBox(int x, int y, int width, int height, int rotation, Module* lis);


private:

	int width, height; //Pixels
	bool shouldCollide;

	Vector2D<int> localPosition;


	Vector2D<int> point01, point02, point03, point04;
};