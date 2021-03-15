/*
Main contributors to this file: Nolan Y.

Bug fixers: Gota7, bbomb64, SkilLP
*/

#include <raylib.h>
#include "scene.h"
#include "menu/titleScreen.h"
#include "menu/pvpScreen.h"
#include "gameplay.h"
#include "screen.h"
#include "input.h"
#include "ui.h"
#include "menu/optionsScreen.h"
#include "menu/characterSelectScreen.h"
#include "imgui.h"
//#include "imgui_impl_opengl3.h"
//#include "imgui_impl_raylib.h"
#include "rlImGui/rlImGui.h"

// Main method.
int main(void)
{

	// Initalize the game window
	InitWindow(Screen::GAME_WIDTH, Screen::GAME_HEIGHT, "Player vs Player Engine (development build)");
	Screen::Init();
	SetTargetFPS(60);
	InitAudioDevice();
	SetMasterVolume(100);

    // Some input.
    Input::AddControl("Left", KEY_A, GAMEPAD_BUTTON_LEFT_FACE_LEFT, GAMEPAD_AXIS_LEFT_X, false, 0);
    Input::AddControl("Right", KEY_D, GAMEPAD_BUTTON_LEFT_FACE_RIGHT, GAMEPAD_AXIS_LEFT_X, true, 0);
    Input::AddControl("Run", KEY_LEFT_SHIFT, 0);
    Input::AddControl("Jump", KEY_SPACE, 0);
    Input::gamePadIDs[0] = -1;

    // Scenes that exist.
    TitleScreen titleScreen;
	PvsPScreen pvspScreen;
    Gameplay gameplay;
	OptionsScreen optionsScreen;
	CharacterSelectScreen characterSelectScreen;

	// Set the initial scene.
	Scene::LoadScene("TitleScreen", &titleScreen);
	Scene::LoadScene("OptionsScreen", &optionsScreen);
	Scene::LoadScene("Gameplay", &gameplay);
	Scene::LoadScene("PvsPScreen", &pvspScreen);
	Scene::LoadScene("CharacterSelectScreen", &characterSelectScreen);
	Scene::ChangeScene("TitleScreen");

	// ImGUI.
	SetupRLImGui(true);

	// Main game loop
	while (!WindowShouldClose() && !Screen::quitGame)
	{

		// Do update.
		UpdateCamera(&Scene::GetCamera());
		Scene::DoUpdate();

		// Fullscreen check.
		if (IsKeyPressed(KEY_F4))
		{
			Screen::DoToggleFullscreen();
		}	

		// Init draw.
		BeginDrawing();
		ClearBackground(BLACK);
		
		// Background.
		Scene::DoDrawBackground2D();

		// 3D.
		BeginMode3D(Scene::GetCamera());
		Scene::DoDraw3D();
		EndMode3D();	

		// ImGUI.
		BeginRLImGui();
		ImGui::Begin("Hello World!");
		ImGui::End();
		ImGui::ShowDemoWindow();
		EndRLImGui();

		// Foreground.
		Scene::DoDrawForeground2D();
		DrawFPS(5, 0);

		// End draw.
		EndDrawing();

	}

	// ImGUI.
	ShutdownRLImGui();

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseAudioDevice(); // Close the Audio Device
	CloseWindow();      // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}