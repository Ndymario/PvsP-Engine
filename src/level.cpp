#include "level.h"
#include "tile.h"
#include "entity.h"
#include <array>

void PLVL::Read(GFile* f)
{
    f->SetEndian(false);
    if (f->ReadU32() != 'LVLP')
    {
        printf("ERROR: INVALID LEVEL FILE MAGIC!");
        return;
    }
    version = f->ReadU32();
    levelSettings.Read(f);
    numAreas = f->ReadU32();
    areas.reserve(numAreas);
    for (u32 i = 0; i < numAreas; i++)
    {
        areas[i].Read(f);
    }
}

void PLVL::Write(GFile* f)
{
    f->SetEndian(false);
    f->Write((u32)'LVLP'); 
    f->Write(version);
    levelSettings.Write(f);
    f->Write(numAreas);
    for (u32 i = 0; i < numAreas; i++)
    {
        areas[i].Write(f);
    }
}

void PLVL::LVLS::Read(GFile* f)
{
    f->ReadU32();
    isRaceLevel = f->ReadU8();
    timer = f->ReadU16();
    f->ReadU8();
}

void PLVL::LVLS::Write(GFile* f)
{
    f->Write((u32)'SLVL');
    f->Write((u8)isRaceLevel);
    f->Write(timer);
    f->Write((u8)0);
}

void PLVL::AREA::Read(GFile* f)
{
    f->ReadU32();
    id = f->ReadU32();
    for (u8 i = 0; i < 4; i++)
    {
        entranceIDs[i] = f->ReadU8();
    }
    startingZone = f->ReadU8();
    for (u8 i = 0; i < 4; i++)
    {
        tilesets[i] = f->ReadStr();
    }
    for (u8 i = 0; i < 4; i++)
    {
        tileLayers[i].Read(f);
    }
    f->Align(4);
    numZones = f->ReadU32();
    zones.reserve(numZones);
    for (u32 i = 0; i < numZones; i++)
    {
        zones[i].Read(f);
    }
}

void PLVL::AREA::Write(GFile* f)
{
    f->Write((u32)'AERA');
    f->Write(id);
    for (u8 i = 0; i < 4; i++)
    {
        f->Write(entranceIDs[i]);
    }
    f->Write(startingZone);
    for (u8 i = 0; i < 4; i++)
    {
        f->Write(tilesets[i]);
    }
    for (u8 i = 0; i < 4; i++)
    {
        tileLayers[i].Write(f);
    }
    f->Align(4);
    f->Write(numZones);
    for (u32 i = 0; i < numZones; i++)
    {
        zones[i].Write(f);
    }
}

void PLVL::ZONE::Read(GFile* f)
{
    f->ReadU32();
    id = f->ReadU32();
    zoneX = f->ReadU32();
    zoneY = f->ReadU32();
    zoneWidth = f->ReadU32();
    zoneHeight = f->ReadU32();
    cameraZoomMode = f->ReadU8();
    scrollX = f->ReadU8();
    scrollY = f->ReadU8();
    wrapsAroundX = f->ReadU8();
    wrapsAroundY = f->ReadU8();
    layer0Spotlight = f->ReadU8();
    darknessMode = (DarknessMode)f->ReadU8();
    dontDoZoomIntro = f->ReadU8();
    stopCamera = f->ReadU8();
    autoscrollPathID = f->ReadU8();
    centerCameraXOnStart = f->ReadU8();
    backgroundName = f->ReadStr();
    musicName = f->ReadStr();
    sfxTrackName = f->ReadStr();
    f->Align(4);
    numEntrances = f->ReadU32();
    entrances.reserve(numEntrances);
    for (u32 i = 0; i < numEntrances; i++)
    {
        entrances[i].Read(f);
    }
    numPaths = f->ReadU32();
    paths.reserve(numPaths);
    for (u32 i = 0; i < numPaths; i++)
    {
        paths[i].Read(f);
    }
    numLocations = f->ReadU32();
    locations.reserve(numLocations);
    for (u32 i = 0; i < numLocations; i++)
    {
        locations[i].Read(f);
    }
    numSprites = f->ReadU32();
    sprites.reserve(numSprites);
    for (u32 i = 0; i < numSprites; i++)
    {
        sprites[i].Read(f);
    }
}

