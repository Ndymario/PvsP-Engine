#pragma once
#include "../scene.h"
#include "../ui.h"

// Character selection screen.
struct CharacterSelectScreen : public Scene
{

    // Shapes.
    Shape P1Podium;
    Shape P2Podium;
    Shape P1ArrowLeft;
    Shape P1ArrowRight;
    Shape P2ArrowLeft;
    Shape P2ArrowRight;

    // Functions.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();

};