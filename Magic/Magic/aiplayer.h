#pragma once
#include "player.h"
#include "types.h"
#include <string>
class AIPlayer : public Player
{
private:
public:
	AIPlayer(std::string name, std::string filename, Types* types);
	~AIPlayer();
};

