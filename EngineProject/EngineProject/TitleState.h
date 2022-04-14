#pragma once
#include "State.h"
#include "Player.h"
#include "World.h"


class TitleState : public State
{
public:
    TitleState(StateStack* stack, Context* context);


    virtual void draw();
    virtual bool update(const GameTimer& gt);
    virtual bool handleEvent(WPARAM btnState);

private:

    std::string TitleTextureName = "Title";
    TitleSprite* bg;
    TitleSprite* bg2;
    TitleSprite* bg3;

};

