#pragma once
#include "Entity.h"
#include <string>


class Enemy : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};

	Enemy(Type type, State* state);

private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();

    
	Type mType;
	std::string mSprite;

};

