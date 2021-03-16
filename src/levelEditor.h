#pragma once
#include "level.h"
#include "scene.h"

struct LevelEditor : public Scene
{

	// Editor data.
    PLVL lvl;

	// To implement.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void DrawImGui();
	void Update();
	void Cleanup();
	
};
