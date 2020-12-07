#include "player.h"
#include "playerStates.h"

void Player::Initialize(int startingLives, int initPowerUp, bool startFacingLeft, bool playerTwo)
{
    lives = startingLives;
    powerState = initPowerUp;
    isFacingLeft = startFacingLeft;
    isPlayerTwo = playerTwo;

    SetModel("MarioBig");
    if (startFacingLeft) 
    {
        GetModel().Rotate({90, 180, 0});
    }
    else 
    {
        GetModel().Rotate({90, 0, 0});
    }

    SetMaxVelocity({4.5f, 0});
    accelRate = 15.0f; // p/s^2
    deaccelRate = 20.0f; // p/s^2

    currentState = &PlayerIdleState::get_instance();
    currentState->Start(this);
}

void Player::changeState(PlayerState& state)
{
    currentState->End(this);
    currentState = &state;
    currentState->Start(this);
}

void Player::Update(float dt)
{
    currentState->Execute(this);

    if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_A))
    {
        changeState(PlayerIdleState::get_instance());
    }
    if (IsKeyPressed(KEY_D))
    {   
        isFacingLeft = false;
        changeState(PlayerWalkState::get_instance());
    }
    if (IsKeyPressed(KEY_A))
    {
        isFacingLeft = true;
        changeState(PlayerWalkState::get_instance());
    }

    UpdatePhysics(dt);
    UpdateModel();
}