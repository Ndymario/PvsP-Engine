#include "entity.h"

// T for FPS.
const float FPS_FACTOR = 30.0f;

// Magical conversion constant.
const float MU_2_FLOAT = 0.0004880371094f; // TILE_SIZE (1.999) / MU's per block (0x1000).

Vector3& Entity::GetPosition()
{
    return position;
}

MU Entity::GetPositionX()
{
    return ConvFloat(position.x);
}

MU Entity::GetPositionY()
{
    return ConvFloat(position.y);
}

Vector2& Entity::GetVelocity()
{
    return velocity;
}

MU Entity::GetVelocityX()
{
    return ConvFloat(velocity.x / FPS_FACTOR);
}

MU Entity::GetVelocityY()
{
    return ConvFloat(velocity.y / FPS_FACTOR);
}

Vector2& Entity::GetAcceleration()
{
    return acceleration;
}

MU Entity::GetAccelerationX()
{
    return ConvFloat(acceleration.x / FPS_FACTOR / FPS_FACTOR);
}

MU Entity::GetAccelerationY()
{
    return ConvFloat(acceleration.y / FPS_FACTOR / FPS_FACTOR);
}

Mdl& Entity::GetModel()
{
    return mainModel;
}

void Entity::SetPosition(Vector3 pos)
{
    position = pos;
}

void Entity::SetPositionX(MU m)
{
    position.x = ConvMU(m);
}

void Entity::SetPositionY(MU m)
{
    position.y = ConvMU(m);
}

void Entity::SetVelocity(Vector2 vel)
{
    velocity = vel;
}

void Entity::SetVelocityX(MU m)
{
    velocity.x = ConvMU(m) * FPS_FACTOR;
}

void Entity::SetVelocityY(MU m)
{
    velocity.y = ConvMU(m) * FPS_FACTOR;
}

void Entity::SetAcceleration(Vector2 acc)
{
    acceleration = acc;
}

void Entity::SetAccelerationX(MU m)
{
    acceleration.x = ConvMU(m) * FPS_FACTOR * FPS_FACTOR;
}

void Entity::SetAccelerationY(MU m)
{
    acceleration.y = ConvMU(m) * FPS_FACTOR * FPS_FACTOR;
}

void Entity::SetMaxVelocity(Vector2 max)
{
    maxVelocity = max;
}

void Entity::SetMaxVelocityX(MU m)
{
    maxVelocity.x = ConvMU(m) * FPS_FACTOR;
}

void Entity::SetMaxVelocityY(MU m)
{
    maxVelocity.y = ConvMU(m) * FPS_FACTOR;
}

void Entity::SetModel(std::string name)
{
    mainModel.SetModel(name);
}

void Entity::UpdatePhysics(float dt)
{
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;
    
    if (velocity.x >= maxVelocity.x)
    {
        velocity.x = maxVelocity.x;
    }
    if (velocity.x <= -maxVelocity.x)
    {
        velocity.x = -maxVelocity.x;
    }
    if (velocity.y >= maxVelocity.y)
    {
        velocity.y = maxVelocity.y;
    }
    if (velocity.y <= -maxVelocity.y)
    {
        velocity.y = -maxVelocity.y;
    }

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

}

void Entity::UpdateModel()
{
    mainModel.Update();
}

void Entity::InitStates(int numStates)
{
    states = new EntityState[numStates];
}

void Entity::ChangeState(int state)
{
    if (currentState != -1 && states[currentState].cleanup != NULL) { doCleanupFrame = true; }
    prevState = currentState;
    currentState = state;
    if (currentState != -1 && states[currentState].init != NULL) { doInitFrame = true; }
}

void Entity::DoState()
{
    if (doCleanupFrame)
    {
        states[prevState].cleanup(this);
        doCleanupFrame = false;
    }
    if (doInitFrame)
    {
        states[currentState].init(this);
        doInitFrame = false;
        return;
    }
    if (currentState == -1 || states[currentState].main == NULL) { return; }
    states[currentState].main(this);
}

void Entity::Cleanup()
{
    delete[] states;
}

int Entity::GetState()
{
    return currentState;
}

int Entity::GetPrevState()
{
    return prevState;
}

float Entity::ConvMU(MU m)
{
    float ret = NAN;
    if (m != 0xFFFF)
    {
        ret = (m & 0x8000) ? (-1.0 * MU_2_FLOAT * (m & 0x7FFF)) : (1.0 * MU_2_FLOAT * (m & 0x7FFF));
    }
    return ret;
}

MU Entity::ConvFloat(float f)
{
    MU ret = 0xFFFF;
    if (f != NAN)
    {
        ret = abs(f) * (1.0f / MU_2_FLOAT);
        if (f < 0.0f) { ret |= 0x8000; }
    }
    return ret;
}