/*
Main contributors to this file: Nolan Y.

Bug fixers: Gota7, bbomb64, SkilLP
*/

#include <raylib.h>
#include "scene.h"
#include "titleScreen.h"
#include "gameplay.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

TitleScreen titleScreen;
Gameplay gameplay;

// Main method.
int main(void) {

    // Initalize the game window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mario vs Luigi - Title Screen");
    SetTargetFPS(60);
    InitAudioDevice();
    SetMasterVolume(100);

    // Set the initial scene.
    Scene::LoadScene("TitleScreen", &titleScreen);
    Scene::LoadScene("Gameplay", &gameplay);
    Scene::ChangeScene("TitleScreen");

    // Main game loop
    while (!WindowShouldClose())
    {
        
        // Do update.
        UpdateCamera(&Scene::GetCamera());
        Scene::DoUpdate();

        // Draw everything.
        BeginDrawing();
            ClearBackground(BLACK);
            Scene::DoDrawBackground2D();
            BeginMode3D(Scene::GetCamera());
                Scene::DoDraw3D();
            EndMode3D();
            Scene::DoDrawForeground2D();
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();   // Close the Audio Device
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}