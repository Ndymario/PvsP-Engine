#include "player.h"

void Player::Initialize(int startingLives, int initPowerUp, bool startFacingLeft, bool playerTwo, string modelName)
{

    // Init stats.
    lives = startingLives;
    powerState = initPowerUp;
    isFacingLeft = startFacingLeft;
    isPlayerTwo = playerTwo;

    // Setup model.
    SetModel(modelName);
    GetModel().Rotate({ 0, -90, 0 });
    if (startFacingLeft) 
    {
        GetModel().Rotate({0, 90, 0});
    }
    else 
    {
        GetModel().Rotate({0, -90, 0});
    }

    // Physic.
    SetMaxVelocity({4.5f, 0});
    accelRate = 15.0f; // p/s^2
    deaccelRate = 20.0f; // p/s^2

    // Set up all the state and state pointers.
    InitStates(NUM_PLAYER_STATES);
    stateFunctions[PLAYER_IDLE] = PlayerIdle;
    stateFunctions[PLAYER_WALK] = PlayerWalk;

}

void Player::Update(float dt)
{
    DoState();

    if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_A))
    {
        currentState = PLAYER_IDLE;
    }
    if (IsKeyPressed(KEY_D))
    {   
        isFacingLeft = false;
        currentState = PLAYER_WALK;
    }
    if (IsKeyPressed(KEY_A))
    {
        isFacingLeft = true;
        currentState = PLAYER_WALK;
    }

    UpdatePhysics(dt);
    UpdateModel();
}

void PlayerIdle(Entity* ent)
{
    Player* p = (Player*)ent;
}

void PlayerWalk(Entity* ent)
{
    Player* p = (Player*)ent;
}

/*
#pragma once
#include "player.h"
#include "playerState.h"

struct PlayerIdleState : public PlayerState
{
    void Start(Player* player)
    {
        player->GetModel().SetAnimation("Skelewalk");
        player->SetAcceleration({(player->isFacingLeft ? 1 : -1) * player->deaccelRate, 0.0f});
    }

    void Execute(Player* player)
    {
        if (abs(player->GetVelocity().x) <= 1.0f)
        {
            player->SetAcceleration({0.0f, 0.0f});
            player->SetVelocity({0.0, 0.0});
        }
    }

    void End(Player* player)
    {
    }

    static PlayerIdleState& get_instance()
    {
        static PlayerIdleState instance;
        return instance;
    }
};

struct PlayerWalkState : public PlayerState
{
    void Start(Player* player)
    {
        if (player->isFacingLeft) 
        {
            player->GetModel().Rotate({0, 180, 0});
        }
        else 
        {
            player->GetModel().Rotate({0, 180, 0});
        }
        player->SetAcceleration({-(player->isFacingLeft ? 1 : -1) * player->accelRate, 0.0f});
        player->GetModel().SetAnimation("Skelewalk");
    }

    void Execute(Player* player)
    {
    }

    void End(Player* player)
    {
    }

    static PlayerWalkState& get_instance()
    {
        static PlayerWalkState instance;
        return instance;
    }
};*/