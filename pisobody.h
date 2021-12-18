#pragma once
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Vector2D.h"
#include "p2Point.h"
#include "ModuleInput.h"

#include "Physics.h"


class PhysBody
{
public:
	//PhysBody() : listener(nullptr) //, body(NULL)
	//{}

	PhysBody(Application* app, bool start_enabled = true);
	PhysBody(int x, int y, int w, int h);
	PhysBody();
	~PhysBody()
	{}

	

	bool start_enabled;
	float GetRotation() const;

	virtual int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;
	int GetId() const;

	int GetPositionX() const;
	int GetPositionY() const;

	virtual void DebugDraw() {
	};

	virtual int GetWidth() {
		return int();
	};

	virtual int GetHeight() {
		return int();
	};

	Vector2D<int> GetPositionVector() const;
	Module* GetListener() const;
	void SetListener(Module* lis);
	ObjType GetType() const;
	void SetType(ObjType type);
	void SetWorldPosition(int x, int y);

	virtual update_status PreUpdate() {
		return UPDATE_CONTINUE;
	}

	virtual update_status Update(float dt) {
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate() {
		return UPDATE_CONTINUE;
	}

	bool pendingToDelete = false;

public:

	// Position
	// You could also use an array/vector

	Vector2D<float> position;
	// Velocity

	Vector2D<float> velocity;
	// Acceleration

	Vector2D<float> acceleration;
	// Force (total) applied to the ball

	Vector2D<float> force;
	// Mass
	float mass;

	// Aerodynamics stuff
	float surface; // Effective wet surface
	float cl; // Lift coefficient
	float cd; // Drag coefficient

	int id;
	Vector2D<int> worldPosition; // Pixels
	ObjType objectType;

	Module* listener;
};

