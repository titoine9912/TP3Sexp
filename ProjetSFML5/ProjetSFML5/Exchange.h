#pragma once
#include <string>

class Exchange
{
public:
	Exchange();
	static int semaphore;
	static std::string message;
};

enum semaphoreState
{
	notInUse,
	inUseByTerminal,
	inUseByServer,
	toReadByTerminal,
	toReadByServer
};