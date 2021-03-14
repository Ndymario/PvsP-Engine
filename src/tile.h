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
    static map<uint, string> tileDefinitions;
    static Mdl basicCube;
    static bool init;

    static float TILE_SIZE;

// Public members.
public:

    // Add a tile definition.
    static void AddTileDef(uint id, string textureName);
    
    // Remove a tile definition.
    static void RemoveTileDef(uint id);

    // Draw a given tile ID.
    static void DrawTile(uint id, Vector3 tilesOrigin, int x, int y, int z = 0, float scale = 1.0f);

};