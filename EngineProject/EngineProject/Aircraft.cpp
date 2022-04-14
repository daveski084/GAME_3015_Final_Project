#include "Aircraft.h"
#include "Game.h"


Aircraft::Aircraft(Type type, State* state) : Entity(state), mType(type)
{
	switch (type)
	{
	case (Eagle):
		mSprite = "Eagle";
		break;
	case (Raptor):
		mSprite = "Raptor";
		break;
	default:
		mSprite = "Eagle";
		break;
	}
}


void Aircraft::drawCurrent() const
{	

}

void Aircraft::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();
	renderer->World = getTransform();
	renderer->ObjCBIndex = mState->getRenderItems().size();
	renderer->Mat = mState->getContext()->game->getMaterials()[mSprite].get();
	renderer->Geo = mState->getContext()->game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;
	mState->getRenderItems().push_back(std::move(render));

}

void Aircraft::Update(const GameTimer& gt)
{
}

unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
		case Eagle:
			return Category::Type::PlayerAircraft;
		default:
			return Category::Type::EnemyAircraft;
	}
}

