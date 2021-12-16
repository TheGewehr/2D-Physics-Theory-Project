#pragma once

#include "module.h"
#include "Physics.h"

class Box : public PhysBody
{
public:

	Box(int x, int y, int w, int h)
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
	}

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