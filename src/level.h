#pragma once
#include <string>

using namespace std;

// For managing tiles.
struct TileGrid
{
    struct GridItem
    {
        unsigned char ID;
        unsigned short X;
        unsigned short Y;
    };
    GridItem* items;
    unsigned int numItems;
};

// Level.
struct Level
{

    TileGrid collTiles; // Collision layer.
    TileGrid bgTiles; // Layer 2.
    TileGrid mTiles; // Layer 1.
    TileGrid fgTiles; // Layer 0.

    Level(string filePath);
    void Draw();
    void Update();
    void SaveLeve(string filePath);

};