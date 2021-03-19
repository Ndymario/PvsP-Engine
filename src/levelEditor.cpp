#include "levelEditor.h"
#include "assetManager.h"
#include "tile.h"
#include "input.h"
#include <imgui.h>
#include "rlImGui/utils.h"

void LevelEditor::Initialize()
{

    // Camera stuff.
    camera.position = {0.0f, 0.0f, 15.0f}; // Camera position.
	camera.target = {0.0f, 0.0f, 0.0f};    // Camera looking at point.
	camera.up = {0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target).
	camera.fovy = 35.0f;                   // Camera field-of-view Y.
	camera.projection = CAMERA_ORTHOGRAPHIC;     // Camera mode type.

    // Dummy tileset.
    Tile::LoadTileset("dummyGrass");
    Tile::LoadTileset("dummyGrass2");
    AssetManager::LoadTextureAsset("PhysicsChart.png", "Phys");
    lvl.FindArea(0)->tilesets[LAYER_1] = "dummyGrass";
    lvl.offset.y = -.8f;
    PLVL::TILE* tiles = &lvl.FindArea(0)->tileLayers[LAYER_1];
    tiles->AddTile(0, 0, 0);
    tiles->AddTile(0, 1, 0);
    tiles->AddTile(0, 2, 0);
    tiles->AddTile(0, 3, 0);
    tiles->AddTile(1, 0, 1);
    tiles->AddTile(1, 1, 1);
    tiles->AddTile(1, 2, 1);

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

    // Demo for reference.
    ImGui::ShowDemoWindow();

    // Main level editor.
    bool enableInput = true;
    ImGui::Begin("Level Editor");
    if (ImGui::IsWindowFocused())
    {
        enableInput = false;
    }
    
    // Level offset.
    ImGui::DragFloat2("Level Offset", (float*)&lvl.offset, 1.0f, -1000.0f, 1000.0f, "%f", 1.0f);
    ImGuiTooltip("To see other parts of the level when editing.");

    // Level settings.
    ImGui::Checkbox("Classic Level", &lvl.levelSettings.isClassicLevel);
    ImGuiTooltip("If the level is a classic one where there is a time limit to complete the goal.");
    if(lvl.levelSettings.isClassicLevel)
    {
        ImGui::SameLine();
        ImGui::SetNextItemWidth(50.0f);
        ImGui::InputScalar("Timer Settings", ImGuiDataType_U16, &lvl.levelSettings.timer);
        ImGuiTooltip("How many game seconds to give the player to complete the level.");
    }
    //ImGui::Image((void*)&AssetManager::GetTexture("Phys"), ImVec2(AssetManager::GetTexture("Phys").width, AssetManager::GetTexture("Phys").height));

    // Manage current areas.
    static s64 areaId = 0;
    ImGuiNumEdit("AreaSelector", areaId, 0, 0xFFFFFFFF);
    ImGui::SameLine();
    if (ImGui::Button("Add Area"))
    {
        if (lvl.FindArea(areaId) == NULL)
        {
            lvl.AddArea(areaId);
            std::sort(lvl.areas.begin(), lvl.areas.end(), SortByAreaID());
        }
    }
    if (lvl.numAreas > 1)
    {
        ImGui::SameLine();
        if(ImGui::Button("Remove Area"))
        {
            lvl.RemoveArea(areaId);
        }
    }
    ImGuiTooltip("Add or remove the given area ID from the level.");
    

    // Area listing.
    if (ImGui::BeginTabBar("Areas"), ImGuiTabBarFlags_Reorderable) {
        for (u32 i = 0; i < lvl.numAreas; i++)
        {
            if (ImGui::BeginTabItem(((string)"Area " + to_string(lvl.areas[i].id)).c_str()))
            {
                PLVL::AREA* area = lvl.FindArea(lvl.areas[i].id);
                if (ImGui::CollapsingHeader("Area Settings")) {
                    int tilesetIndices[4] = { Tile::GetTilesetIndex(area->tilesets[LAYER_COLLISION]), Tile::GetTilesetIndex(area->tilesets[LAYER_2]), Tile::GetTilesetIndex(area->tilesets[LAYER_1]), Tile::GetTilesetIndex(area->tilesets[LAYER_0]) };
                    char* tilesets = Tile::GetAvailableTilesets();
                    if (ImGui::Combo("Collision Tileset", &tilesetIndices[LAYER_COLLISION], tilesets, IM_ARRAYSIZE(tilesets)))
                    {
                        area->tilesets[LAYER_COLLISION] = Tile::GetTilesetAtIndex(tilesetIndices[LAYER_COLLISION]);
                    }
                    ImGuiTooltip("Which tileset to use for displaying the collision if show collision in debug options is enabled.\nNote that this does not change collision behavior.");
                    if (ImGui::Combo("Layer 2 Tileset", &tilesetIndices[LAYER_2], tilesets, IM_ARRAYSIZE(tilesets)))
                    {
                        area->tilesets[LAYER_2] = Tile::GetTilesetAtIndex(tilesetIndices[LAYER_2]);
                    }
                    ImGuiTooltip("Which tileset to use for the background layer.");
                    if (ImGui::Combo("Layer 1 Tileset", &tilesetIndices[LAYER_1], tilesets, IM_ARRAYSIZE(tilesets)))
                    {
                        area->tilesets[LAYER_1] = Tile::GetTilesetAtIndex(tilesetIndices[LAYER_1]);
                    }
                    ImGuiTooltip("Which tileset to use for the interactive layer.");
                    if (ImGui::Combo("Layer 0 Tileset", &tilesetIndices[LAYER_0], tilesets, IM_ARRAYSIZE(tilesets)))
                    {
                        area->tilesets[LAYER_0] = Tile::GetTilesetAtIndex(tilesetIndices[LAYER_0]);
                    }
                    ImGuiTooltip("Which tileset to use for the foreground layer.");
                    free(tilesets);
                    // TODO: AREA ID!
                    // TODO: ENTRANCE IDS!
                    // TODO: STARTING ZONE!
                }
                DrawZoneInfo(area);
                ImGui::EndTabItem();
            }
        }
        ImGui::EndTabBar();
    }
	ImGui::End();

    // Scrollbar X.
    ImGui::Begin("##ScrollX", NULL, ImGuiWindowFlags_NoTitleBar);
    ImGui::DragFloat("##ScrollXControl", &lvl.offset.x, 1.0f, -1000.0f, 1000.f, "%f", 1.0f);
    ImGui::End();

    // Scrollbar Y.

    // Input.
    Input::enabled = enableInput;

}

