#include "entity.h"

// Magical conversion constant.
const float MU_2_FLOAT = 0.0004880371094f; // TILE_SIZE (1.999) / MU's per block (0x1000).

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

void Entity::InitStates(int numStates)
{
    states = new EntityState[numStates];
}

void Entity::ChangeState(int state)
{
    if (currentState != -1 && states[currentState].cleanup != NULL) { states[currentState].cleanup(this); }
    currentState = state;
    if (currentState != -1 && states[currentState].init != NULL) { states[currentState].init(this); }
}

void Entity::DoState()
{
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

float Entity::ConvMU(MU m)
{
    float ret = NAN;
    if (m != 0xFFFF)
    {
        ret = (m & 0x8000) ? (-1.0 * MU_2_FLOAT * (m & 0x7FFF)) : (1.0 * MU_2_FLOAT * (m & 0x7FFF));
    }
    return ret;
}