void PLVL::ZONE::Write(GFile* f)
{
    f->Write((u32)'ENOZ');
    f->Write(id);
    f->Write(zoneX);
    f->Write(zoneY);
    f->Write(zoneWidth);
    f->Write(zoneHeight);
    f->Write(cameraZoomMode);
    f->Write((u8)scrollX);
    f->Write((u8)scrollY);
    f->Write((u8)wrapsAroundX);
    f->Write((u8)wrapsAroundY);
    f->Write((u8)layer0Spotlight);
    f->Write((u8)darknessMode);
    f->Write((u8)dontDoZoomIntro);
    f->Write((u8)stopCamera);
    f->Write(autoscrollPathID);
    f->Write((u8)centerCameraXOnStart);
    f->Write(backgroundName);
    f->Write(musicName);
    f->Write(sfxTrackName);
    f->Align(4);
    f->Write(numEntrances);
    for (u32 i = 0; i < numEntrances; i++)
    {
        entrances[i].Write(f);
    }
    f->Write(numPaths);
    for (u32 i = 0; i < numPaths; i++)
    {
        paths[i].Write(f);
    }
    f->Write(numLocations);
    for (u32 i = 0; i < numLocations; i++)
    {
        locations[i].Write(f);
    }
    f->Write(numSprites);
    for (u32 i = 0; i < numSprites; i++)
    {
        sprites[i].Write(f);
    }
}

void PLVL::SPRT::Read(GFile* f)
{
    f->ReadU32();
    id = f->ReadU32();
    layer = f->ReadU8();
    initialState = f->ReadU8();
    activeIfOffscreen = f->ReadU8();
    respawnable = f->ReadU8();
    xPos = f->ReadU32();
    yPos = f->ReadU32();
    spriteData1 = f->ReadU64();
    spriteData2 = f->ReadU64();
}

void PLVL::SPRT::Write(GFile* f)
{
    f->Write((u32)'TRPS');
    f->Write(id);
    f->Write(layer);
    f->Write(initialState);
    f->Write((u8)activeIfOffscreen);
    f->Write((u8)respawnable);
    f->Write(xPos);
    f->Write(yPos);
    f->Write(spriteData1);
    f->Write(spriteData2);
}

void PLVL::LOCN::Read(GFile* f)
{
    f->ReadU32();
    locationID = f->ReadU32();
    xPos = f->ReadU32();
    yPos = f->ReadU32();
    width = f->ReadU32();
    height = f->ReadU32();
}

void PLVL::LOCN::Write(GFile* f)
{
    f->Write((u32)'NCOL');
    f->Write(locationID);
    f->Write(xPos);
    f->Write(yPos);
    f->Write(width);
    f->Write(height);
}

void PLVL::PATH::Read(GFile* f)
{
    f->ReadU32();
    pathID = f->ReadU8();
    loop = f->ReadU8();
    numNodes = f->ReadU16();
    nodes.reserve(numNodes);
    for (u16 i = 0; i < numNodes; i++)
    {
        nodes[i].xPos = f->ReadU32();
        nodes[i].yPos = f->ReadU32();
        nodes[i].vel = f->ReadU16();
        nodes[i].accel = f->ReadU16();
        nodes[i].delay = f->ReadU32();
    }
}

void PLVL::PATH::Write(GFile* f)
{
    f->Write((u32)'HTAP');
    f->Write(pathID);
    f->Write((u8)loop);
    f->Write(numNodes);
    for (u16 i = 0; i < numNodes; i++)
    {
        f->Write(nodes[i].xPos);
        f->Write(nodes[i].yPos);
        f->Write(nodes[i].vel);
        f->Write(nodes[i].accel);
        f->Write(nodes[i].delay);
    }
}

void PLVL::ENTR::Read(GFile* f)
{
    f->ReadU32();
    mode = (EntranceMode)f->ReadU8();
    entranceID = f->ReadU8();
    destinationID = f->ReadU8();
    destinationArea = f->ReadU8();
    enterable = f->ReadU8();
    autoscrollNodeID = f->ReadU8();
    faceLeft = f->ReadU8();
    transition = (Transition)f->ReadU8();
    xPosition = f->ReadU32();
    yPosition = f->ReadU32();
}

void PLVL::ENTR::Write(GFile* f)
{
    f->Write((u32)'RTNE');
    f->Write((u8)mode);
    f->Write(entranceID);
    f->Write(destinationID);
    f->Write(destinationArea);
    f->Write((u8)enterable);
    f->Write(autoscrollNodeID);
    f->Write((u8)faceLeft);
    f->Write((u8)transition);
    f->Write(xPosition);
    f->Write(yPosition);
}

void PLVL::TILE::Read(GFile* f)
{
    f->ReadU32();
    numTiles = f->ReadU32();
    tiles.reserve(numTiles);
    for (u32 i = 0; i < numTiles; i++)
    {
        tiles[i].tileID = f->ReadU8();
        tiles[i].xPos = f->ReadU32();
        tiles[i].yPos = f->ReadU32();
    }
}

