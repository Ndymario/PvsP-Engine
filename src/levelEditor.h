#pragma once
#include "level.h"
#include "scene.h"
#include "rlImGui/fileBrowser.h"

enum GridView {
	GRID_NONE,
	GRID_LINES,
	GRID_TILES
};

struct LevelEditor : public Scene
{

	// Editor data.
    PLVL lvl;
	bool showZones = true;
	imgui_addons::ImGuiFileBrowser file_dialog;
	GridView grid;
	TileLayer paintMode = LAYER_1;
	vector<string> tilenameSets[4];

	// To implement.
	void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void DrawImGui();
	void Update();
	void Cleanup();

	// Level editor stuff.
	void DrawToolbox(bool& isWindowFocused);
	void DrawZoneInfo(PLVL::AREA* area);
	
};

struct SortByAreaID
{
   bool const operator() (const PLVL::AREA& L, const PLVL::AREA& R) { return L.id < R.id; }
};

struct SortByZoneID
{
   bool const operator() (const PLVL::ZONE& L, const PLVL::ZONE& R) { return L.id < R.id; }
};