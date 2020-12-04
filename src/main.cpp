/*
Main contributors to this file: Nolan Y.

Bug fixers: Gota7, bbomb64
*/
#include <iostream>
#include <stdio.h>
#include <raylib.h>
#include <algorithm>

// Some constants.
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const Vector2 ZERO = { 0, 0 };
std::string rootDir = std::string(GetWorkingDirectory());
std::string titleScreenAsset = "/./../assets/title/title_screen_assets.png";
std::string audioAsset = "/./../assets/sounds";

int main(void) {

    // Initialization
    //--------------------------------------------------------------------------------------

    // Declare constants for the dimentions of assets
        // Titlescreen:
    const int highlightedPipeWidth = 228;
    const int highlightedPipeHeight = 35;
    const int unhighlightedPipeWidth = 217;
    const int unhighlightedPipeHeight = 35;
    const int backgroundWidth = 256;
    const int backgroundHeight = 160;

    // Set up the CWD
    std::string backgroundAsset = rootDir + titleScreenAsset;

    // Initalize the game window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mario vs Luigi - Title Screen");

    // Load the Title Screen assets
    Image asset = LoadImage(backgroundAsset.c_str());

    // Define the rectangles for the bounding boxes of the buttons. (Also used for cropping)
    // Y pos of first buttton in the .png is 68
    // BG Coords (270, 195)
    Rectangle mvslHighlightedBox = { 0, 68, highlightedPipeWidth, highlightedPipeHeight };
    Rectangle mvslUnhighlightedBox = { 0, 68 + highlightedPipeHeight, unhighlightedPipeWidth, unhighlightedPipeHeight };
    Rectangle minigameHighlightedBox = { 0, 68 + (highlightedPipeHeight * 2), highlightedPipeWidth, highlightedPipeHeight };
    Rectangle minigameUnhighlightedBox = { 0, 68 + (highlightedPipeHeight * 3), unhighlightedPipeWidth, unhighlightedPipeHeight };
    Rectangle optionsHighlightedBox = { 0, 68 + (highlightedPipeHeight * 4), highlightedPipeWidth, highlightedPipeHeight };
    Rectangle optionsUnhighlightedBox = { 0, 68 + (highlightedPipeHeight * 5), unhighlightedPipeWidth, unhighlightedPipeHeight };
    Rectangle backgroundBox = { 270, 195, backgroundWidth, backgroundHeight};

    // Create Textures for drawing to the screen
    Texture2D titleAsset = LoadTextureFromImage(asset);

    // Declare bools to keep track of what game state we are in
    bool titleScreen = true;
    bool inGame = false;
    bool inMinigame = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Initalize the Audio and set the Master Audio to default
    InitAudioDevice();
    SetMasterVolume(100);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Declare some ints for determining if the mouse is hovering over a button
        bool mvslHover = 0;
        bool minigameHover = 0;
        bool optionsHover = 0;

        // Declare some bounding boxes for the title screen buttons
        Rectangle mvslButton = { SCREEN_WIDTH/4 + 20, backgroundHeight, highlightedPipeWidth, highlightedPipeHeight };
        Rectangle minigameButton = { mvslButton.x, mvslButton.y + highlightedPipeHeight, highlightedPipeWidth, highlightedPipeHeight };
        Rectangle optionsButton = { mvslButton.x, minigameButton.y + highlightedPipeHeight, highlightedPipeWidth, highlightedPipeHeight };

        Vector2 mvslButtonCoords = { mvslButton.x, mvslButton.y };
        Vector2 minigameButtonCoords = { minigameButton.x, minigameButton.y };
        Vector2 optionsButtonCoords = { optionsButton.x, optionsButton.y };

        // Make a position vector for the background
        Vector2 backgroundCoords = { SCREEN_WIDTH/4, backgroundHeight};

        // Load button sounds
        std::string buttonSoundAsset = rootDir + audioAsset + "/Mario/whoohoo.wav";
        Sound buttonSound = LoadSoundFromWave(LoadWave(buttonSoundAsset.c_str()));

        // Declare and Initalized the status of the buttons
        bool mvslButtonPressed = false;
        bool miniGameButtonPressed = false;
        bool optionsButtonPressed = false;

        while (titleScreen) {

            // Swap the Texture for if the buttons are highlightted are not

            if (GetMouseX() > mvslButton.x & GetMouseX() < (mvslButton.x + highlightedPipeWidth)){
                if (GetMouseY() > mvslButton.y & GetMouseY() < (mvslButton.y + highlightedPipeHeight)){
                    mvslHover = 1;
                } else {
                    mvslHover = 0;
                }
            } else {
                mvslHover = 0;
            }

            if (GetMouseX() > minigameButton.x & GetMouseX() < (minigameButton.x + highlightedPipeWidth)){
                if ((GetMouseY() > minigameButton.y) & (GetMouseY() < (minigameButton.y + highlightedPipeHeight))){
                    minigameHover = 1;
                } else {
                    minigameHover = 0;
                }
            } else {
                minigameHover = 0;
            }

            if (GetMouseX() > optionsButton.x & GetMouseX() < (optionsButton.x + highlightedPipeWidth)){
                if ((GetMouseY() > optionsButton.y) & (GetMouseY() < (optionsButton.y + highlightedPipeHeight))){
                    optionsHover = 1;
                } else {
                    optionsHover = 0;
                }
            } else {
                optionsHover = 0;
            }

            // Check to see if the mouse is being clicked inside of a button, and do something based
            // on what button is pressed

            if (IsMouseButtonPressed(0)){
                if (mvslHover == 1){
                    // If the mouse clicks on the MvsL Button
                    PlaySound(buttonSound);
                    mvslButtonPressed = true;
                }

                if (minigameHover == 1){
                    // If the mouse clicks on the Minigame Button
                    PlaySound(buttonSound);
                    miniGameButtonPressed = true;
                }

                if (optionsHover == 1){
                    // If the mouse clicks on the Options Button
                    PlaySound(buttonSound);
                    optionsButtonPressed = true;
                }
            }
            // Draw to the screen
            BeginDrawing();

            // Clear the frame for the next frame
            ClearBackground(BLACK);

            if(!optionsButtonPressed){
                DrawTextureRec(titleAsset, backgroundBox, backgroundCoords, WHITE);
                DrawTextureRec(titleAsset, mvslHover ? mvslHighlightedBox : mvslUnhighlightedBox, mvslButtonCoords, WHITE);
                DrawTextureRec(titleAsset, minigameHover ? minigameHighlightedBox : minigameUnhighlightedBox, minigameButtonCoords, WHITE);
                DrawTextureRec(titleAsset, optionsHover ? optionsHighlightedBox : optionsUnhighlightedBox, optionsButtonCoords, WHITE);
            }

            if(optionsButtonPressed){
                //TODO: Add buttons to draw for the options menu
            }

            // End Drawing to the screen
            EndDrawing();

            // Post rendering
            if(mvslButtonPressed || miniGameButtonPressed){
                // Transition to the other scene
                titleScreen = false;

                if(mvslButtonPressed){
                    // Load the MvsL game scene
                    // [TODO]
                }

                if(miniGameButtonPressed){
                    // Load the minigame game scene
                    // [TODO]
                }
            }

        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();   // Close the Audio Device
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}