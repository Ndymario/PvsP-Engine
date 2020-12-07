#pragma once
#include "player.h"

struct Player;

struct PlayerState
{
    // To be implemented
    virtual void Start(Player* player) = 0;
    virtual void Execute(Player* player) = 0;
    virtual void End(Player* player) = 0;
};