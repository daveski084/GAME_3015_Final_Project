#pragma once
#include "State.h"
#include "Player.h"
#include "World.h"


class MenuState : public State
{
public:
    MenuState(StateStack* stack, Context* context);


    virtual void draw();
    virtual bool update(const GameTimer& gt);
    virtual bool handleEvent(WPARAM btnState);
private:

    std::string MenuTextureName = "Menu";
    TitleSprite* bg;
    TitleSprite* bg2;
    TitleSprite* bg3;

};