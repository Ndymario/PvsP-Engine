#pragma once
#include "entity.h"

// States the player can take.
enum PlayerStates {
    PLAYER_IDLE,
    PLAYER_WALK,
    NUM_PLAYER_STATES
};

// The controllable player.
struct Player : Entity
{
    // Define some player states
    int lives = 0;
    int powerState = 0;
    bool isPlayerTwo = false;
    bool isFacingLeft = false;

    // Movement variables
    float maxSpeed;
    float accelRate;
    float deaccelRate;

    // Basic actions
    void Initialize(int lives, int initPowerUp, bool startFacingLeft, bool playerTwo, string modelName);
    void Update(float dt);

};

// States.
void PlayerIdle(Entity* ent);
void PlayerWalk(Entity* ent);