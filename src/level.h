#pragma once
#include <string>
#include "gbin/gtypes.h"
#include "entity.h"

using namespace std;

// Tile layers.
enum TileLayer : s32
{
    LAYER_COLLISION,
    LAYER_2,
    LAYER_1,
    LAYER_0
};

//PvsP LeVeL Specification (PLVL):
struct PLVL : public GReadable, public GWriteable
{

    // LeVeL Settings.
    struct LVLS : public GReadable, public GWriteable
    {
        bool isClassicLevel = false;            // If the level is a classic level with a flagpole ending.
        u16 timer = 400;                        // If it is a classic level, how much time to give the player(s).
        u8 pad = 0;                             // General purpose padding.

        // Read and write functions.
        void Read(GFile* f);
        void Write(GFile* f);  
    };

    // TILE block.
    struct TILE : public GReadable, public GWriteable
    {
        struct TileDef
        {
            u8 tileID = 0;                      // Tile ID.
            u16 xPos = 0;                       // X position.
            u16 yPos = 0;                       // Y position.
        };
        u32 numTiles = 0;                       // How many tiles.
        vector<TileDef> tiles;                     // Tiles to use.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);

        // Tiles.
        TileDef* FindTile(u16 xPos, u16 yPos);
        void AddTile(u8 id, u16 xPos, u16 yPos);
        void RemoveTile(u16 xPos, u16 yPos);

    };

    // Zone darkness mode.
    enum DarknessMode : s32
    {
        DARKNESS_NONE,
        DARKNESS_NO_SPOT,
        DARKNESS_SMALL_SPOT,
        DARKNESS_LARGE_SPOT
    };

    // How to enter.
    enum EntranceMode : u8
    {
        ENTRANCE_NORMAL
    };

    // Transition to use.
    enum Transition : u8
    {
        TRANSITION_JUMPCUT
    };

    // ENTRances.
    struct ENTR : public GReadable, public GWriteable
    {
        EntranceMode mode = ENTRANCE_NORMAL;    // How the player should enter.
        u8 entranceID = 0;                      // ID of the entrance.
        u8 destinationID = 0;                   // Destination ID of the entrance.
        u8 destinationArea = 0;                 // Destination area.
        bool enterable = false;                 // If you can go through the entrance.
        u8 autoscrollNodeID = 0xFF;             // Which node to start the autoscroll if the zone uses autoscroll. 0xFF otherwise.
        bool faceLeft = false;                  // Face the player left.
        Transition transition = TRANSITION_JUMPCUT; // Transition to use when exiting. The inverse is played for entering.
        EMU xPosition = 0;                      // X position.
        EMU yPosition = 0;                      // Y position.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);
    };

    // A PATH.
    struct PATH : public GReadable, public GWriteable
    {
        // A path node.
        struct PathNode
        {
            u32 id;                             // Path ID.
            EMU xPos = 0;                       // X position.
            EMU yPos = 0;                       // Y position.
            MU vel = 0;                         // Velocity. (NA to not set).
            MU accel = 0;                       // Acceleration. (NA to not set).
            u32 delay = 0;                      // Delay in frames.
        };
        u8 pathID = 0;                          // Path ID.
        bool loop = false;                      // If the path loops.
        u16 numNodes = 0;                       // Number of paths.
        vector<PathNode> nodes;                 // Path nodes.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);

        // Path nodes.
        PathNode* FindNode(u32 id);
        void AddNode(u32 id, EMU xPos, EMU yPos, MU vel, MU accel, u32 delay);
        void RemoveNode(u32 id);
    };

    // LOCatioN.
    struct LOCN : public GReadable, public GWriteable
    {
        u32 locationID = 0;                     // Location ID.
        EMU xPos = 0;                           // X position.
        EMU yPos = 0;                           // Y position.
        EMU width = 0;                          // Width.
        EMU height = 0;                         // Height.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);
    };

    // SPRiTe.
    struct SPRT : public GReadable, public GWriteable
    {
        u32 id = 0;                             // Sprite ID.
        u8 layer = 1;                           // Layer to put on (0-2).
        u8 initialState = 0;                    // What state to initially set too.
        bool activeIfOffscreen = false;         // Is active offscreen.
        bool respawnable = true;                // Can respawn this when killed.
        EMU xPos = 0;                           // X position.
        EMU yPos = 0;                           // Y position.
        u64 spriteData1 = 0;                    // Sprite data.
        u64 spriteData2 = 0;                    // More sprite data.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);
    };

