#pragma once
#include <raylib.h>
#include <raymath.h>
#include "mdl.h"

struct Entity;

typedef void(*StateFunction)(Entity* ent);

// Measurement unit, where 0xABCD represents A in tiles (&8 is sign), B in pixels, C in subpixels, and D in subsubpixels. There are 16 subpixels in a pixel, 16 pixels in a block, etc. 0xFFFF is NA.
typedef unsigned short MU;

struct EntityState
{
    StateFunction init = NULL;
    StateFunction main = NULL;
    StateFunction cleanup = NULL;
};

struct Entity 
{
// Physics variables.
private:
    Vector3 position = {0, 0, 0};
    Vector2 velocity = {0, 0};
    Vector2 acceleration = {0, 0};

    Vector2 maxVelocity = {0, 0};

    // Main model for the entity
    Mdl mainModel;

    // State.
    int currentState = -1;

// Getters and setters.
public:
    EntityState* states;

    Vector3& GetPosition();
    Vector2& GetVelocity();
    Vector2& GetAcceleration();
    Mdl& GetModel();

    void SetPosition(Vector3 pos);
    void SetVelocity(Vector2 vel);
    void SetAcceleration(Vector2 acc);
    void SetMaxVelocity(Vector2 max);
    void SetModel(std::string name);

    void UpdatePhysics(float dt);
    void UpdateModel();

    // State functions.
    void InitStates(int numStates);
    void ChangeState(int state);
    void DoState();
    int GetState();

    // Cleanup.
    void Cleanup();

    // Static stuff.
    static float ConvMU(MU m);

};