#pragma once

// For managing tiles.
struct TileGrid
{

};

// Level.
struct Level
{

    TileGrid collTiles; // Collision layer.
    TileGrid bgTiles; // Layer 2.
    TileGrid mTiles; // Layer 1.
    TileGrid fgTiles; // Layer 0.

    void Draw();
    void Update();

};