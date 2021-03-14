#pragma once
#include "../screen.h"
#include "../ui.h"
#include "../scene.h"

// Options screen.
struct OptionsScreen : public Scene
{

	// Menu.
	Shape BG;
	Shape Logo;
	Shape AssetsButton;
	Shape InputButton;
	Shape GraphicsButton;
	Shape AudioButton;
	Shape BackButton;

    // Functions.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();

};

// Button functions.
void ClickAssetsButton();
void ClickInputButton();
void ClickGraphicsButton();
void ClickAudioButton();
void ClickBackButton();