void PLVL::TILE::Write(GFile* f)
{
    f->Write((u32)'ELIT');
    f->Write(numTiles);
    for (u32 i = 0; i < numTiles; i++)
    {
        f->Write(tiles[i].tileID);
        f->Write(tiles[i].xPos);
        f->Write(tiles[i].yPos);
    }
}

PLVL::AREA* PLVL::FindArea(u32 id)
{
    for (u32 i = 0; i < numAreas; i++)
    {
        if (areas[i].id == id)
        {
            return &areas[i];
        }
    }
    return NULL;
}

void PLVL::AddArea(u32 id)
{
    for (u32 i = 0; i < numAreas; i++)
    {
        if (areas[i].id == id)
        {
            return;
        }
    }
    AREA e;
    e.id = id;
    e.AddZone(0);
    areas.insert(areas.end(), e);
    numAreas++;
}

void PLVL::RemoveArea(u32 id)
{
    for (u32 i = 0; i < numAreas; i++)
    {
        if(areas[i].id == id)
        {
            for (u32 j = 0; j < areas[i].numZones; j++)
            {
                areas[i].RemoveZone(areas[i].zones[0].id);
            }
            for (u32 j = 0; j < 4; j++)
            {
                for (u32 k = 0; k < areas[i].tileLayers[j].numTiles; k++)
                {
                    areas[i].tileLayers[j].RemoveTile(areas[i].tileLayers[j].tiles[0].xPos, areas[i].tileLayers[j].tiles[0].yPos);
                }
            }
            areas.erase(areas.begin() + i);
            i--;
            numAreas--;
        }
    }
}

PLVL::ZONE* PLVL::AREA::FindZone(u32 id)
{
    for (u32 i = 0; i < numZones; i++)
    {
        if(zones[i].id == id)
        {
            return &zones[i];
        }
    }
    return NULL;
}

void PLVL::AREA::AddZone(u32 id)
{
    for (u32 i = 0; i < numZones; i++)
    {
        if (zones[i].id == id)
        {
            return;
        }
    }
    ZONE e;
    e.id = id;
    e.AddEntrance(0);
    zones.insert(zones.end(), e);
    numZones++;
}

void PLVL::AREA::RemoveZone(u32 id)
{
    for (u32 i = 0; i < numZones; i++)
    {
        if(zones[i].id == id)
        {
            for (u32 j = 0; j < zones[i].numEntrances; j++)
            {
                zones[i].RemoveEntrance(zones[i].entrances[0].entranceID);
            }
            for (u32 j = 0; j < zones[i].numLocations; j++)
            {
                zones[i].RemoveLocation(zones[i].locations[0].locationID);
            }
            for (u32 j = 0; j < zones[i].numPaths; j++)
            {
                zones[i].RemovePath(zones[i].paths[0].pathID);
            }
            for (u32 j = 0; j < zones[i].numSprites; j++)
            {
                zones[i].RemoveSprite(zones[i].sprites[0].xPos, zones[i].sprites[0].yPos);
            }
            zones.erase(zones.begin() + i);
            i--;
            numZones--;
        }
    }
}

PLVL::ENTR* PLVL::ZONE::FindEntrance(u8 id)
{
    for (u8 i = 0; i < numEntrances; i++)
    {
        if(entrances[i].entranceID == id)
        {
            return &entrances[i];
        }
    }
    return NULL;
}

void PLVL::ZONE::AddEntrance(u8 id)
{
    for (u8 i = 0; i < numEntrances; i++)
    {
        if (entrances[i].entranceID == id)
        {
            return;
        }
    }
    ENTR e;
    e.entranceID = id;
    entrances.insert(entrances.end(), e);
    numEntrances++;
}

void PLVL::ZONE::RemoveEntrance(u8 id)
{
    for (u8 i = 0; i < numEntrances; i++)
    {
        if(entrances[i].entranceID == id)
        {
            entrances.erase(entrances.begin() + i);
            i--;
            numEntrances--;
        }
    }
}

PLVL::PATH* PLVL::ZONE::FindPath(u8 id)
{
    for (u8 i = 0; i < numPaths; i++)
    {
        if(paths[i].pathID == id)
        {
            return &paths[i];
        }
    }
    return NULL;
}

void PLVL::ZONE::AddPath(u8 id)
{
    for (u8 i = 0; i < numPaths; i++)
    {
        if (paths[i].pathID == id)
        {
            return;
        }
    }
    PATH e;
    e.pathID = id;
    paths.insert(paths.end(), e);
    numPaths++;
}

