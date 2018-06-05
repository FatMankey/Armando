#pragma once
#include "player.h"
#include "types.h"
#include <string>
class HumanPlayer : public Player {
private:

public:
	
	HumanPlayer(std::string name, std::string filename, Types* types);
	~HumanPlayer();
	void test();

	
};

