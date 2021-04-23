#pragma once
#include "mdl.h"
#include <map>

using namespace std;

typedef unsigned int uint;

/*
// Tileset Object List (for level editing).
struct TOL
{
    char magic[4];                          // PTOL.
    u32 numObjects;                         // Number of objects used.
    TOL_Object objects[numObjects];         // Objects.

    // An object used, it is padded to 4 bytes.
    struct TOL_Object
    {
        u8 randomizeOffset;                 // First bit is to randomize the tile data instead of use it in the correct order, next is pos or negative, rest are for how much to move up when placing next object.
        u8 width;                           // Width.
        u8 height;                          // Height.
        u8 tileIds[width * height];         // Tile IDs. They are stored left to right, top to bottom.
    };
};
*/

// For drawing tiles on screen.
struct Tile
{

// Private members.
private:
    static map<string, map<uint, string>> tileDefinitions;
    static vector<string> loadedTilesets;
    static Mdl basicCube;
    static bool init;

    static float TILE_SIZE;

// Public members.
public:

    // Add a tile definition.
    static void AddTileDef(string tileset, uint id, string textureName);
    
    // Remove a tile definition.
    static void RemoveTileDef(string tileset, uint id);

    // Draw a given tile ID.
    static void DrawTile(string tileset, uint id, Vector3 tilesOrigin, int x, int y, int z = 0, float scale = 1.0f);

    // Get the available tilesets.
    static char* GetAvailableTilesets();

    // Load a given tileset.
    static void LoadTileset(string tilesetName);

    // Unload a given tileset.
    static void UnloadTileset(string tilesetName);

    // Get the tileset index.
    static int GetTilesetIndex(string tilesetName);

    // Get tileset at tileset index.
    static string GetTilesetAtIndex(int tilesetIndex);

    // Get the list of tiles used for a tileset.
    static vector<string> GetTilesInTileset(string tilesetName);

};

// Collision types.
enum KCL_Types
{
    KCL_TILE_FULL,
    KCL_TILE_TOP,
    KCL_TILE_BOTTOM,
    KCL_TILE_LEFT,
    KCL_TILE_RIGHT,
    KCL_TILE_SOLID_ON_TOP,
    KCL_TILE_SOLID_ON_BOTTOM,
    KCL_TILE_SOLID_ON_LEFT,
    KCL_TILE_SOLID_ON_RIGHT,
    KCL_TILE_SLOPE_45_UR,
    KCL_TILE_SLOPE_45_UL,
    KCL_TILE_SLOPE_45_DR,
    KCL_TILE_SLOPE_45_DL,
    KCL_TILE_SLOPE_23_UR_A1,
    KCL_TILE_SLOPE_23_UR_A2,
    KCL_TILE_SLOPE_23_UL_A1,
    KCL_TILE_SLOPE_23_UL_A2,
    KCL_TILE_SLOPE_23_DR_A1,
    KCL_TILE_SLOPE_23_DR_A2,
    KCL_TILE_SLOPE_23_DL_A1,
    KCL_TILE_SLOPE_23_DL_A2,
    KCL_TILE_SLOPE_11_UR_A1,
    KCL_TILE_SLOPE_11_UR_A2,
    KCL_TILE_SLOPE_11_UR_A3,
    KCL_TILE_SLOPE_11_UR_A4,
    KCL_TILE_SLOPE_11_UL_A1,
    KCL_TILE_SLOPE_11_UL_A2,
    KCL_TILE_SLOPE_11_UL_A3,
    KCL_TILE_SLOPE_11_UL_A4,
    KCL_TILE_SLOPE_11_DR_A1,
    KCL_TILE_SLOPE_11_DR_A2,
    KCL_TILE_SLOPE_11_DR_A3,
    KCL_TILE_SLOPE_11_DR_A4,
    KCL_TILE_SLOPE_11_DL_A1,
    KCL_TILE_SLOPE_11_DL_A2,
    KCL_TILE_SLOPE_11_DL_A3,
    KCL_TILE_SLOPE_11_DL_A4
};