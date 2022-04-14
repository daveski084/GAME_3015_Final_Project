#pragma once
#include "Entity.h"
#include <string>


class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};
	
	
	Aircraft(Type type, State* state);

	void Update(const GameTimer& gt);
	unsigned int getCategory() const;

	
private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();


	Type mType;
	std::string mSprite;
};