void PLVL::ZONE::RemovePath(u8 id)
{
    for (u8 i = 0; i < numPaths; i++)
    {
        if(paths[i].pathID == id)
        {
            for (u32 j = 0; j < paths[i].numNodes; j++)
            {
                paths[i].RemoveNode(paths[i].nodes[0].id);
            }
            paths.erase(paths.begin() + i);
            i--;
            numPaths--;
        }
    }
}

PLVL::LOCN* PLVL::ZONE::FindLocation(u32 id)
{
    for (u32 i = 0; i < numLocations; i++)
    {
        if(locations[i].locationID == id)
        {
            return &locations[i];
        }
    }
    return NULL;
}

void PLVL::ZONE::AddLocation(u32 id)
{
    for (u32 i = 0; i < numLocations; i++)
    {
        if (locations[i].locationID == id)
        {
            return;
        }
    }
    LOCN e;
    e.locationID = id;
    locations.insert(locations.end(), e);
    numLocations++;
}

void PLVL::ZONE::RemoveLocation(u32 id)
{
    for (u32 i = 0; i < numLocations; i++)
    {
        if(locations[i].locationID == id)
        {
            locations.erase(locations.begin() + i);
            i--;
            numLocations--;
        }
    }
}

PLVL::SPRT* PLVL::ZONE::FindSprite(EMU xPos, EMU yPos)
{
    for (u32 i = 0; i < numSprites; i++)
    {
        if (sprites[i].xPos == xPos && sprites[i].yPos == yPos)
        {
            return &sprites[i];
        }
    }
    return NULL;
}

void PLVL::ZONE::AddSprite(u32 id, EMU xPos, EMU yPos)
{
    numSprites++;
    SPRT s;
    s.id = id;
    s.xPos = xPos;
    s.yPos = yPos;
    sprites.insert(sprites.end(), s);
}

void PLVL::ZONE::RemoveSprite(EMU xPos, EMU yPos)
{
    for (u32 i = 0; i < numSprites; i++)
    {
        if (sprites[i].xPos == xPos && sprites[i].yPos == yPos)
        {
            u32 ind = i;
            sprites.erase(sprites.begin() + ind);
            numSprites--;
        }
    }
}

PLVL::PATH::PathNode* PLVL::PATH::FindNode(u32 id)
{
    for (u16 i = 0; i < numNodes; i++)
    {
        if(nodes[i].id == id)
        {
            return &nodes[i];
        }
    }
    return NULL;
}

void PLVL::PATH::AddNode(u32 id, EMU xPos, EMU yPos, MU vel, MU accel, u32 delay)
{
    for (u16 i = 0; i < numNodes; i++)
    {
        if (nodes[i].id == id)
        {
            return;
        }
    }
    nodes.insert(nodes.end(), PathNode { id, xPos, yPos, vel, accel, delay });
    numNodes++;
}

void PLVL::PATH::RemoveNode(u32 id)
{
    for (u16 i = 0; i < numNodes; i++)
    {
        if(nodes[i].id == id)
        {
            nodes.erase(nodes.begin() + i);
            i--;
            numNodes--;
        }
    }
}

PLVL::TILE::TileDef* PLVL::TILE::FindTile(u16 xPos, u16 yPos)
{
    for (u32 i = 0; i < numTiles; i++)
    {
        if (tiles[i].xPos == xPos && tiles[i].yPos == yPos)
        {
            return &tiles[i];
        }
    }
    return NULL;
}

void PLVL::TILE::AddTile(u8 id, u16 xPos, u16 yPos)
{ 
    TileDef t;
    t.tileID = id;
    t.xPos = xPos;
    t.yPos = yPos;
    tiles.insert(tiles.end(), t);
    numTiles++;
}

void PLVL::TILE::RemoveTile(u16 xPos, u16 yPos)
{
    for (u32 i = 0; i < numTiles; i++)
    {
        if (tiles[i].xPos == xPos && tiles[i].yPos == yPos)
        {
            u32 ind = i;
            tiles.erase(tiles.begin() + ind);
            i--;
            numTiles--;
        }
    }
}

PLVL::PLVL()
{
    AddArea(0);
}

PLVL::~PLVL()
{
    for (u32 i = 0; i < numAreas; i++)
    {
        RemoveArea(areas[0].id);
    }
}

void PLVL::DrawTiles(TileLayer layer, float scale)
{
    AREA* a = FindArea(currAreaID);
    if (a == NULL) { return; }
    TILE* t = &a->tileLayers[layer];
    for (u32 i = 0; i < t->numTiles; i++)
    {
        Tile::DrawTile(a->tilesets[layer], t->tiles[i].tileID, { offset.x, offset.y , 0 }, t->tiles[i].xPos, t->tiles[i].yPos, 0, scale); // TODO!!! Z!!!
    }
}