#include "GameState.h"
#include "Game.h"



GameState::GameState(StateStack* stack, Context* context): State(stack, context), mPlayer(*context->player), 
    mGame(context->game)
{
    OutputDebugString(L"game init");
    OutputDebugString(L"\n");
    
    mAllRitems.clear();

    // set aircraft size
	aircraftSize = XMFLOAT3(0.5f, 0.5f, 0.5f);

    // // Player
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, this));
	mPlayerAircraft = player.get();
	mPlayerAircraft->setPosition(0.0f, 0.1f, -1.0f);
	mPlayerAircraft->setScale(aircraftSize);
	mSceneGraph->attachChild(std::move(player));

	// Enemy
	std::unique_ptr<Aircraft> enemy3(new Aircraft(Aircraft::Raptor, this));
	auto raptor3 = enemy3.get();
	raptor3->setPosition(0.5f, 0.1f, 1.0f);
	raptor3->setScale(aircraftSize);
	raptor3->setWorldRotation(0, XM_PI, 0);
	mSceneGraph->attachChild(std::move(enemy3));


	// Background
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(this));
	mBackground = backgroundSprite.get();
	mBackground->setPosition(0.0f, 0.0f, 0.0f);
	mBackground->setScale(50.0, 1.0, 50.0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

    // build scenegraph
    mSceneGraph->build();

    // build render items
    getContext()->game->BuildRenderItems(mAllRitems);

    // build frame resources
    getContext()->game->BuildFrameResources(mAllRitems.size());

}

void GameState::draw()
{
    // mWorld.draw();
    mSceneGraph->draw();
}

bool GameState::update(const GameTimer& gt)
{  
    // update world
    // mWorld.update(gt);

    mSceneGraph->update(gt);

    while (!cQueue.isEmpty())
	{
		mSceneGraph->onCommand(cQueue.pop(), gt);
	}


    // handle player input
	mPlayer.handleRealtimeInput(cQueue);


	mBackground->Update(gt);


    // press b to goto title state
    if (GetAsyncKeyState('B') & 0x8000)
    {
        requestStackPop();
        requestStackPush(States::Menu);
        
        return false;
    }

	return true;

}

bool GameState::handleEvent(WPARAM btnState)
{

	return true;
}
