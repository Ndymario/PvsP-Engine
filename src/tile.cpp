#include "tile.h"
#include "assetManager.h"

map<uint, string> Tile::tileDefinitions;
Mdl Tile::basicCube;
bool Tile::init = false;
float Tile::TILE_SIZE = 2.01f;

void Tile::AddTileDef(uint id, string textureName)
{
    tileDefinitions[id] = textureName;
}

void Tile::RemoveTileDef(uint id)
{
    tileDefinitions.erase(id);
}

void Tile::DrawTile(uint id, Vector3 tilesOrigin, int x, int y, int z, float scale)
{
    if (!init)
    {
        basicCube.SetModel("Cube");
        init = true;
    }
    basicCube.SetTexture(tileDefinitions[id], 0, MAP_DIFFUSE);
    DrawModel(basicCube.GetModel(), { tilesOrigin.x + TILE_SIZE * x * scale, tilesOrigin.y + TILE_SIZE * y * scale, tilesOrigin.z + TILE_SIZE * z * scale }, scale, WHITE);
}