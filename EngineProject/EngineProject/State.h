#pragma once
#include <memory>
#include "SceneNode.h"

class World;
class Player;
class StateStack;

namespace States
{
	enum ID
	{
		None,
		Title,
		Menu,
		Game,
		Loading,
		Pause
	};
}


class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    // context for each state object
    struct Context
    {
        Context(Player& player, Game& game);
        void BuildWorld();
        
        Game* game;
        Player* player;
    };

    State(StateStack* stack, Context* context);

    virtual ~State();
    virtual void draw() = 0 ;
    virtual bool update(const GameTimer& gt) = 0;
    virtual bool handleEvent(WPARAM btnState) = 0;
    bool UpdateObjectCB();

    // get render item list
    std::vector<std::unique_ptr<RenderItem>>& getRenderItems() { return mAllRitems; }
    
    // scene graph
    std::unique_ptr<SceneNode> mSceneGraph;

    // return state context
    Context* getContext() const;

protected:
    // manipulation method
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStateClear();

    Context* mContext;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;


private:
    StateStack* mStack;

};

