#include "player.h"


Player::Player(std::string name, std::string filename, Types* types) : carddeck(filename, types){
	this->name = name;
}


Player::~Player()
{
}


