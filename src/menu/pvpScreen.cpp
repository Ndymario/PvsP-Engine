// Include headers we need
#include "pvpScreen.h"
#include "input.h"
#include "assetManager.h"
#include "screen.h"
#include "ui.h"
#include "optionsScreen.h"

// Define some constants for the dimentions of the UI elements
const int buttonWidth = 730;
const int buttonHeight = 215;
const int toggleWidth = 430;
const int toggleHeight = 215;
const int toggleRadius = 100; // The radius of the rounded edges for the toggle
const float BG_SCALE = 2.007f;
const float LOGO_SCALE = 0.23f * 2.007f;
const float BUTTON_SCALE_X = 1.7f;
const float BUTTON_SCALE_Y = 1.0f;
const float BG_SCROLL_SPEED = 70.0f;

// Define Assets
Texture2D ui_text;

void PvsPScreen::Initialize()
{

    // BG,
	AssetManager::LoadTextureAsset("menu/TitleBg.png", "TitleBG");
	BG = Shape::createShape("BG", "TitleBG", false, false, 0, 0, 0, 0, AssetManager::GetTexture("TitleBG").width, AssetManager::GetTexture("TitleBG").height, false, 0, 0, 0, false, 0);
	BG.scale(BG_SCALE);
	BG.xPos = Scene::BGPos.x;
	BG.yPos = Scene::BGPos.y;

    // Logo.
	AssetManager::LoadTextureAsset("menu/TitleLogo.png", "Logo");
	Logo = Shape::createShape("Logo", "Logo", false, false, 0, 0, 0, 0, AssetManager::GetTexture("Logo").width, AssetManager::GetTexture("Logo").height, false, 0, (Screen::GAME_WIDTH - AssetManager::GetTexture("Logo").width * LOGO_SCALE) / 2, 50, false, 0);
	Logo.scale(LOGO_SCALE);

    // Load assets.
    AssetManager::LoadTextureAsset("menu/UI_and_Text.png", "UI_Text");

    // Create shapes.
	localButton = Shape::createShape("Local", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500, false, 0);
	localButton.scaleX(BUTTON_SCALE_X);
	localButton.scaleY(BUTTON_SCALE_Y);
	localButton.onClick = ClickLocalButton;

	onlineButton = Shape::createShape("Online", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500 + buttonHeight * BUTTON_SCALE_Y * 1.5f, false, 0);
	onlineButton.scaleX(BUTTON_SCALE_X);
	onlineButton.scaleY(BUTTON_SCALE_Y);
	onlineButton.onClick = ClickOnlineButton;

	trainingButton = Shape::createShape("Training", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500 + buttonHeight * BUTTON_SCALE_Y * 3.0f, false, 0);
	trainingButton.scaleX(BUTTON_SCALE_X);
	trainingButton.scaleY(BUTTON_SCALE_Y);
	trainingButton.onClick = ClickTrainingButton;

    backButton = Shape::createShape("Back", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500 + buttonHeight * BUTTON_SCALE_Y * 4.5f, false, 0);
	backButton.scaleX(BUTTON_SCALE_X);
	backButton.scaleY(BUTTON_SCALE_Y);
	backButton.onClick = ClickBackButton;

}

void PvsPScreen::DrawBackground2D()
{
    BG.drawRepeated(Screen::GAME_WIDTH + BG.width, Screen::GAME_HEIGHT + BG.height);
}

void PvsPScreen::DrawForeground2D()
{
    Logo.draw();
    localButton.draw();
    onlineButton.draw();
    trainingButton.draw();
    backButton.draw();
    DrawText("Local", 655, 275, 55, BLACK);
	DrawText("Online", 605, 275 + buttonHeight * BUTTON_SCALE_Y * 0.75f, 55, BLACK);
	DrawText("Training", 630, 275 + buttonHeight * BUTTON_SCALE_Y * 1.5f, 55, BLACK);
	DrawText("Back", 667, 275 + buttonHeight * BUTTON_SCALE_Y * 2.25f, 55, BLACK);
}

void PvsPScreen::Draw3D()
{
}

void PvsPScreen::Update()
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
	localButton.update();
	onlineButton.update();
	trainingButton.update();
	backButton.update();
    
}

void PvsPScreen::Cleanup()
{
    AssetManager::UnloadTextureAsset("TitleBG");
    AssetManager::UnloadTextureAsset("UI_Text");
    AssetManager::UnloadTextureAsset("Logo");
}

void ClickLocalButton()
{
	Scene::ChangeScene("CharacterSelectScreen");
}

void ClickOnlineButton()
{
	Scene::ChangeScene("CharacterSelectScreen");
}

void ClickTrainingButton()
{
	Scene::ChangeScene("CharacterSelectScreen");
}