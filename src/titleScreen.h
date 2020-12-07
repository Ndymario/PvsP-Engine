#pragma once
#include "scene.h"
struct TitleScreen : public Scene
{

	// To implement.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();
};
