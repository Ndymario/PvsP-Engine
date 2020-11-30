/*
Contributors to this file: Nolan Y.
*/
#include <stdio.h>
#include <raylib.h>

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Declare constants for the dimentions of assets
        // Titlescreen:
            const int highlightedPipeWidth = 228;
            const int highlightedPipeHeight = 35;
            const int unhighlitedPipeWidth = 218;
            const int unhighlitedPipeHeight = 35;
            const int numOfButtons = 3;

    // Initalize the game window
    InitWindow(screenWidth, screenHeight, "Mario vs Luigi - Title Screen");

    // Load the Title Screen assets
        Image asset = LoadImage("assets/title/title_screen_assets.png");
        Image mvslButtonHi = ImageCopy(asset);
        Image mvslButtonLo = ImageCopy(asset);
        Image minigameButtonHi = ImageCopy(asset);
        Image minigameButtonLo = ImageCopy(asset);
        Image optionsButtonHi = ImageCopy(asset);
        Image optionsButtonLo = ImageCopy(asset);

        // Define the rectangles for the bounding boxes of the buttons. (Also used for cropping)
        // Y pos of first buttton in the .png is 68
        Rectangle mvslHighlightedBox(0, 68, highlightedPipeWidth, highlightedPipeHeight);
        Rectangle mvslUnhighlightedBox(0, 68 + highlightedPipeHeight, unhighlightedPipeWidth, unhighlightedPipeHeight);
        Rectangle minigameHighlightedBox(0, 68 + (highlightedPipeHeight * 1), highlightedPipeWidth, highlightedPipeHeight);
        Rectangle minigameUnhighlightedBox(0, 68 + (highlightedPipeHeight * 1), unhighlightedPipeWidth, unhighlightedPipeHeight);
        Rectangle optionsHighlightedBox(0, 68 + (highlightedPipeHeight * 2), highlightedPipeWidth, highlightedPipeHeight);
        Rectangle optionsUnhighlightedBox(0, 68 + (highlightedPipeHeight * 2), unhighlightedPipeWidth, unhighlightedPipeHeight);

        // Crop and store the buttons. (Hi = Highlighted, Lo = Unhilighted)
        mvslButtonHi = ImageCrop(mvslButtonHi, mvslHighlighted);
        mvslButtonLo = ImageCrop(mvslButtonLo, mvslUnhighlighted);
        minigameButtonHi = ImageCrop(minigameButtonHi, minigameHighlighted);
        minigameButtonLo = ImageCrop(minigameButtonLo, minigameUnhighlighted);
        optionsButtonHi = ImageCrop(optionsButtonHi, optionsHighlighted);
        optionsButtonLo = ImageCrop(optionsButtonLo, opttionsUnhighlighted);

        // Create Textures for drawing to the screen
        Texture2D mvslButton[2] = { 0 };
        Texture2D minigameButton[2] = { 0 };
        Texture2D optionsButton[2] = { 0 };

        mvslButton[0] = LoadTextureFromImage(mvslButtonLo);
        mvslButton[1] = LoadTextureFromImage(mvslButtonHi);
        minigameButton[0] = LoadTextureFromImage(minigameButtonLo);
        minigameButton[1] = LoadTextureFromImage(minigameButtonHi);
        optionsButton[0] = LoadTextureFromImage(optionsButtonLo);
        optionsButton[1] = LoadTextureFromImage(optionsButtonHi);

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
    
        while (titleScreen){
            
            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

                DrawTexture(mvslButton[mvslHover], 0, 0, WHITE);
                DrawTexture(mvslButton[minigameHover], 0, highlightedPipeHeight, WHITE);
                DrawTexture(mvslButton[optionsHover], 0, highlightedPipeHeight * 2, WHITE);

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