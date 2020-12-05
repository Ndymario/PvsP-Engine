#pragma once
#include "scene.h"
#include "mdl.h"
#include <raylib.h>

struct Gameplay : public Scene
{

	// Player data.
	Mdl playerModel;
	Mdl playerHeadModel;

	// To implement.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();

};

