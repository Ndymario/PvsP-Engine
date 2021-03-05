#pragma once
#include <raylib.h>
#include <raymath.h>
#include "mdl.h"

struct Entity;

typedef void(*StateFunction)(Entity* ent);

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

// Getters and setters.
public:
    int currentState = -1;
    StateFunction* stateFunctions;

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

    void InitStates(int numStates);
    void DoState();

    void Cleanup();
};