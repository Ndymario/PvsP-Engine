#include "titleScreen.h"
#include "../assetManager.h"
#include "../screen.h"
#include <imgui.h>

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

void TitleScreen::Initialize()
{

	// BG,
	AssetManager::LoadTextureAsset("menu/TitleBg.png", "TitleBG");
	BG = Shape::createShape("BG", "TitleBG", false, false, 0, 0, 0, 0, AssetManager::GetTexture("TitleBG").width, AssetManager::GetTexture("TitleBG").height, false, 0, 0, 0, false, 0);
	BG.scale(BG_SCALE);
	BG.xPos = Scene::BGPos.x;
	BG.yPos = Scene::BGPos.y;

	// Logo.
	AssetManager::LoadTextureAsset("menu/TitleLogo.png", "TitleLogo");
	Logo = Shape::createShape("Logo", "TitleLogo", false, false, 0, 0, 0, 0, AssetManager::GetTexture("TitleLogo").width, AssetManager::GetTexture("TitleLogo").height, false, 0, (Screen::GAME_WIDTH - AssetManager::GetTexture("TitleLogo").width * LOGO_SCALE) / 2, 50, false, 0);
	Logo.scale(LOGO_SCALE);

	// Buttons.
	AssetManager::LoadTextureAsset("menu/UI_and_Text.png", "TitleUI");
	PvsPButton = Shape::createShape("PvsP", "TitleUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500, false, 0);
	PvsPButton.scaleX(BUTTON_SCALE_X);
	PvsPButton.scaleY(BUTTON_SCALE_Y);
	PvsPButton.onClick = ClickPvsPButton;

	MinigamesButton = Shape::createShape("Minigames", "TitleUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500 + buttonHeight * BUTTON_SCALE_Y * 1.5f, false, 0);
	MinigamesButton.scaleX(BUTTON_SCALE_X);
	MinigamesButton.scaleY(BUTTON_SCALE_Y);
	MinigamesButton.onClick = ClickMinigameButton;

	OptionsButton = Shape::createShape("Options", "TitleUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500 + buttonHeight * BUTTON_SCALE_Y * 3.0f, false, 0);
	OptionsButton.scaleX(BUTTON_SCALE_X);
	OptionsButton.scaleY(BUTTON_SCALE_Y);
	OptionsButton.onClick = ClickOptionsButton;

	QuitButton = Shape::createShape("Quit", "TitleUI", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, (Screen::GAME_WIDTH - buttonWidth * BUTTON_SCALE_X) / 2, 500 + buttonHeight * BUTTON_SCALE_Y * 4.5f, false, 0);
	QuitButton.scaleX(BUTTON_SCALE_X);
	QuitButton.scaleY(BUTTON_SCALE_Y);
	QuitButton.onClick = ClickQuitButton;

}

void TitleScreen::DrawBackground2D()
{
	BG.drawRepeated(Screen::GAME_WIDTH + BG.width, Screen::GAME_HEIGHT + BG.height);
}

void TitleScreen::DrawForeground2D()
{
	Logo.draw();
	PvsPButton.draw();
	MinigamesButton.draw();
	OptionsButton.draw();
	QuitButton.draw();
	DrawText("PvsP", 655, 275, 55, BLACK);
	DrawText("Minigames", 605, 275 + buttonHeight * BUTTON_SCALE_Y * 0.75f, 55, BLACK);
	DrawText("Options", 630, 275 + buttonHeight * BUTTON_SCALE_Y * 1.5f, 55, BLACK);
	DrawText("Quit", 667, 275 + buttonHeight * BUTTON_SCALE_Y * 2.25f, 55, BLACK);
}

void TitleScreen::Draw3D()
{
}

void TitleScreen::DrawImGui()
{
}

void TitleScreen::Update()
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
	PvsPButton.update();
	MinigamesButton.update();
	OptionsButton.update();
	QuitButton.update();

}

void TitleScreen::Cleanup()
{
	AssetManager::UnloadTextureAsset("TitleBG");
	AssetManager::UnloadTextureAsset("TitleLogo");
	AssetManager::UnloadTextureAsset("TitleUI");
	Scene::BGPos.x = BG.xPos;
	Scene::BGPos.y = BG.yPos;
}

void ClickPvsPButton()
{
	Scene::ChangeScene("PvsPScreen");
}

void ClickMinigameButton()
{
	Scene::ChangeScene("LevelEditor");
	//Scene::ChangeScene("Gameplay");
}

void ClickOptionsButton()
{
	Scene::ChangeScene("OptionsScreen");
}

void ClickQuitButton()
{
	Screen::quitGame = true;
}