#pragma once
#include "scene.h"
#include "mdl.h"
#include "player.h"
#include <raylib.h>
#include <raymath.h>

struct Gameplay : public Scene
{

	// Player data.
	Mdl marioModel;
	Mdl playerHeadModel;
	Mdl hammerBro;

    // Player
    Player player;

	// To implement.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();
};
