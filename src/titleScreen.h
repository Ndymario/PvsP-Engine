#pragma once
#include "scene.h"
#include "ui.h"

const float BG_SCROLL_SPEED = 70.0f;

struct TitleScreen : public Scene
{
	Shape BG;
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();
};