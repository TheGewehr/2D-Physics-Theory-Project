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
#include "ModulePhysbodyController.h"
#include "Timer.h"
#include "PerfTimer.h"

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
	PyhsBodyController* phys_controller;
	Physics* physics;



private:

	p2List<Module*> list_modules;


	PerfTimer* ptimer;
	PerfTimer* frameDuration;

	Timer startupTime;
	Timer frameTime;
	Timer lastSecFrameTime;

	int frameCount = 0;
	int framesPerSecond = 0;
	int lastSecFrameCount = 0;

	float averageFps = 0.0f;
	float dt = 0.0f;



	int maxFrameRate = 0;

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
extern Application* App;