#include "Player.h"

Player::Player()
{
    // setup the inputs
    moveLeft.category = Category::Type::PlayerAircraft;
    moveLeft.action = AircraftMover(-playerSpeed, 0.0f, 0.0f);
    moveLeft.isRealtimeAction = true;
    
    moveRight.category = Category::Type::PlayerAircraft;
    moveRight.action = AircraftMover(playerSpeed, 0.0f, 0.0f);
    moveRight.isRealtimeAction = true;

    moveForward.category = Category::Type::PlayerAircraft;
    moveForward.action = AircraftMover(0.0f, 0.0f, playerSpeed);
    moveForward.isRealtimeAction = true;
    
    moveBackward.category = Category::Type::PlayerAircraft;
    moveBackward.action = AircraftMover(0.0f, 0.0f, -playerSpeed);
    moveBackward.isRealtimeAction = true;
    


    // fill key binding map
    mKeyBinding.insert(std::pair<int, Action>('A', Action::MoveLeft));
    mKeyBinding.insert(std::pair<int, Action>('D', Action::MoveRight));
    mKeyBinding.insert(std::pair<int, Action>('W', Action::MoveForward));
    mKeyBinding.insert(std::pair<int, Action>('S', Action::MoveBackward));



    // fill action binding map
    mActionBinding.insert(std::pair<Action, Command>(Action::MoveLeft, moveLeft));
    mActionBinding.insert(std::pair<Action, Command>(Action::MoveRight, moveRight));
    mActionBinding.insert(std::pair<Action, Command>(Action::MoveForward, moveForward));
    mActionBinding.insert(std::pair<Action, Command>(Action::MoveBackward, moveBackward));


}



void Player::handleEvent(CommandQueue& commands)
{

}


void Player::handleRealtimeInput(CommandQueue& commands)
{


    // push all item in key binding into the command queue
    // pair first = keypressed, second = action enum
    for(auto pair : mKeyBinding)
    {
        if (GetAsyncKeyState(pair.first) && isRealtimeAction(mActionBinding[pair.second]))
        {
            commands.push(mActionBinding[pair.second]);
        }
    }

}

void Player::assignKey(Action action, int key)
{
}

std::string Player::getAssignedKey(Action action) const
{
    return std::string();
}


bool Player::isRealtimeAction(Command command)
{
    return command.isRealtimeAction;
}
