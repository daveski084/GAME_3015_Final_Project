#pragma once
#include "State.h"
#include <vector>
#include <map>
#include <functional>


class StateStack
{
public:
    enum Action
    {
        Push,
        Pop,
        Clear
    };


public:
    explicit StateStack(State::Context context);
    
    // template for registering a state
    template <typename T>
    void registerState(States::ID stateID)
    {
        mFactories[stateID] = [this]()
        {
            return State::Ptr(new T(this, &mContext));
        };
    }

    void update(const GameTimer& gt);
    void draw();
    void UpdateStateObjectCB();

    // state manipulation
    void pushState(States::ID);
    void popState();
    void clearStates();
    void handleEvent(WPARAM btnState);
    // determine if stack empty
    bool isEmpty() const;

    State::Context mContext;

private:
	struct PendingChange
	{
		explicit PendingChange(Action action, States::ID stateID = States::None);

		Action action;
		States::ID stateID;
	};

    State::Ptr createState(States::ID stateID);
    void StateStack::applyPendingChanges();
    
    std::vector<State::Ptr> mStack;
    std::vector<PendingChange> mPendingList;
    std::map<States::ID, std::function<State::Ptr()>> mFactories;

};

