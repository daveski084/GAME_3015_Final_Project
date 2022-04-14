#pragma once
#include "Entity.h"
#include "CommandQueue.h"


class TitleSprite :  public Entity
{
public:

	TitleSprite(State* state);

	void Update(const GameTimer gt);
	void UpdateWithCmd(CommandQueue& commands);

	std::string TextureName;

private:

	virtual void drawCurrent() const;
	virtual void buildCurrent();

    std::unique_ptr<RenderItem> SpriteRenderer;

};

