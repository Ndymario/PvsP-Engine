#include "levelEditor.h"
#include "assetManager.h"
#include "tile.h"
#include "input.h"
#include <imgui.h>
#include "rlImGui/utils.h"
#include "rlImGui/rlImGui.h"

void LevelEditor::Initialize()
{

    // Camera stuff.
    camera.position = {0.0f, 0.0f, 15.0f}; // Camera position.
	camera.target = {0.0f, 0.0f, 0.0f};    // Camera looking at point.
	camera.up = {0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target).
	camera.fovy = 35.0f;                   // Camera field-of-view Y.
	camera.projection = CAMERA_ORTHOGRAPHIC;     // Camera mode type.

    // Tilesets.
    Tile::LoadTileset("KCL");
    Tile::LoadTileset("Overworld");
    lvl.FindArea(0)->tilesets[LAYER_1] = "Overworld";
    lvl.FindArea(0)->tilesets[LAYER_COLLISION] = "KCL";
    lvl.offset.y = -.8f;
    PLVL::TILE* tiles = &lvl.FindArea(0)->tileLayers[LAYER_1];
    tiles->AddTile(4, 0, 0);
    tiles->AddTile(5, 1, 0);
    tiles->AddTile(6, 2, 0);
    tiles->AddTile(7, 3, 0);
    tiles->AddTile(0, 0, 1);
    tiles->AddTile(1, 1, 1);
    tiles->AddTile(2, 2, 1);
    tiles->AddTile(3, 3, 1);
    tilenameSets[LAYER_1] = Tile::GetTilesInTileset("Overworld");
    tilenameSets[LAYER_COLLISION] = Tile::GetTilesInTileset("KCL");

}

void LevelEditor::DrawBackground2D()
{
}

void LevelEditor::DrawForeground2D()
{
    if (grid == GRID_LINES)
    {
        
    }
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
    ImGui::DragFloat("Zoom", &camera.fovy, 1, 1, 200, "%f", 1.0f);
    ImGui::SameLine();
    if (ImGui::Button("Reset##Zoom"))
    {
        camera.fovy = 35.0f;
    }
    ImGuiTooltip("Controls the orthographic camera FOV.");
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
                    /*if (ImGui::Combo("Collision Tileset", &tilesetIndices[LAYER_COLLISION], tilesets, IM_ARRAYSIZE(tilesets)))
                    {
                        area->tilesets[LAYER_COLLISION] = Tile::GetTilesetAtIndex(tilesetIndices[LAYER_COLLISION]);
                    }
                    ImGuiTooltip("Which tileset to use for displaying the collision if show collision in debug options is enabled.\nNote that this does not change collision behavior.");*/
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

    // Toolbox.
    DrawToolbox(enableInput);

    // Input.
    Input::enabled = enableInput;

}

void LevelEditor::DrawToolbox(bool& isWindowFocused)
{
    ImGui::Begin("Toolbox");
    if (ImGui::IsWindowFocused())
    {
        isWindowFocused = false;
    }
    if (ImGui::BeginTabBar("ToolboxMode"))
    {
        if (ImGui::BeginTabItem("Tilesets"))
        {

            // Paint layer.
            ImGui::Text("Paint Layer:");
            ImGuiTooltip("What layer to paint on.\n0 is the foreground layer.\n1 is the interactive/player level layer.\n2 is the background layer.\nC is the collision layer.");
            ImGui::RadioButton("0", (s32*)&paintMode, LAYER_0);
            ImGui::SameLine();
            ImGui::RadioButton("1", (s32*)&paintMode, LAYER_1);
            ImGui::SameLine();
            ImGui::RadioButton("2", (s32*)&paintMode, LAYER_2);
            ImGui::SameLine();
            ImGui::RadioButton("C", (s32*)&paintMode, LAYER_COLLISION); 
            
            // Get tileset selecting info.
            static s64 tileSize = 48;
            ImGui::SameLine();
            ImGuiNumEdit("Tile Size##Selector", tileSize, 1, 200);
            ImGuiTooltip("Size to preview tiles in the toolbox.");
            ImVec2 tileSizeVec = ImVec2(tileSize, tileSize);
            s32 tilesPerRow = (s32)(ImGui::GetWindowContentRegionWidth() / (tileSize + ImGui::GetStyle().FramePadding.x * 1.5)) - 1;
            s32 lineCtr = 0;
            for (s32 i = 0; i < tilenameSets[paintMode].size(); i++)
            {
                ImGui::Image(&AssetManager::GetTexture(tilenameSets[paintMode][i]), tileSizeVec);
                lineCtr++;
                if (lineCtr > tilesPerRow)
                {
                    lineCtr = 0;
                }
                else
                {
                    ImGui::SameLine();
                }
            }

            //Finish.
            ImGui::EndTabItem();

        }
        ImGui::EndTabBar();
    }
    ImGui::End();
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