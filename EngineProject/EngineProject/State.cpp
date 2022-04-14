#include "State.h"
#include "StateStack.h"
#include "World.h"
#include "Player.h"
#include "Game.h"


State::Context::Context(Player& player, Game& game) : player(&player), game(&game)
{
}

void State::Context::BuildWorld()
{
}

State::State(StateStack* stack, Context* context): mStack(stack), mContext(context)
	, mSceneGraph(std::make_unique<SceneNode>(this))
{
}

State::~State()
{
}


bool State::UpdateObjectCB()
{
	mContext->game->UpdateObjectCBs(mAllRitems);

	return true;
}


void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context* State::getContext() const
{
	return mContext;
}
