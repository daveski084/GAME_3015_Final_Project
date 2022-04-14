#pragma once
#include "CommandQueue.h"
#include "Aircraft.h"
#include "World.h"
#include <map>


class Player
{
    
    struct AircraftMover
    {
        XMFLOAT3 velocity;
        
        AircraftMover(float vx, float vy, float vz) : velocity(vx, vy, vz)
        {

        }

        void operator() (SceneNode& node, const GameTimer& gt) 
        {
            Aircraft& aircraft = static_cast<Aircraft&>(node);
            aircraft.move(velocity);
        }        
    };

   
    enum Action
    {
        MoveLeft,
        MoveRight,
        MoveForward,
        MoveBackward
    };


public:
    Player();
    
    const float playerSpeed = 0.001f;

    void handleEvent(CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
    void assignKey(Action action, int key);
    
    std::string getAssignedKey(Action action) const;

private:
   
    static bool isRealtimeAction(Command command);

    // map for key and action binding
    std::map<int, Action> mKeyBinding;
    std::map<Action, Command> mActionBinding;

    // player commands
    Command moveLeft;
    Command moveRight;
    Command moveForward;
    Command moveBackward;

};

