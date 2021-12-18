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
	
	
	Physics(Application* app, bool start_enabled = true);

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

