// Include headers we need
#include "pvpScene.h"
#include "input.h"
#include "assetManager.h"
#include "screen.h"
#include "ui.h"

// Define some constants for the dimentions of the UI elements
const int buttonWidth = 730;
const int buttonHeight = 215;
const int toggleWidth = 430;
const int toggleHeight = 215;
const int toggleRadius = 100; // The radius of the rounded edges for the toggle

// Define Assets
Texture2D ui_text;

void PvsP_Menu::Initialize(){
    // Load assets
    AssetManager::LoadTextureAsset("menu/UI_and_Text.png", "UI_Text");

    // Create shapes
    localButton = Shape::createShape("Local", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, 0, 0, false, 0);

    onlineButton = Shape::createShape("Online", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, 0, 90, false, 0);

    trainingButton = Shape::createShape("Training", "UI_Text", true, false, 0, 0, 0, 0, buttonWidth, buttonHeight,\
    false, 0, 0, 180, false, 0);
};

void PvsP_Menu::DrawForeground2D(){
    DrawTexturePro(localButton.shapeTexture, localButton.textureRectangle, localButton.shapeRectangle, {0, 0}, 0, WHITE);
    DrawTexturePro(onlineButton.shapeTexture, onlineButton.textureRectangle, onlineButton.shapeRectangle, {0, 0}, 0, WHITE);
    DrawTexturePro(trainingButton.shapeTexture, trainingButton.textureRectangle, trainingButton.shapeRectangle, {0, 0}, 0, WHITE);
};

void PvsP_Menu::Update(){
    // TODO
};

void PvsP_Menu::Cleanup(){
    // TODO
};