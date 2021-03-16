#include "levelEditor.h"
#include "assetManager.h"
#include "tile.h"
#include "input.h"
#include <imgui.h>

void LevelEditor::Initialize()
{

    // Camera stuff.
    camera.position = {0.0f, 0.0f, 15.0f}; // Camera position.
	camera.target = {0.0f, 0.0f, 0.0f};    // Camera looking at point.
	camera.up = {0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target).
	camera.fovy = 35.0f;                   // Camera field-of-view Y.
	camera.type = CAMERA_ORTHOGRAPHIC;     // Camera mode type.

    // Dummy tileset.
    AssetManager::LoadModelAsset("tileset/Cube.gltf", "Cube");
	AssetManager::LoadTextureAsset("tileset/dummyGrass/grassCenter.png", "Dirt");
	AssetManager::LoadTextureAsset("tileset/dummyGrass/grassMid.png", "Grass");
	Tile::AddTileDef(0, "Dirt");
	Tile::AddTileDef(1, "Grass");
    lvl.offset.y = -.8f;
    lvl.areas[0].tileLayers[LAYER_1].AddTile(0, 0, 0);
    lvl.areas[0].tileLayers[LAYER_1].AddTile(0, 1, 0);
    lvl.areas[0].tileLayers[LAYER_1].AddTile(0, 2, 0);
    lvl.areas[0].tileLayers[LAYER_1].AddTile(0, 3, 0);
    lvl.areas[0].tileLayers[LAYER_1].AddTile(1, 0, 1);
    lvl.areas[0].tileLayers[LAYER_1].AddTile(1, 1, 1);
    lvl.areas[0].tileLayers[LAYER_1].AddTile(1, 2, 1);

}

void LevelEditor::DrawBackground2D()
{
}

void LevelEditor::DrawForeground2D()
{
}

void LevelEditor::Draw3D()
{
	lvl.DrawTiles(LAYER_1);
}

void LevelEditor::DrawImGui()
{

    // Main level editor.
    bool enableInput = true;
    ImGui::Begin("Level Editor");
    if (ImGui::IsWindowFocused())
    {
        enableInput = false;
    }
    ImGui::DragFloat2("Level Offset", (float*)&lvl.offset, 1.0f, -1000.0f, 1000.0f, "%f", 1.0f);
	ImGui::End();

    // Scrollbar X.
    ImGui::Begin("##ScrollX", NULL, ImGuiWindowFlags_NoTitleBar);
    ImGui::DragFloat("##ScrollXControl", &lvl.offset.x, 1.0f, -1000.0f, 1000.f, "%f", 1.0f);
    ImGui::End();

    // Scrollbar Y.

    // Input.
    Input::enabled = enableInput;

}

void LevelEditor::Update()
{
}

void LevelEditor::Cleanup()
{
}