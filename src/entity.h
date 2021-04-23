#pragma once
#include <raylib.h>
#include <raymath.h>
#include "mdl.h"
#include "gbin/types.h"
#include "level.h"
#include "mu.h"

struct Entity;

typedef void(*StateFunction)(Entity* ent);

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
    Vector2 maxVelocity = {0, 0};
    Vector2 acceleration = {0, 0};

    // State.
    int currentState = -1;
    std::vector<int> cleanupStack;
    bool doInitFrame = false;
    bool doCleanupFrame = false;

    // Main model for the entity
    Mdl mainModel;

    // Collision funcs.
    void UpdateCollision(float dt);
    bool CollidesWith(Entity& other);
    PLVL::TILE::TileDef* CollidesWithTile(PLVL::AREA* area, u16 tileX, u16 tileY);
    void CollisionTileResponse(PLVL::AREA* area, PLVL::TILE::TileDef* tile);
    void CollisionEjectPlayer(Rectangle kickOutFrom, bool canMoveUp, bool canMoveDown, bool canMoveLeft, bool canMoveRight);

// Getters and setters.
public:
    EntityState* states;
    bool collisionEnabled = false;
    Rectangle boundingBox;
    Vector2 pastBoundingPos;

    // Collision flags.
    bool resolvedUp = false;
    bool resolvedDown = false;
    bool resolvedLeft = false;
    bool resolvedRight = false;

    Vector3& GetPosition();
    MU GetPositionX();
    MU GetPositionY();
    Vector2& GetVelocity();
    MU GetVelocityX();
    MU GetVelocityY();
    Vector2& GetAcceleration();
    MU GetAccelerationX();
    MU GetAccelerationY();
    Mdl& GetModel();

    void SetPosition(Vector3 pos);
    void SetPositionX(MU m);
    void SetPositionY(MU m);
    void SetVelocity(Vector2 vel);
    void SetVelocityX(MU m);
    void SetVelocityY(MU m);
    void SetAcceleration(Vector2 acc);
    void SetAccelerationX(MU m);
    void SetAccelerationY(MU m);
    void SetMaxVelocity(Vector2 max);
    void SetMaxVelocityX(MU m);
    void SetMaxVelocityY(MU m);
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
    static MU ConvFloat(float f);
    static float ConvEMU(EMU e);
    static EMU ConvFloatE(float f);

};