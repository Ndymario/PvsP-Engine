#include "gameplay.h"
#include <assetManager.h>
#include "input.h"

int frameCounter;
Vector3 pos = {0, 0, 0};
Vector3 rot = {90, 0, 0};

void Gameplay::Initialize()
{

	AssetManager::LoadModelAsset("player/Mario/models/Big.iqm", "MarioBig");
	AssetManager::LoadTextureAsset("player/Mario/textures/Normal.png", "MarioNormal");
	AssetManager::LoadAnimationAsset("player/Animations/Run.iqm", "MarioRun");
    AssetManager::LoadAnimationAsset("player/Animations/Walk.iqm", "MarioWalk");
    AssetManager::LoadAnimationAsset("player/Animations/Wait.iqm", "MarioIdle");
    AssetManager::LoadAnimationAsset("player/Animations/Turn.iqm", "MarioTurn");
    AssetManager::LoadAnimationAsset("player/Animations/Turn.iqm", "MarioTurned");

	//AssetManager::LoadModelAsset("player/Mario/models/Head.iqm", "MarioHead");

	AssetManager::LoadModelAsset("enemy/Bros/Bros.iqm", "Bros");
	AssetManager::LoadTextureAsset("enemy/Bros/HammerBro.png", "HammerBro");
	AssetManager::LoadAnimationAsset("enemy/Bros/ThrowAnim.iqm", "HammerThrow");

	marioModel.SetModel("MarioBig");
	marioModel.SetAnimation("MarioRun");
	marioModel.SetTexture("MarioNormal", 0, MAP_DIFFUSE);
	//playerHeadModel.SetModel("MarioHead");

	hammerBro.SetModel("Bros");
	hammerBro.SetAnimation("HammerThrow");
	hammerBro.SetTexture("HammerBro", 0, MAP_DIFFUSE);

	camera.position = {0.0f, 0.0f, 15.0f}; // Camera position
	camera.target = {0.0f, 0.0f, 0.0f};    // Camera looking at point
	camera.up = {0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target)
	camera.fovy = 35.0f;                   // Camera field-of-view Y
	camera.type = CAMERA_ORTHOGRAPHIC;     // Camera mode type

    player.Initialize(5, 0, false, false);
}

void Gameplay::DrawBackground2D()
{
}

void Gameplay::DrawForeground2D()
{
}

void Gameplay::Draw3D()
{
	//DrawGrid(10, 1.0f);
	//DrawModelEx(hammerBro.GetModel(), { 0, 0, 0 }, { 1.0f, 0.0f, 0.0f }, -90.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
	DrawModel(player.GetModel().GetModel(), player.GetPosition(), 0.1f, WHITE);
	//DrawModelEx(playerHeadModel.GetModel(), {0, 3, 0 }, { 1.0f, 0.0f, 0.0f }, -270.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
}

void Gameplay::Update()
{
    player.Update(GetFrameTime());
}

void Gameplay::Cleanup()
{
}