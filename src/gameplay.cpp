#include "gameplay.h"
#include <assetManager.h>
#include "input.h"

Vector3 pos = { 0, 0, 0 };

void Gameplay::Initialize()
{

    AssetManager::LoadModelAsset("player/Mario/models/Big.iqm", "MarioBig");
    AssetManager::LoadTextureAsset("player/Mario/textures/Normal.png", "MarioNormal");
    AssetManager::LoadAnimationAsset("player/Animations/Run.iqm", "MarioRun");
    //AssetManager::LoadModelAsset("player/Mario/models/Head.iqm", "MarioHead");

    AssetManager::LoadModelAsset("enemy/Bros/Bros.iqm", "Bros");
    AssetManager::LoadTextureAsset("enemy/Bros/HammerBro.png", "HammerBro");
    AssetManager::LoadAnimationAsset("enemy/Bros/ThrowAnim.iqm", "HammerThrow");

    playerModel.SetModel("MarioBig");
    playerModel.SetAnimation("MarioRun");
    playerModel.SetTexture("MarioNormal", 0, MAP_DIFFUSE);
    //playerHeadModel.SetModel("MarioHead");

    hammerBro.SetModel("Bros");
    hammerBro.SetAnimation("HammerThrow");
    hammerBro.SetTexture("HammerBro", 0, MAP_DIFFUSE);

    camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type

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
    DrawModelEx(hammerBro.GetModel(), { 0, 0, 3 }, { 1.0f, 0.0f, 0.0f }, -90.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
    DrawModelEx(playerModel.GetModel(), pos, { 1.0f, 0.0f, 0.0f }, -90.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
    //DrawModelEx(playerHeadModel.GetModel(), {0, 3, 0 }, { 1.0f, 0.0f, 0.0f }, -270.0f, { 0.1f, 0.1f, 0.1f }, WHITE);

}

void Gameplay::Update()
{

    playerModel.Update();
    hammerBro.Update();
    //pos.x += 0.075;

    pos.x -= Input::ButtonDown("Left", 0) * 0.1f;
    pos.x += Input::ButtonDown("Right", 0) * 0.1f;

}

void Gameplay::Cleanup()
{



}