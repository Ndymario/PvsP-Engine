#include "entity.h"

Vector3& Entity::GetPosition()
{
    return position;
}

Vector2& Entity::GetVelocity()
{
    return velocity;
}

Vector2& Entity::GetAcceleration()
{
    return acceleration;
}

Mdl& Entity::GetModel()
{
    return mainModel;
}

void Entity::SetPosition(Vector3 pos)
{
    position = pos;
}

void Entity::SetVelocity(Vector2 vel)
{
    velocity = vel;
}

void Entity::SetAcceleration(Vector2 acc)
{
    acceleration = acc;
}

void Entity::SetMaxVelocity(Vector2 max)
{
    maxVelocity = max;
}

void Entity::SetModel(std::string name)
{
    mainModel.SetModel(name);
}

void Entity::UpdatePhysics(float dt)
{
    velocity.x += acceleration.x * dt;
    position.x += velocity.x * dt;
    
    if (velocity.x >= maxVelocity.x)
    {
        velocity.x = maxVelocity.x;
    }
    if (velocity.x <= -maxVelocity.x)
    {
        velocity.x = -maxVelocity.x;
    }
}

void Entity::UpdateModel()
{
    mainModel.Update();
}

/*
// Entity Structs
struct BigStar : Entity
{
    // Declare and initalize the Big Star's special properties
    int starID = 0;
    bool wasCollected = false;
};

struct Goomba : Entity
{
    // Declare and initalize the Goomba's special properties
    bool isStomped = false;
    bool isFacingRight = false;
};

struct Koopa : Entity
{
    // Declare and initalize the Koopa's special properties
    int shellType = 0;
    bool isStomped = false;
    bool isFacingRight = false;
    bool wasThrown = false;
};

struct BulletBill : Entity
{
    // Declare and initalize the Bullet Bill's special properties
    bool isStomped = false;
    bool isFacingRight = false;
};

struct PiranhaPlant : Entity
{
    // Declare and initalize the Piranha Plant's special properties
    bool isStomped = false;
    bool isInPipe = false;
};

struct Bobomb : Entity
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

struct FireBall : Entity
{
    // Declare the Fire Ball's special properties
    int playerNumber = 0;
};

// Powerup Structs
struct Mushroom : Entity
{
    // Declare and initalize the Mushroom's special properties
    int powerupValue = 0;
    bool isEvil = false;
};

struct FireFlower : Entity
{
    // Declare and initalize the Fire Flower's special properties
    int powerupValue = 1;
};

struct BlueShell : Entity
{
    // Declare and initalize the Blue Shell's special properties
    int powerupValue = 2;
};

struct MiniMushroom : Entity
{
    // Declare and initalize the Mini Mushroom's special properties
    int powerupValue = 3;
};

struct SuperStar : Entity
{
    // Declare and initalize the Super Star's special properties
    int powerupValue = 4;
};

struct MegaMushroom : Entity
{
    // Declare and initalize the Fire Flower's special properties
    int powerupValue = 5;
};*/