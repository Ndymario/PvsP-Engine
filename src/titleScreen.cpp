#include "titleScreen.h"
#include "assetManager.h"
#include "screen.h"

void TitleScreen::Initialize()
{
	AssetManager::LoadTextureAsset("menu/TitleBg.png", "TitleBG");
	BG = Shape::createShape("BG", "TitleBG", false, false, 0, 0, 0, 0, AssetManager::GetTexture("TitleBG").width, AssetManager::GetTexture("TitleBG").height, false, 0, 0, 0, false, 0);
}

void TitleScreen::DrawBackground2D()
{
	BG.drawRepeated(Screen::GAME_WIDTH + BG.width, Screen::GAME_HEIGHT + BG.height);
}

void TitleScreen::DrawForeground2D()
{
}

void TitleScreen::Draw3D()
{
}

void TitleScreen::Update()
{
	BG.xPos -= GetFrameTime() * BG_SCROLL_SPEED;
	BG.yPos -= GetFrameTime() * BG_SCROLL_SPEED;
	if (BG.xPos < -BG.width) {
		BG.xPos = 0;
	}
	if (BG.yPos < -BG.height) {
		BG.yPos = 0;
	}
}

void TitleScreen::Cleanup()
{
	AssetManager::UnloadTextureAsset("TitleBG");
}