#pragma once
#include "entity.h"
#include "mdl.h"
#include "input.h"
#include "playerState.h"

struct PlayerState;

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

    // Current player states
    PlayerState* currentState;
    void changeState(PlayerState& state);
    //void changeState(PlayerState* state);

    // Basic actions
    void Initialize(int lives, int initPowerUp, bool startFacingLeft, bool playerTwo);
    void Update(float dt);
};