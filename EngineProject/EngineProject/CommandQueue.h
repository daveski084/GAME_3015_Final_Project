#pragma once
#include <iostream>
#include <Queue>
#include <functional>
#include "SceneNode.h"


struct Command
{
	Command() = default;

	// command name
	std::string name;

	// lambda function for command
	std::function<void(SceneNode&, const GameTimer& gt)> action;
	
	// command category
	unsigned int category = NULL;

	// define if command is a realtime action
	bool isRealtimeAction = false;
};



class CommandQueue
{
public:

	// push commands into the command queue
	void push(const Command newCommand);

	// remove commands from the command queue
	Command pop();

	// return if queue is empty
	bool isEmpty() const;


private:
	// FIFO queue for commands
	std::queue<Command> mQueue;

};

