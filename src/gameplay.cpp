#include "gameplay.h"
#include "main.h"
#include <assetManager.h>

int frameCounter;
Vector3 pos = { 0, 0, 0 };

void Gameplay::Initialize()
{

    AssetManager::LoadModelAsset("player/Mario/models/Big.iqm", "MarioBig");
    AssetManager::LoadTextureAsset("player/Mario/textures/Normal.png", "MarioNormal");
    AssetManager::LoadAnimationAsset("player/Animations/Run.iqm", "MarioRun");

    playerModel.SetModel("MarioBig");
    playerModel.SetAnimation("MarioRun");
    playerModel.SetTexture("MarioNormal", 0, MAP_DIFFUSE);

}

void Gameplay::DrawBackground2D()
{



}

void Gameplay::DrawForeground2D()
{



}

void Gameplay::Draw3D()
{

    DrawGrid(10, 1.0f);
    DrawModelEx(playerModel.GetModel(), pos, { 1.0f, 0.0f, 0.0f }, -90.0f, { 0.1f, 0.1f, 0.1f }, WHITE);

}

void Gameplay::Update()
{

    playerModel.Update();
    pos.x += 0.075;
    //MainCamera->position.x += 5;

}

void Gameplay::Cleanup()
{



}