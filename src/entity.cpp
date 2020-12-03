/*
Main contributors to this file: Nolan Y?

Bug fixers: [None, yet]
*/

#include <raylib.h>

// Physics Object struct
struct PhysicsObject
{
    // Declare the object's postion, velocity, and acceleration
    // Initalize each var to (0, 0)
    Vector2 pos = { 0, 0 };
    Vector2 vel = { 0, 0 };
    Vector2 accel = { 0, 0 };
};

// Player Struct
struct Player : PhysicsObject
{
    // Declare and initalize the player's special properties.
    int playerPowerState = 0;
    bool isJumping = false;
    bool isRunning = false;
    bool isSkidding = false;
    bool isGroundPounding = false;
    bool isSpinning = false;
    bool isWalljumping = false;
    bool isAttacking = false;
    bool isDead = false;
    bool isTransitioning = false;
    bool isStomped = false;
    bool isInvincible = false;
    bool isHurt = false;
};

// Entity Structs
struct BigStar : PhysicsObject
{
    // Declare and initalize the Big Star's special properties
    int starID = 0;
    bool wasCollected = false;
};

struct Goomba : PhysicsObject
{
    // Declare and initalize the Goomba's special properties
    bool isStomped = false;
    bool isFacingRight = false;
};

struct Koopa : PhysicsObject
{
    // Declare and initalize the Koopa's special properties
    int shellType = 0;
    bool isStomped = false;
    bool isFacingRight = false;
    bool wasThrown = false;

};

struct BulletBill : PhysicsObject
{
    // Declare and initalize the Bullet Bill's special properties
    bool isStomped = false;
    bool isFacingRight = false;
};

struct PiranhaPlant : PhysicsObject
{
    // Declare and initalize the Piranha Plant's special properties
    bool isStomped = false;
    bool isInPipe = false;
};

struct Bobomb : PhysicsObject
{
    // Declare and initalize the Bobomb's special properties
    bool isStomped = false;
    int fuseTimer = 500;
};

struct StoneWall
{
    // Declare and initalize the Stone Wall's special properties
    int width = 0;
    int height = 0;
};

struct FireBall : PhysicsObject
{
    // Declare the Fire Ball's special properties
    int playerNumber = 0;
};


// Powerup Structs
struct Mushroom : PhysicsObject
{
    // Declare and initalize the Mushroom's special properties
    int powerupValue = 0;
    bool isEvil = false;
};

struct FireFlower : PhysicsObject
{
    // Declare and initalize the Fire Flower's special properties
    int powerupValue = 1;
};

struct BlueShell : PhysicsObject
{
    // Declare and initalize the Blue Shell's special properties
    int powerupValue = 2;
};

struct MiniMushroom : PhysicsObject
{
    // Declare and initalize the Mini Mushroom's special properties
    int powerupValue = 3;
};

struct SuperStar : PhysicsObject
{
    // Declare and initalize the Super Star's special properties
    int powerupValue = 4;
};

struct MegaMushroom : PhysicsObject
{
    // Declare and initalize the Fire Flower's special properties
    int powerupValue = 5;
};