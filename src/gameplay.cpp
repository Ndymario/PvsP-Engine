#include "gameplay.h"
#include <assetManager.h>
#include "input.h"
#include "tile.h"

int frameCounter;
Vector3 pos = {0, 0, 0};
Vector3 rot = {90, 0, 0};

void Gameplay::Initialize()
{

	/*AssetManager::LoadModelAsset("player/Martin/models/Big.iqm", "MartinBig");
	AssetManager::LoadTextureAsset("player/Martin/textures/Normal.png", "MartinNormal");
	AssetManager::LoadAnimationAsset("player/Animations/Run.iqm", "MartinRun");
    AssetManager::LoadAnimationAsset("player/Animations/Walk.iqm", "MartinWalk");
    AssetManager::LoadAnimationAsset("player/Animations/Wait.iqm", "MartinIdle");
    AssetManager::LoadAnimationAsset("player/Animations/Turn.iqm", "MartinTurn");
    AssetManager::LoadAnimationAsset("player/Animations/Turn.iqm", "MartinTurned");

	//AssetManager::LoadModelAsset("player/Martin/models/Head.iqm", "MartinHead");

	AssetManager::LoadModelAsset("enemy/Bros/Bros.iqm", "Bros");
	AssetManager::LoadTextureAsset("enemy/Bros/HammerBro.png", "HammerBro");
	AssetManager::LoadAnimationAsset("enemy/Bros/ThrowAnim.iqm", "HammerThrow");

	martinModel.SetModel("MartinBig");
	martinModel.SetAnimation("MartinRun");
	martinModel.SetTexture("MartinNormal", 0, MAP_DIFFUSE);
	//playerHeadModel.SetModel("MartinHead");

	hammerBro.SetModel("Bros");
	hammerBro.SetAnimation("HammerThrow");
	hammerBro.SetTexture("HammerBro", 0, MAP_DIFFUSE);

	camera.position = {0.0f, 0.0f, 15.0f}; // Camera position
	camera.target = {0.0f, 0.0f, 0.0f};    // Camera looking at point
	camera.up = {0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target)
	camera.fovy = 35.0f;                   // Camera field-of-view Y
	camera.type = CAMERA_ORTHOGRAPHIC;     // Camera mode type

    player.Initialize(5, 0, false, false);*/

	camera.position = {0.0f, 0.0f, 15.0f}; // Camera position
	camera.target = {0.0f, 0.0f, 0.0f};    // Camera looking at point
	camera.up = {0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target)
	camera.fovy = 35.0f;                   // Camera field-of-view Y
	camera.type = CAMERA_ORTHOGRAPHIC;     // Camera mode type

	AssetManager::LoadModelAsset("tileset/Cube.gltf", "Cube");
	AssetManager::LoadTextureAsset("tileset/dummyGrass/grassCenter.png", "Dirt");
	AssetManager::LoadTextureAsset("tileset/dummyGrass/grassMid.png", "Grass");
	Tile::AddTileDef(0, "Dirt");
	Tile::AddTileDef(1, "Grass");

	AssetManager::LoadModelAsset("player/Skeleton.gltf", "Skeleton");
	AssetManager::LoadAnimationAsset("player/Skeleton.gltf", "Skelewalk");
	martinModel.SetModel("Skeleton");
	martinModel.SetAnimation("Skelewalk");
	player.Initialize(5, 0, false, false, "Skeleton");
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
	//DrawModel(player.GetModel().GetModel(), player.GetPosition(), 0.1f, WHITE);
	//DrawModelEx(playerHeadModel.GetModel(), {0, 3, 0 }, { 1.0f, 0.0f, 0.0f }, -270.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
	DrawModelEx(player.GetModel().GetModel(), { 0, 1, 0 }, { 0.0f, 1.0f, 0.0f }, -90.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
	Tile::DrawTile(0, { 0, 0, 0}, 0, 0, 0, 1.0f);
	Tile::DrawTile(0, { 0, 0, 0}, 1, 0, 0, 1.0f);
	Tile::DrawTile(0, { 0, 0, 0}, 1, 1, 0, 1.0f);
	Tile::DrawTile(1, { 0, 0, 0}, 1, 2, 0, 1.0f);
	Tile::DrawTile(1, { 0, 0, 0}, 2, 2, 0, 1.0f);
}

void Gameplay::Update()
{
    player.Update(GetFrameTime());
}

void Gameplay::Cleanup()
{
}