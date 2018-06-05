#pragma once
#include "carddeck.h"
#include "types.h"
#include <string>
class Player
{
private:
	std::string name;
	// OOP composition (HAS A)
	// CardDeck cardDeck;
	CardDeck carddeck;
public:
	Player();
	Player(std::string name,std::string filename, Types* types);
	virtual ~Player();

};

