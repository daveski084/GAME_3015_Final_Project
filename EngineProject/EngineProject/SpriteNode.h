#pragma once
#include "Entity.h"
#include "CommandQueue.h"
#include "State.h"


class SpriteNode : public Entity
{
public:
    struct BGMover
    {
        XMFLOAT3 velocity;
    
	    BGMover(float vx, float vy, float vz) : velocity(vx, vy, vz){}
        void operator() (SceneNode& node, const GameTimer& gt) 
        {
            SpriteNode& spriteNode = static_cast<SpriteNode&>(node);
            spriteNode.move(velocity);
        }
    };

	SpriteNode(State* state);

	void Update(const GameTimer gt);
	void UpdateWithCmd(CommandQueue& commands);
    void CustomBuildCurrent(std::string material, std::string geometry, std::string shape);

	float backgroundSpeed;
    std::unique_ptr<RenderItem> SpriteRenderer;

private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();
};
