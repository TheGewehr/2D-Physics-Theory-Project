#pragma once

#include "p2List.h"
#include "Globals.h"
#include "Module.h"
//#include "Dummy.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "Physics.h"
#include "ModuleSceneIntro.h"

class Physics;

class Application
{
public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModulePlayer* player;
	ModuleSceneIntro* scene_intro;
	Physics* physics;

private:

	p2List<Module*> list_modules;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();


	int MeterToPixel(float meter)
	{
		return (int)(meter * MeterToPixelFUIM);
	}

	float PixelToMeter(int pixel)
	{
		return (float)(pixel * PixelToMeterFUIM);
	}

private:

	int start;

	void AddModule(Module* mod);
};