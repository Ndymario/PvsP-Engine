#include "gameplay.h"
#include <assetManager.h>
#include "input.h"
#include "tile.h"
#include "imgui.h"

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
	camera.projection = CAMERA_ORTHOGRAPHIC;     // Camera mode type

	Tile::LoadTileset("KCL");
    Tile::LoadTileset("Overworld");
	lvl.FindArea(0)->tilesets[LAYER_1] = "Overworld";
	lvl.offset.y = -0.8f - 10 * 1.999f;
	lvl.offset.x = -15 * 1.999f;
	PLVL::TILE* tiles = &lvl.FindArea(0)->tileLayers[LAYER_1];
	for (int i = 0; i < 30; i++)
	{
		tiles->AddTile(std::rand() % 4, i, 10);
		for (int j = 0; j <= 9; j++)
		{
			tiles->AddTile(std::rand() % 4 + 4, i, j);
		}
	}

	AssetManager::LoadModelAsset("player/Skeleton.gltf", "Skeleton");
	AssetManager::LoadModelAsset("player/Brobot.gltf", "Brobot");
	//AssetManager::LoadAnimationAsset("player/Skeleton.gltf", "Skelewalk");
	player.Initialize(5, 0, false, 0, "Brobot");
	player.GetModel().Scale({ 10.0f, 10.0f, 10.0f });
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
	DrawModelEx(player.GetModel().GetModel(), player.GetPosition(), { 0.0f, 1.0f, 0.0f }, -90.0f, { 0.1f, 0.1f, 0.1f }, WHITE);
	lvl.DrawTiles(LAYER_1);
}

void Gameplay::DrawImGui()
{
	ImGui::Begin("Player Stats");
	ImGui::SliderFloat("X Position", &player.GetPosition().x, -27.5f, 27.5f);
	ImGui::SliderFloat("Y Position", &player.GetPosition().y, -27.5f, 27.5f);
	ImGui::SliderFloat("Z Position", &player.GetPosition().z, -27.5f, 27.5f);
	ImGui::SliderFloat("X Velocity", &player.GetVelocity().x, -100.0f, 100.0f);
	ImGui::SliderFloat("Y Velocity", &player.GetVelocity().y, -100.0f, 100.0f);
	ImGui::SliderFloat("X Acceleration", &player.GetAcceleration().x, -100.0f, 100.0f);
	ImGui::SliderFloat("Y Acceleration", &player.GetAcceleration().y, -100.0f, 100.0f);
	ImGui::End();
}

void Gameplay::Update()
{
	//player.GetModel().Rotate({ 0, 1, 0 });
    player.Update(GetFrameTime());
}

void Gameplay::Cleanup()
{
}