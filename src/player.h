#pragma once
#include "entity.h"

// States the player can take.
enum PlayerStates {
    PLAYER_IDLE,
    PLAYER_WALK,
    NUM_PLAYER_STATES
};

// Player physics. Speeds are in MUs/frame, and accelerations are in MUs/frame^2.
struct PlayerPhysics
{

    // For going up or down a slope.
    struct UpDownCombo
    {
        MU Down;
        MU Up;
    };

    // For travelling in the X direction.
    struct XPhys
    {
        MU FlatSpeed;
        UpDownCombo Slope11Deg;
        UpDownCombo Slope23Deg;
        UpDownCombo Slope45Deg;
        UpDownCombo Slope67Deg;
    };

    // Jump physics.
    struct JumpPhys
    {
        MU XVel;
        MU FirstFrameJumpY;
        MU FirstFrameSpinjumpY;
    };

    // Movement in X direction.
    XPhys MaxWalkXVel;
    XPhys MaxRunXVel;
    XPhys MaxSprintXVel;
    XPhys WalkRunXAccel;
    XPhys StoppingXDecel;
    XPhys SkidWalkXDecel;
    XPhys SkidRunXDecel;
    XPhys NaturalXVel;
    XPhys SlidingXAccel;
    XPhys MaxSlidingXVel;
    XPhys WalkIceXAccel;
    XPhys RunIceXAccel;
    XPhys StoppingIceXDecel;
    XPhys SkidWalkIceXDecel;
    XPhys SkidRunIceXDecel;
    XPhys MaxWalkUnderwaterXVel;
    XPhys WalkUnderwaterXAccel;
    XPhys StoppingUnderwaterXDecel;
    XPhys SkidWalkUnderwaterXDecel;
    XPhys NaturalUnderwaterXVel;

    // Jump physics.
    JumpPhys* JumpPhysics; // Each X velocity is the miniumum needed to have that jump speed.
    MU GravityBYVel;
    MU GravityNoBYVel;
    MU TerminalYVel;
    MU AirForwardXAccel;
    MU AirBackwardXAccel;
    MU AirRunBkXAccel;
    
    // Climbing.
    MU ClimbingXVel;
    MU ClimbingYVel;

};

// The controllable player.
struct Player : Entity
{
    // Define some player states
    int lives = 0;
    int powerState = 0;
    int playerId;
    bool isFacingLeft = false;

    // Movement variables
    float maxSpeed;
    float accelRate;
    float deaccelRate;

    // Player specific.
    static bool PlayerPhysicsInitialized;
    static PlayerPhysics MartinPhysics;

    // Basic actions
    void Initialize(int lives, int initPowerUp, bool startFacingLeft, int playerId, string modelName);
    void Update(float dt);

};

// States.
void PlayerIdleMain(Entity* ent);
void PlayerWalkMain(Entity* ent);