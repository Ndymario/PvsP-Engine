#include "player.h"
#include "input.h"
#include "screen.h"

bool Player::PlayerPhysicsInitialized = false;
PlayerPhysics Player::MartinPhysics;

void Player::Initialize(int startingLives, int initPowerUp, bool startFacingLeft, int playerId, string modelName)
{

    // Player physics.
    if (!PlayerPhysicsInitialized)
    {
        MartinPhysics.MaxWalkXVel = { (MU)0x0140, { (MU)0x0140, (MU)0x0140 }, { (MU)0x0180, (MU)0x0110 }, { (MU)0x0240, (MU)0x00F0 }, { (MU)0x0240, (MU)0xFFFF } };
        MartinPhysics.MaxRunXVel = { (MU)0x0240, { (MU)0x0240, (MU)0x0240 }, { (MU)0x0240, (MU)0x01F0 }, { (MU)0x0240, (MU)0x01B0 }, { (MU)0x0240, (MU)0xFFFF } };
        MartinPhysics.MaxSprintXVel = { (MU)0x0300, { (MU)0x0300, (MU)0x0300 }, { (MU)0x0300, (MU)0xFFFF }, { (MU)0x0300, (MU)0xFFFF }, { (MU)0x0300, (MU)0xFFFF } };
        // TODO!!!
        MartinPhysics.JumpPhysics = new PlayerPhysics::JumpPhys[1];
        MartinPhysics.JumpPhysics[0].XVel = 0;
        MartinPhysics.JumpPhysics->FirstFrameJumpY = 0x4D0;
        MartinPhysics.JumpPhysics->FirstFrameSpinjumpY = 0x470;
        MartinPhysics.NumJumpPhysics = 1;
        // TODO!!!
        MartinPhysics.GravityBYAccel = 0x8030;
        MartinPhysics.GravityNoBYAccel = 0x8060;
        MartinPhysics.TerminalYVel = 0x400;
        // TODO!!!
        PlayerPhysicsInitialized = true;
    }

    // Init stats.
    lives = startingLives;
    powerState = initPowerUp;
    isFacingLeft = startFacingLeft;
    this->playerId = playerId;
    physics = MartinPhysics;

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
    states[PLAYER_JUMP].init = PlayerJumpInit;
    states[PLAYER_JUMP].main = PlayerJumpMain;
}

void Player::Update(float dt)
{
    if (GetState() != PLAYER_JUMP && (Input::ButtonReleased("Right", playerId) || Input::ButtonReleased("Left", playerId)) &&\
    Input::ButtonUp("Right", playerId) && Input::ButtonUp("Left", playerId))
    {
        ChangeState(PLAYER_IDLE);
    }
    if (GetState() != PLAYER_JUMP && Input::ButtonPressed("Right", playerId))
    {   
        isFacingLeft = false;
        ChangeState(PLAYER_WALK);
    }
    if (GetState() != PLAYER_JUMP && Input::ButtonPressed("Left", playerId))
    {
        isFacingLeft = true;
        ChangeState(PLAYER_WALK);
    }
    if (GetState() != PLAYER_JUMP && Input::ButtonPressed("Jump", playerId))
    {
        ChangeState(PLAYER_JUMP);
    }
    DoState();
    UpdatePhysics(dt);
    if (GetPosition().x < -27.5f)
    {
        SetPosition({ -27.5f, GetPosition().y, GetPosition().z });
    } else if (GetPosition().x > 27.5f)
    {
        SetPosition({ 27.5f, GetPosition().y, GetPosition().z });
    }
    UpdateModel();
}

int Player::DetermineJumpTableIndex()
{
    int ind = -1;
    for (int i = 0; i < physics.NumJumpPhysics; i++)
    {
        if (physics.JumpPhysics[i].XVel <= (ConvFloat(GetVelocity().x) & 0x7FFF))
        {
            ind = i;
        }
        else
        {
            break;
        }
    }
    return ind;
}

void PlayerIdleMain(Entity* ent)
{
    Player* p = (Player*)ent;
    p->SetVelocity({ 0.0f, 0 });
}

void PlayerWalkMain(Entity* ent)
{
    Player* p = (Player*)ent;
    p->SetVelocityX(0x300 | (p->isFacingLeft ? 0x8000 : 0x0));
}

void PlayerJumpInit(Entity* ent)
{
    Player* p = (Player*)ent;
    int jumpInd = p->DetermineJumpTableIndex();
    if (jumpInd != -1)
    {
        p->SetVelocityY(p->physics.JumpPhysics[jumpInd].FirstFrameJumpY);
        p->SetMaxVelocityY((p->physics.JumpPhysics[jumpInd].FirstFrameJumpY & 0x7FFF) + 1);
    }
}

void PlayerJumpMain(Entity* ent)
{
    Player* p = (Player*)ent;
    p->SetAccelerationY(Input::ButtonDown("Jump", p->playerId) ? p->physics.GravityBYAccel : p->physics.GravityNoBYAccel);
    p->SetMaxVelocityY(p->physics.TerminalYVel);
    if (p->GetPosition().y <= 0.0f)
    {
        p->SetPositionY(0);
        p->SetVelocityY(0);
        p->SetAccelerationY(0);
        if (Input::ButtonDown("Left", p->playerId) || Input::ButtonDown("Right", p->playerId))
        {
            p->ChangeState(PLAYER_WALK);
        }
        else
        {
            p->ChangeState(PLAYER_IDLE);
        }
    }
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