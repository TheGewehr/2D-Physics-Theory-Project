#ifndef __PHYSBODYCONTROLLER_H__
#define __PHYSBODYCONTROLLER_H__

#define MAX_ENTITIES 20

#include "Module.h"
#include "PhysBody.h"
#include "SDL/include/SDL.h"

class PyhsBodyController : public Module
{
public:
	// Constructor

	PyhsBodyController(Application* app, bool start_enabled = true);

	// Destructor
	virtual ~PyhsBodyController();

	update_status PreUpdate();

	update_status Update(float dt);

	update_status PostUpdate();

	bool CleanUp();

	PhysBody* AddPhysBody(int x, int y, int w, int h, int enemy);

	void DebugDraw();

	bool debug;

	// All existing colliders in the scene
	PhysBody* Enemies[MAX_ENTITIES] = { nullptr };

};

#endif // __MODULE_ENEMYCONTROLLER_H__


