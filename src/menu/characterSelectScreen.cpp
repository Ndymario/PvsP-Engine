#include "characterSelectScreen.h"
#include "../screen.h"

const int PODIUM_Y_OFF = 50;
const int PODIUM_X_OFF = 300;
const int ARROW_X_OFF = 30;
const int ARROW_Y_OFF = 30;

void CharacterSelectScreen::Initialize()
{

    // Assets.
    AssetManager::LoadTextureAsset("menu/Podium.png", "Podium");
    AssetManager::LoadTextureAsset("menu/ArrowLeft.png", "LeftArrow");
    AssetManager::LoadTextureAsset("menu/ArrowRight.png", "RightArrow");

    // Podium.
    P1Podium = Shape::createShape("P1Podium", "Podium", false, false, 0, 0, 0, 0, AssetManager::GetTexture("Podium").width, AssetManager::GetTexture("Podium").height, false, 0.0f, PODIUM_X_OFF, Screen::GAME_HEIGHT - AssetManager::GetTexture("Podium").height - PODIUM_Y_OFF, false, 0.0f);
    P2Podium = Shape::createShape("P2Podium", "Podium", false, false, 0, 0, 0, 0, AssetManager::GetTexture("Podium").width, AssetManager::GetTexture("Podium").height, false, 0.0f, Screen::GAME_WIDTH - AssetManager::GetTexture("Podium").width - PODIUM_X_OFF, Screen::GAME_HEIGHT - AssetManager::GetTexture("Podium").height - PODIUM_Y_OFF, false, 0.0f);

    // Arrows.
    P1ArrowLeft = Shape::createShape("P1LeftArrow", "LeftArrow", true, false, false, false, 0, 0, AssetManager::GetTexture("LeftArrow").width, AssetManager::GetTexture("LeftArrow").height, false, 0.0f, P1Podium.xPos + ARROW_X_OFF, P1Podium.yPos + P1Podium.height - AssetManager::GetTexture("RightArrow").height - ARROW_Y_OFF, false, 0);
    P1ArrowRight = Shape::createShape("P1RightArrow", "RightArrow", true, false, false, false, 0, 0, AssetManager::GetTexture("RightArrow").width, AssetManager::GetTexture("RightArrow").height, false, 0.0f, P1Podium.xPos + P1Podium.width - AssetManager::GetTexture("RightArrow").width - ARROW_X_OFF, P1Podium.yPos + P1Podium.height - AssetManager::GetTexture("RightArrow").height - ARROW_Y_OFF, false, 0);
    P2ArrowLeft = Shape::createShape("P2LeftArrow", "LeftArrow", true, false, false, false, 0, 0, AssetManager::GetTexture("LeftArrow").width, AssetManager::GetTexture("LeftArrow").height, false, 0.0f, P2Podium.xPos + ARROW_X_OFF, P2Podium.yPos + P2Podium.height - AssetManager::GetTexture("RightArrow").height - ARROW_Y_OFF, false, 0);
    P2ArrowRight = Shape::createShape("P2RightArrow", "RightArrow", true, false, false, false, 0, 0, AssetManager::GetTexture("RightArrow").width, AssetManager::GetTexture("RightArrow").height, false, 0.0f, P2Podium.xPos + P2Podium.width - AssetManager::GetTexture("RightArrow").width - ARROW_X_OFF, P2Podium.yPos + P2Podium.height - AssetManager::GetTexture("RightArrow").height - ARROW_Y_OFF, false, 0);

}

void CharacterSelectScreen::DrawBackground2D()
{
    ClearBackground(DARKPURPLE);
}

void CharacterSelectScreen::DrawForeground2D()
{
    P1Podium.draw();
    P2Podium.draw();
    P1ArrowLeft.draw();
    P1ArrowRight.draw();
    P2ArrowLeft.draw();
    P2ArrowRight.draw();
}

void CharacterSelectScreen::Draw3D()
{
}

void CharacterSelectScreen::Update()
{
}

void CharacterSelectScreen::Cleanup()
{
    AssetManager::UnloadTextureAsset("Podium");
}