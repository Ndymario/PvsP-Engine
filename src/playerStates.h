#pragma once
#include "player.h"
#include "playerState.h"

struct PlayerIdleState : public PlayerState
{
    void Start(Player* player)
    {
        player->GetModel().SetAnimation("MarioIdle");
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
            player->GetModel().Rotate({90, 180, 0});
        }
        else 
        {
            player->GetModel().Rotate({90, 0, 0});
        }
        player->SetAcceleration({-(player->isFacingLeft ? 1 : -1) * player->accelRate, 0.0f});
        player->GetModel().SetAnimation("MarioWalk");
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
};