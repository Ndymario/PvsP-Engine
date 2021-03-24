#pragma once
#include "mdl.h"
#include <map>

using namespace std;

typedef unsigned int uint;

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