#include "titleScreen.h"
#include "assetManager.h"
#include "screen.h"

const int SCREEN_WIDTH = 1435;
const int SCREEN_HEIGHT = 900;

// Declare constants for the dimentions of assets
// Titlescreen:
const int highlightedButtonWidth = 228;
const int highlightedButtonHeight = 35;
const int unhighlightedButtonWidth = 228;
const int unhighlightedButtonHeight = 35;
const int backgroundWidth = 256;
const int backgroundHeight = 160;

// Declare bools to keep track of what game state we are in
bool titleScreen = true;
bool inGame = false;
bool inMinigame = false;

// Declare some bools for determining if the mouse is hovering over a button
bool pvspHover = false;
bool minigameHover = false;
bool optionsHover = false;

// Define the rectangles for the bounding boxes of the buttons. (Also used for cropping)
// Y pos of first buttton in the .png is 68
// BG Coords (270, 195)
Rectangle pvspHighlightedBox = {0, 68, highlightedButtonWidth, highlightedButtonHeight};
Rectangle pvspUnhighlightedBox = {0, 68 + highlightedButtonHeight, unhighlightedButtonWidth, unhighlightedButtonHeight};
Rectangle minigameHighlightedBox = {0, 68 + (highlightedButtonHeight * 2), highlightedButtonWidth, highlightedButtonHeight};
Rectangle minigameUnhighlightedBox = {0, 68 + (highlightedButtonHeight * 3), unhighlightedButtonWidth, unhighlightedButtonHeight};
Rectangle optionsHighlightedBox = {0, 68 + (highlightedButtonHeight * 4), highlightedButtonWidth, highlightedButtonHeight};
Rectangle optionsUnhighlightedBox = {0, 68 + (highlightedButtonHeight * 5), unhighlightedButtonWidth, unhighlightedButtonHeight};
Rectangle backgroundBox = {270, 195, backgroundWidth, backgroundHeight};

// Declare some bounding boxes for the title screen buttons
Rectangle pvspButton = {SCREEN_WIDTH / 4 + 20, backgroundHeight, highlightedButtonWidth * 3, highlightedButtonHeight * 3};
Rectangle minigameButton = {pvspButton.x, pvspButton.y + highlightedButtonHeight * 3, highlightedButtonWidth * 3, highlightedButtonHeight * 3};
Rectangle optionsButton = {pvspButton.x, minigameButton.y + highlightedButtonHeight * 3, highlightedButtonWidth * 3, highlightedButtonHeight * 3};

Rectangle pvspButtonCoords = {pvspButton.x, pvspButton.y, highlightedButtonWidth * 3, highlightedButtonHeight * 3};
Rectangle minigameButtonCoords = {minigameButton.x, minigameButton.y, highlightedButtonWidth * 3, highlightedButtonHeight * 3};
Rectangle optionsButtonCoords = {optionsButton.x, optionsButton.y, highlightedButtonWidth * 3, highlightedButtonHeight * 3};

// Make a position vector for the background
Rectangle backgroundCoords = {SCREEN_WIDTH / 4, backgroundHeight, backgroundWidth * 3, backgroundHeight * 3};

// Declare and Initalized the status of the buttons
bool pvspButtonPressed = false;
bool miniGameButtonPressed = false;
bool optionsButtonPressed = false;

// Misc. assets.
Texture2D titleAsset;
Sound buttonSound;

void TitleScreen::Initialize()
{
	AssetManager::LoadTextureAsset("title/title_screen_assets.png", "TitleAsset");
	titleAsset = AssetManager::GetTexture("TitleAsset");
	AssetManager::LoadSoundAsset("sounds/Martin/whoohoo.wav", "TitleButtonSound");
	buttonSound = AssetManager::GetSound("TitleButtonSound");
}

void TitleScreen::DrawBackground2D()
{
}

void TitleScreen::DrawForeground2D()
{

	if (!optionsButtonPressed)
	{
		DrawTexturePro(titleAsset, backgroundBox, Screen::ScaleRectangle(&backgroundCoords), {0, 0}, 0, WHITE);
		DrawTexturePro(titleAsset, pvspHover ? pvspHighlightedBox : pvspUnhighlightedBox, Screen::ScaleRectangle(&pvspButtonCoords), {0, 0}, 0, WHITE);
		DrawTexturePro(titleAsset, minigameHover ? minigameHighlightedBox : minigameUnhighlightedBox, Screen::ScaleRectangle(&minigameButtonCoords), {0, 0}, 0, WHITE);
		DrawTexturePro(titleAsset, optionsHover ? optionsHighlightedBox : optionsUnhighlightedBox, Screen::ScaleRectangle(&optionsButtonCoords), {0, 0}, 0, WHITE);
	}

	if (optionsButtonPressed)
	{
		DrawRectangle(10, 10, 10, 10, RED);
	}
}

void TitleScreen::Draw3D()
{
}

void TitleScreen::Update()
{

	// Swap the Texture for if the buttons are highlightted are not
	pvspHover = CheckCollisionPointRec(GetMousePosition(), Screen::ScaleRectangle(&pvspButton));
	minigameHover = CheckCollisionPointRec(GetMousePosition(), Screen::ScaleRectangle(&minigameButton));
	optionsHover = CheckCollisionPointRec(GetMousePosition(), Screen::ScaleRectangle(&optionsButton));

	// Check to see if the mouse is being clicked inside of a button, and do something based
	// on what button is pressed

	if (IsMouseButtonPressed(0))
	{
		if (pvspHover)
		{
			// If the mouse clicks on the pvsp Button
			//PlaySound(buttonSound);
			pvspButtonPressed = true;
		}
		else if (minigameHover)
		{
			// If the mouse clicks on the Minigame Button
			//PlaySound(buttonSound);
			miniGameButtonPressed = true;
		}
		else if (optionsHover)
		{
			// If the mouse clicks on the Options Button
			//PlaySound(buttonSound);
			optionsButtonPressed = true;
		}
	}

	if (pvspButtonPressed || miniGameButtonPressed)
	{
		// Transition to the other scene
		titleScreen = false;

		if (pvspButtonPressed)
		{
			// Load the pvsp game scene
			Scene::ChangeScene("Gameplay");
		}

		if (miniGameButtonPressed)
		{
			// Load the minigame game scene
			// [TODO]
		}
	}
}

void TitleScreen::Cleanup()
{

	AssetManager::UnloadTextureAsset("TitleAsset");
	//AssetManager::UnloadSoundAsset("TitleButtonSound");
}