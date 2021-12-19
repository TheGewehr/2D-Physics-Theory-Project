#pragma once
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Vector2D.h"
#include "p2Point.h"
#include "ModuleInput.h"

class Box;

//struct ObjType
//{
//	int b2_staticBody = -1;
//	int b2_kinematicBody = 1;
//	int b2_dynamicBody = 0;
//
//};



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
	update_status Draw();

	bool CleanUp();
	bool GetDebug();
	void SetDebug(bool d);
	p2List<PhysBody*> GetWorld();

	Box* AddBoxToWorld(int x, int y, int w, int h, float mass_, float rc_, int type, int type02);

	void OnCollision(Collider* body1, Collider* body2);

	

private:

	bool debug;
	

	p2List<PhysBody*> World;



};

