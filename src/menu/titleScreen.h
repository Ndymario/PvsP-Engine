#pragma once
#include "../scene.h"
#include "../ui.h"

struct TitleScreen : public Scene
{

	// Menu.
	Shape BG;
	Shape Logo;
	Shape PvsPButton;
	Shape MinigamesButton;
	Shape OptionsButton;
	Shape QuitButton;

	// Functions.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();
	
};

// Button functions.
void ClickPvsPButton();
void ClickMinigameButton();
void ClickOptionsButton();
void ClickQuitButton();