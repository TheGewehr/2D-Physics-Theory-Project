#pragma once
#include "Module.h"
#include "Globals.h"
//#include "Application.h"
#include "Vector2D.h"

enum ObjType
{
	b2_staticBody = 0,
	b2_kinematicBody,
	b2_dynamicBody

};

// Como voy a medir las distancias?

class PhysBody
{
public:
	PhysBody() : listener(nullptr) //, body(NULL)
	{}

	~PhysBody()
	{}

	float GetRotation() const;
	
	int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;
	int GetId() const;
	float GetPositionX() const;
	float GetPositionY() const;
	Vector2D<float> GetPositionVector() const;
	Module* GetListener() const;
	ObjType GetType() const;
	void SetType(ObjType type) const;



private:

	int id;
	Vector2D<float> position;
	int width, height;
	ObjType objectType;
	
	Module* listener;
};

class Physics : public Module
{
public:
	
	
	Physics(Application* app, bool start_enabled = true);
	~Physics();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	bool GetDebug();
	void SetDebug(bool d);



private:

	bool debug;

	p2List<PhysBody*> World;


};

