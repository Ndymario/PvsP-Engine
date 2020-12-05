/*
Main contributors to this file: Nolan Y.

Bug fixers: Gota7, bbomb64, SkilLP
*/
#include <main.h>

// Main method.
int main(void) {

    // Initalize the game window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mario vs Luigi - Title Screen");
    SetTargetFPS(60);
    InitAudioDevice();
    SetMasterVolume(100);

    // Set the initial scene.
    Scene::ChangeScene(&TitleScreenScene);

    // Main game loop
    while (!WindowShouldClose())
    {
        
        // Do update.
        Scene::DoUpdate();

        // Draw everything.
        BeginDrawing();
            ClearBackground(BLACK);
            Scene::DoDrawBackground2D();
            BeginMode3D(MainCamera);
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