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
	 kinematicBody,
	 dynamicBody 

};

// Como voy a medir las distancias?


class Physics : public Module
{
public:
	
	
	Physics(Application* app, bool start_enabled = true) {};

	~Physics();

	

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	bool GetDebug();
	void SetDebug(bool d);
	p2List<PhysBody*> GetWorld();


private:

	bool debug;

	p2List<PhysBody*> World;


};

class PhysBody 
{
public:
	PhysBody() : listener(nullptr) //, body(NULL)
	{}

	~PhysBody()
	{}

	float GetRotation() const;

	virtual int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;
	int GetId() const;
	int GetPositionX() const;
	int GetPositionY() const;
	Vector2D<int> GetPositionVector() const;
	Module* GetListener() const;
	void SetListener(Module* lis);
	ObjType GetType() const;
	void SetType(ObjType type);
	void SetWorldPosition(int x, int y);

	void PreUpdate() {

	}
	void Update() {

	}
	void PostUpdate() {

	}


	bool pendingToDelete = false;

private:

	int id;
	Vector2D<int> worldPosition; // Pixels
	ObjType objectType;

	Module* listener;
};

