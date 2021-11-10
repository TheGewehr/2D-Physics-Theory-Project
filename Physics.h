#pragma once
#include "module.h"
#include "Globals.h"

class PhysBody
{
public:
	PhysBody() : listener(nullptr)//, body(NULL)
	{}

	void GetPosition(int& x, int& y) const;
	float GetRotation() const;
	bool Contains(int x, int y) const;
	int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;
	int GetId() const;
	int GetX() const;
	int GetY() const;
	Module* GetListener() const;

private:

	int id;
	int width, height;
	//b2Body* body;

	Module* listener;
};

class Physics : public Module
{
public:
	Physics();
	~Physics();

	Physics(Application* app, bool start_enabled = true);
	~Physics();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

private:

	bool debug;
private:

};

