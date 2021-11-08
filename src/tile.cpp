#include "tile.h"
#include "assetManager.h"
#include <string.h>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

map<string, map<uint, string>> Tile::tileDefinitions;
vector<string> Tile::loadedTilesets;
Mdl Tile::basicCube;
bool Tile::init = false;
float Tile::TILE_SIZE = 1.999f;

void Tile::AddTileDef(string tileSet, uint id, string textureName)
{
    tileDefinitions[tileSet][id] = textureName;
}

void Tile::RemoveTileDef(string tileSet, uint id)
{
    tileDefinitions[tileSet].erase(id);
    if (tileDefinitions.size() == 0) { tileDefinitions.erase(tileSet); }
}

void Tile::DrawTile(string tileSet, uint id, Vector3 tilesOrigin, int x, int y, int z, float scale)
{
    if (!init)
    {
        basicCube.SetModel("Cube");
        init = true;
    }
    basicCube.SetTexture(tileDefinitions[tileSet][id], 0, MATERIAL_MAP_DIFFUSE);
    DrawModel(basicCube.GetModel(), { tilesOrigin.x + TILE_SIZE * x * scale, tilesOrigin.y + TILE_SIZE * y * scale, tilesOrigin.z + TILE_SIZE * z * scale }, scale, WHITE);
}

char* Tile::GetAvailableTilesets()
{
    int allocSize = 0;
    for (int i = 0; i < loadedTilesets.size(); i++)
    {
        allocSize += loadedTilesets[i].size() + 1;
    }
    char* tilesets = (char*)malloc(allocSize);
    int ind = 0;
    for (int i = 0; i < loadedTilesets.size(); i++)
    {
        for (int j = 0; j < loadedTilesets[i].size(); j++)
        {
            tilesets[ind++] = loadedTilesets[i][j];
        }
        tilesets[ind++] = 0;
    }
    return tilesets;
}

void Tile::LoadTileset(string tileset)
{
    if (loadedTilesets.size() == 0)
    {
        AssetManager::LoadModelAsset("tileset/Cube.gltf", "Cube");
    }
    for (uint i = 0; i < loadedTilesets.size(); i++)
    {
        if (strcmp(loadedTilesets[i].c_str(), tileset.c_str()) == 0)
        {
            return;
        }
    }
    string path = string(GetWorkingDirectory()) + "/assets/tileset/" + tileset;
    vector<string> files;
    for (const auto & entry : fs::directory_iterator(path))
    {
        files.push_back(entry.path().string());
    }
    std::sort(files.begin(), files.end(), std::less<std::string>());
    for (uint i = 0; i < files.size(); i++)
    {
        string file = GetFileName(files[i].c_str());
        string name = GetFileNameWithoutExt(files[i].c_str());
        tileDefinitions[tileset][i] = tileset + "_" + name;
        AssetManager::LoadTextureAsset("tileset/" + tileset + "/" + file, tileset + "_" + name);
    }
    loadedTilesets.push_back(tileset);
}

void Tile::UnloadTileset(string tileset)
{
    string path = string(GetWorkingDirectory()) + "/assets/tileset/" + tileset;
    vector<string> files;
    for (const auto & entry : fs::directory_iterator(path))
    {
        files.push_back(entry.path().string());
    }
    for (uint i = 0; i < files.size(); i++)
    {
        string name = GetFileNameWithoutExt(files[i].c_str());
        tileDefinitions[tileset].erase(i);
        AssetManager::UnloadTextureAsset(tileset + "_" + name);
    }
    for (uint i = 0; i < loadedTilesets.size(); i++)
    {
        if (strcmp(loadedTilesets[i].c_str(), tileset.c_str()) == 0)
        {
            loadedTilesets.erase(loadedTilesets.begin() + i);
            break;
        }
    }
    if (loadedTilesets.size() == 0)
    {
        AssetManager::UnloadModelAsset("Cube");
    }
}

int Tile::GetTilesetIndex(string tilesetName)
{
    if (strcmp(tilesetName.c_str(), "") == 0) { return 0; }
    for (int i = 0; i < loadedTilesets.size(); i++)
    {
        if (strcmp(tilesetName.c_str(), loadedTilesets[i].c_str()) == 0)
        {
            return i;
        }
    }
    return 0;
}

string Tile::GetTilesetAtIndex(int tilesetIndex)
{
    if (tilesetIndex >= 0 && tilesetIndex < loadedTilesets.size())
    {
        return loadedTilesets[tilesetIndex];
    }
    return loadedTilesets[0];
}

vector<string> Tile::GetTilesInTileset(string tilesetName)
{
    string path = string(GetWorkingDirectory()) + "/assets/tileset/" + tilesetName;
    vector<string> files;
    for (const auto & entry : fs::directory_iterator(path))
    {
        files.push_back(tilesetName + "_" + GetFileNameWithoutExt(entry.path().string().c_str()));
    }
    std::sort(files.begin(), files.end(), std::less<std::string>());
    return files;
}