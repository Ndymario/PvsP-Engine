#include "player.h"
#include "input.h"

bool Player::PlayerPhysicsInitialized;
PlayerPhysics Player::MartinPhysics;

void Player::Initialize(int startingLives, int initPowerUp, bool startFacingLeft, int playerId, string modelName)
{

    // Player physics.
    if (!PlayerPhysicsInitialized)
    {
        MartinPhysics.MaxWalkXVel = { (MU)0x0140, { (MU)0x0140, (MU)0x0140 }, { (MU)0x0180, (MU)0x0110 }, { (MU)0x0240, (MU)0x00F0 }, { (MU)0x0240, (MU)0xFFFF } };
        MartinPhysics.MaxRunXVel = { (MU)0x0240, { (MU)0x0240, (MU)0x0240 }, { (MU)0x0240, (MU)0x01F0 }, { (MU)0x0240, (MU)0x01B0 }, { (MU)0x0240, (MU)0xFFFF } };
        MartinPhysics.MaxSprintXVel = { (MU)0x0300, { (MU)0x0300, (MU)0x0300 }, { (MU)0x0300, (MU)0xFFFF }, { (MU)0x0300, (MU)0xFFFF }, { (MU)0x0300, (MU)0xFFFF } };
        PlayerPhysicsInitialized = true;
    }

    // Init stats.
    lives = startingLives;
    powerState = initPowerUp;
    isFacingLeft = startFacingLeft;
    this->playerId = playerId;

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
    states[PLAYER_IDLE].main = PlayerIdleMain;
    states[PLAYER_WALK].main = PlayerWalkMain;

}

void Player::Update(float dt)
{
    DoState();

    if ((Input::ButtonReleased("Right", playerId) || Input::ButtonReleased("Left", playerId)) &&\
    Input::ButtonUp("Right", playerId) && Input::ButtonUp("Left", playerId))
    {
        ChangeState(PLAYER_IDLE);
    }
    if (Input::ButtonPressed("Right", playerId))
    {   
        isFacingLeft = false;
        ChangeState(PLAYER_WALK);
    }
    if (Input::ButtonPressed("Left", playerId))
    {
        isFacingLeft = true;
        ChangeState(PLAYER_WALK);
    }

    UpdatePhysics(dt);
    UpdateModel();
}

void PlayerIdleMain(Entity* ent)
{
    Player* p = (Player*)ent;
    p->SetVelocity({ 0.0f, 0 });
}

void PlayerWalkMain(Entity* ent)
{
    Player* p = (Player*)ent;
    p->SetVelocity({ 30.0f * p->isFacingLeft ? -1.0f : 1.0f, 0 });
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