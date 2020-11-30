/*
Contributors to this file: Nolan Y.
*/
#include <stdio.h>
#include <raylib.h>

// Some constants.
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const Vector2 ZERO = { 0, 0 };

int main(void) {

    // Initialization
    //--------------------------------------------------------------------------------------

    // Declare constants for the dimentions of assets
        // Titlescreen:
    const int highlightedPipeWidth = 228;
    const int highlightedPipeHeight = 35;
    const int unhighlightedPipeWidth = 218;
    const int unhighlightedPipeHeight = 35;
    const int numOfButtons = 3;

    // Initalize the game window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mario vs Luigi - Title Screen");

    // Load the Title Screen assets
    Image asset = LoadImage("assets/title/title_screen_assets.png");

    // Define the rectangles for the bounding boxes of the buttons. (Also used for cropping)
    // Y pos of first buttton in the .png is 68
    Rectangle mvslHighlightedBox = { 0, 68, highlightedPipeWidth, highlightedPipeHeight };
    Rectangle mvslUnhighlightedBox = { 0, 68 + highlightedPipeHeight, unhighlightedPipeWidth, unhighlightedPipeHeight };
    Rectangle minigameHighlightedBox = { 0, 68 + (highlightedPipeHeight * 2), highlightedPipeWidth, highlightedPipeHeight };
    Rectangle minigameUnhighlightedBox = { 0, 68 + (highlightedPipeHeight * 3), unhighlightedPipeWidth, unhighlightedPipeHeight };
    Rectangle optionsHighlightedBox = { 0, 68 + (highlightedPipeHeight * 4), highlightedPipeWidth, highlightedPipeHeight };
    Rectangle optionsUnhighlightedBox = { 0, 68 + (highlightedPipeHeight * 5), unhighlightedPipeWidth, unhighlightedPipeHeight };

    // Create Textures for drawing to the screen
    Texture2D titleAsset = LoadTextureFromImage(asset);

    // Declare bools to keep track of what game state we are in
    bool titleScreen = true;
    bool inGame = false;
    bool inMinigame = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Declare some ints for determining if the mouse is hovering over a button
        int mvslHover = 0;
        int minigameHover = 0;
        int optionsHover = 0;

        while (titleScreen) {

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(BLACK);
            DrawTextureRec(titleAsset, mvslHover ? mvslHighlightedBox : mvslUnhighlightedBox, ZERO, WHITE);
            DrawTextureRec(titleAsset, minigameHover ? minigameHighlightedBox : minigameUnhighlightedBox, { 0, highlightedPipeHeight }, WHITE);
            DrawTextureRec(titleAsset, optionsHover ? optionsHighlightedBox : optionsUnhighlightedBox, { 0, highlightedPipeHeight * 2 }, WHITE);

            EndDrawing();
            //----------------------------------------------------------------------------------
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}