void LevelEditor::DrawZoneInfo(PLVL::AREA* area)
{

    // Zone adder.
    static s64 zoneId = 0;
    ImGuiNumEdit("ZoneSelector", zoneId, 0, 0xFFFFFFFF);
    ImGui::SameLine();
    if (ImGui::Button("Add Zone"))
    {
        if (area->FindZone(zoneId) == NULL)
        {
            area->AddZone(zoneId);
            std::sort(area->zones.begin(), area->zones.end(), SortByZoneID());
        }
    }
    if (area->numZones > 1)
    {
        ImGui::SameLine();
        if(ImGui::Button("Remove Zone"))
        {
            area->RemoveZone(zoneId);
        }
    }
    ImGuiTooltip("Add or remove the given zone ID from the area.");

    // Show zones.
    if (ImGui::BeginTabBar("Zones"), ImGuiTabBarFlags_Reorderable) {
        for (u32 i = 0; i < area->numZones; i++)
        {
            if (ImGui::BeginTabItem(((string)"Zone " + to_string(area->zones[i].id)).c_str()))
            {
                PLVL::ZONE* zone = area->FindZone(i);
                if (ImGui::CollapsingHeader("Zone Settings"))
                {
                    ImGui::Checkbox("Show Zones In Editor", &showZones);
                    ImGuiTooltip("Preview zones on the level view.");
                    // TODO: ZONE DIMENSIONS!!!
                    // TODO: CAMERA ZOOM MODE!!!
                    ImGui::Checkbox("Scroll X", &zone->scrollX);
                    ImGuiTooltip("Enable camera scrolling in the X direction.");
                    ImGui::SameLine();
                    ImGui::Checkbox("Scroll Y", &zone->scrollY);
                    ImGuiTooltip("Enable camera scrolling in the Y direction.");
                    ImGui::Checkbox("Wraps Around X", &zone->wrapsAroundX);
                    ImGuiTooltip("If the player tries to go to the edge of the zone, they will appear on the other side in the X direction.");
                    ImGui::SameLine();
                    ImGui::Checkbox("Wraps Around Y", &zone->wrapsAroundY);
                    ImGuiTooltip("If the player tries to go to the edge of the zone, they will appear on the other side in the Y direction.");
                    ImGui::Checkbox("Layer 0 Spotlight", &zone->layer0Spotlight);
                    ImGuiTooltip("If the player goes behind a layer 0 tile, show a spotlight through so you can see the player.");
                    const char* darknessModes[] = { "No Darkness", "Pitch Black", "Small Light On Player", "Big Light On Player" };
                    ImGui::Combo("Darkness Mode", (int*)&zone->darknessMode, darknessModes, IM_ARRAYSIZE(darknessModes));
                    ImGuiTooltip("How dark the zone environment should be.");
                    ImGui::Checkbox("Don't Do Camera Zoom Intro", &zone->dontDoZoomIntro);
                    ImGuiTooltip("When entering the zone, don't have the camera initially zoom in or out.");
                    ImGui::SameLine();
                    ImGui::Checkbox("Stop Camera", &zone->stopCamera);
                    ImGuiTooltip("Do not let the camera go outside of the zone.");
                    // TODO: AUTOSCROLL PATH ID!!!
                    ImGui::Checkbox("Center Camera X On Enter", &zone->centerCameraXOnStart);
                    ImGuiTooltip("Center the X position of the camera when entering the zone.");
                    ImGuiStringEdit("Background Name", &zone->backgroundName);
                    ImGuiTooltip("Name of the background model to use for the zone.");
                    ImGuiStringEdit("Music Track Name", &zone->musicName);
                    ImGuiTooltip("Name of the song to use for the zone.");
                    ImGuiStringEdit("SFX Track Name", &zone->sfxTrackName);
                    ImGuiTooltip("Name of sfx sounds to play in the background of the zone.");
                }
                if (ImGui::BeginTabBar("ZoneStuff"))
                {
                    if (ImGui::BeginTabItem("Entrances"))
                    {
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("Paths"))
                    {
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("Locations"))
                    {
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("Sprites"))
                    {
                        ImGui::EndTabItem();
                    }
                    ImGui::EndTabBar();
                }
                ImGui::EndTabItem();
            }
        }
        ImGui::EndTabBar();
    }

}

void LevelEditor::Update()
{
}

void LevelEditor::Cleanup()
{
}