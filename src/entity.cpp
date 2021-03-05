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

void Entity::InitStates(int numStates)
{
    stateFunctions = new StateFunction[numStates];
}

void Entity::DoState()
{
    if (currentState == -1) { return; }
    stateFunctions[currentState](this);
}

void Entity::Cleanup()
{
    delete[] stateFunctions;
}