    // ZONE area.
    struct ZONE : public GReadable, public GWriteable
    {
        u32 id = 0;                             // Zone ID.
        EMU zoneX = 0;                          // Zone X position.
        EMU zoneY = 0;                          // Zone Y position.
        EMU zoneWidth = 0x1000;                 // Zone width.
        EMU zoneHeight = 0x1000;                // Zone height.
        u8 cameraZoomMode = 0;                  // TODO!!!
        bool scrollX = true;                    // Allow the camera to move in the X direction.
        bool scrollY = true;                    // Allow the camera to move in the Y direction.
        bool wrapsAroundX = false;              // If the zone wraps around such that once the player reaches a side on the X axis, they will come out the other.
        bool wrapsAroundY = false;              // Like the above, but for the Y axis.
        bool layer0Spotlight = true;            // Use a spotlight in layer 0.
        DarknessMode darknessMode = DARKNESS_NONE;  // Darkness mode.
        bool dontDoZoomIntro = false;           // Don't zoom when entering zone, have camera in correct place.
        bool stopCamera = true;                 // Camera is not allowed to go beyond the end of a zone.
        u8 autoscrollPathID = 0xFF;             // If the zone is autoscroll, have it follow a path if this value is not 255.
        bool centerCameraXOnStart = false;      // If to center the camera X when entering.
        string backgroundName = "";             // Background name.
        string musicName = "";                  // Music name.
        string sfxTrackName = "";               // Name for the SFX background track ("" if none), padded to 4 bytes.
        u32 numEntrances = 0;                   // Number of entrances.
        vector<ENTR> entrances;                 // Entrances.
        u32 numPaths = 0;                       // Number of paths.
        vector<PATH> paths;                     // Paths.
        u32 numLocations = 0;                   // Number of locations.
        vector<LOCN> locations;                 // Locations.
        u32 numSprites = 0;                     // Number of sprites.
        vector<SPRT> sprites;                   // Sprites.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);

        // Items.
        ENTR* FindEntrance(u8 id);
        void AddEntrance(u8 id);
        void RemoveEntrance(u8 id);
        PATH* FindPath(u8 id);
        void AddPath(u8 id);
        void RemovePath(u8 id);
        LOCN* FindLocation(u32 id);
        void AddLocation(u32 id);
        void RemoveLocation(u32 id);
        SPRT* FindSprite(EMU xPos, EMU yPos);
        void AddSprite(u32 id, EMU xPos, EMU yPos);
        void RemoveSprite(EMU xPos, EMU yPos);
    };

    // AREA settings.
    struct AREA : public GReadable, public GWriteable
    {
        u32 id = 0;                             // Area ID.
        u8 entranceIDs[4] = { 0, 0, 0, 0 };     // Entrance IDs for all 4 players.
        u8 startingZone = 0;                    // Which zone to start in.
        string tilesets[4] = { "", "", "", "" };// Tilesets to use for the area, one for each zone. "" is no tileset, and this last value is padded to 4 bytes.
        TILE tileLayers[4];                     // Collision tiles, Layer 2 tiles, Layer 1 tiles, Layer 0 tiles. Padded to 4 bytes.
        u32 numZones = 0;                       // How many zones to have.
        vector<ZONE> zones;                     // Zones.

        // Read and write the data.
        void Read(GFile* f);
        void Write(GFile* f);

        // Zone stuff.
        ZONE* FindZone(u32 id);
        void AddZone(u32 id);
        void RemoveZone(u32 id);
    };

    // General variables.
    u32 version = 0;                            // Specifies the version.
    LVLS levelSettings;                         // Level settings.
    u32 numAreas = 0;                           // Number of areas.
    vector<AREA> areas;                         // Actual areas.

    // Read and write the data.
    void Read(GFile* f);
    void Write(GFile* f);    

    // Area settings.
    AREA* FindArea(u32 id);
    void AddArea(u32 id);
    void RemoveArea(u32 id);

    // Contructor destructor stuff.
    PLVL();
    ~PLVL();

    // Level management stuff.
    u32 currAreaID = 0;
    Vector2 offset = { 0.0f, 0.0f };
    void DrawTiles(TileLayer layer, float scale = 1.0f);

};

/*

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

};*/