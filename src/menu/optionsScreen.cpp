#include "optionsScreen.h"

// Define some constants for the dimentions of the UI elements
const int buttonWidth = 730;
const int buttonHeight = 215;
const int toggleWidth = 430;
const int toggleHeight = 215;
const int toggleRadius = 100; // The radius of the rounded edges for the toggle
const float BG_SCALE = 2.007f;
const float LOGO_SCALE = 0.23f * 2.007f;
const float BUTTON_SCALE_X = 1.0f;
const float BUTTON_SCALE_Y = 0.7f;
const float BG_SCROLL_SPEED = 70.0f;
const int BUTTON_START_Y = 550;

void OptionsScreen::Initialize()
{

    // BG,
	AssetManager::LoadTextureAsset("menu/TitleBg.png", "TitleBG");
	BG = Shape::createShape("BG", "TitleBG", false, false, 0, 0, 0, 0, AssetManager::GetTexture("TitleBG").width, AssetManager::GetTexture("TitleBG").height, false, 0, 0, 0, false, 0);
	BG.scale(BG_SCALE);
    BG.xPos = Scene::BGPos.x;
	BG.yPos = Scene::BGPos.y;

	// Logo.
	AssetManager::LoadTextureAsset("menu/TitleLogo.png", "OptionsLogo");
	Logo = Shape::createShape("Logo", "OptionsLogo", false, false, 0, 0, 0, 0, AssetManager::GetTexture("OptionsLogo").width, AssetManager::GetTexture("OptionsLogo").height, false, 0, (Screen::GAME_WIDTH - AssetManager::GetTexture("OptionsLogo").width * LOGO_SCALE) / 2, 50, false, 0);
	Logo.scale(LOGO_SCALE);

	// Buttons.
	AssetManager::LoadTextureAsset("menu/UI_and_Text.png", "OptionsUI");
	AssetsButton = Shape::createShape("Assets", "OptionsUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, BUTTON_START_Y, false, 0);
	AssetsButton.scaleX(BUTTON_SCALE_X);
	AssetsButton.scaleY(BUTTON_SCALE_Y);
	AssetsButton.onClick = ClickAssetsButton;

	InputButton = Shape::createShape("Input", "OptionsUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, BUTTON_START_Y + buttonHeight * BUTTON_SCALE_Y * 1.5f, false, 0);
	InputButton.scaleX(BUTTON_SCALE_X);
	InputButton.scaleY(BUTTON_SCALE_Y);
	InputButton.onClick = ClickInputButton;

	GraphicsButton = Shape::createShape("Graphics", "OptionsUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, BUTTON_START_Y + buttonHeight * BUTTON_SCALE_Y * 3.0f, false, 0);
	GraphicsButton.scaleX(BUTTON_SCALE_X);
	GraphicsButton.scaleY(BUTTON_SCALE_Y);
	GraphicsButton.onClick = ClickGraphicsButton;

    AudioButton = Shape::createShape("Audio", "OptionsUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, BUTTON_START_Y + buttonHeight * BUTTON_SCALE_Y * 4.5f, false, 0);
	AudioButton.scaleX(BUTTON_SCALE_X);
	AudioButton.scaleY(BUTTON_SCALE_Y);
	AudioButton.onClick = ClickAudioButton;

	BackButton = Shape::createShape("Back", "OptionsUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, BUTTON_START_Y + buttonHeight * BUTTON_SCALE_Y * 6.0f, false, 0);
	BackButton.scaleX(BUTTON_SCALE_X);
	BackButton.scaleY(BUTTON_SCALE_Y);
	BackButton.onClick = ClickBackButton;

}

void OptionsScreen::DrawBackground2D()
{
    BG.drawRepeated(Screen::GAME_WIDTH + BG.width, Screen::GAME_HEIGHT + BG.height);
}

void OptionsScreen::DrawForeground2D()
{
    Logo.draw();
	AssetsButton.draw();
	InputButton.draw();
	GraphicsButton.draw();
	AudioButton.draw();
    BackButton.draw();
    DrawText("Assets", 655, 275, 55, BLACK);
	DrawText("Input", 605, 275 + buttonHeight * BUTTON_SCALE_Y * 0.75f, 55, BLACK);
	DrawText("Graphics", 630, 275 + buttonHeight * BUTTON_SCALE_Y * 1.5f, 55, BLACK);
	DrawText("Audio", 667, 275 + buttonHeight * BUTTON_SCALE_Y * 2.25f, 55, BLACK);
	DrawText("Back", 667, 275 + buttonHeight * BUTTON_SCALE_Y * 3.0f, 55, BLACK);
}

void OptionsScreen::Draw3D()
{
}

void OptionsScreen::Update()
{

    // BG scrolling.
	BG.xPos -= GetFrameTime() * BG_SCROLL_SPEED;
	BG.yPos -= GetFrameTime() * BG_SCROLL_SPEED;
	if (BG.xPos < -BG.width) {
		BG.xPos = 0;
	}
	if (BG.yPos < -BG.height) {
		BG.yPos = 0;
	}

    // Update buttons.
	AssetsButton.update();
	InputButton.update();
	GraphicsButton.update();
	AudioButton.update();
	BackButton.update();

}

void OptionsScreen::Cleanup()
{
    AssetManager::UnloadTextureAsset("TitleBG");
	AssetManager::UnloadTextureAsset("OptionsLogo");
	AssetManager::UnloadTextureAsset("OptionsUI");
    Scene::BGPos.x = BG.xPos;
	Scene::BGPos.y = BG.yPos;
}

void ClickAssetsButton()
{
}

void ClickInputButton()
{
}

void ClickGraphicsButton()
{
}

void ClickAudioButton()
{
}

void ClickBackButton()
{
    Scene::ChangeScene("TitleScreen");
}