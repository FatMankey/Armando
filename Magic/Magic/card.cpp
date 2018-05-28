#include "card.h"

// Reference should be initialized either by passing data to a parmeterized constructor (a constructor with a parameter list)
// or allocating memory from the heap if you want to initialize in default constructor (a constructor which can be called with no arguments,
// either defined with an empty parameter list, or with default arguments provided for every parameter): 
// dynamically allocate the vector and then dereference it (*) to get a reference to the vector.

Card::Card() : mana(*(new std::map<int, int>())) {
	side				= SIDES::BLANK_CARD;
	name				= "";
	type				= BLANK_CARD;
	convertedManaCost	= 0;
	text				= "";
	tapped				= false;
	valid				= false;
}

// Reference class variables must be initialized in a constructor via the initializer list (:), not in the body of the constructor
Card::Card(SIDES side, std::string name, int type, std::map<int, int> &mana, std::string text) : mana(mana) {
	this->side		= side;
	this->name		= name;
	this->type		= type;
	this->text		= text;

	convertedManaCost = 0;

	for (const std::pair<int, int> pair : this->mana) {
		convertedManaCost += pair.second;
	}

	tapped			= false;
	valid			= true;
}

// Copy constructor and copy assignment operator
Card::Card(const Card *other) : mana(other->mana) {
	side				= other->side;
	name				= other->name;
	type				= other->type;
	convertedManaCost	= other->convertedManaCost;
	text				= other->text;
	tapped				= other->tapped;
	valid				= other->valid;
}

Card* Card::operator =(const Card *other) {
	side				= other->side;
	name				= other->name;
	type				= other->type;
	mana				= other->mana;
	convertedManaCost	= other->convertedManaCost;
	text				= other->text;
	tapped				= other->tapped;
	valid				= other->valid;

	return this;
}

Card::~Card() {
}

SIDES Card::getSide() const {
	return side;
}

std::string Card::getName() const {
	return name;
}

int Card::getType() const {
	return type;
}

std::map<int, int>& Card::getMana() const {
	return mana;
}

int Card::getMana(int color) const {
	int numberOfMana = 0;

	const std::map<int, int>::const_iterator iterator = mana.find(color);

	if (iterator != mana.end()) {
		numberOfMana = iterator->second;
	}

	return numberOfMana;
}

int Card::getConvertedManaCost() const {
	return convertedManaCost;
}

std::string Card::getText() const {
	return text;
}

bool Card::isTapped() const {
	return tapped;
}

bool Card::isBlank() const {
	return type == BLANK_CARD;
}

bool Card::isValid() const {
	return valid;
}

void Card::setCard(SIDES side, std::string name, int type, std::map<int, int> &mana, std::string text, bool tapped) {
	this->side = side;
	this->name = name;
	this->type = type;
	this->text = text;

	convertedManaCost = 0;

	for (const std::pair<int, int> pair : this->mana) {
		convertedManaCost += pair.second;
	}

	this->tapped = tapped;
}

void Card::setSide(SIDES side) {
	this->side = side;
}

void Card::setName(std::string name) {
	this->name = name;
}

void Card::setType(int type) {
	this->type = type;
}

void Card::setMana(std::map<int, int> &mana) {
	this->mana = mana;

	for (const std::pair<int, int> pair : this->mana) {
		convertedManaCost += pair.second;
	}
}

bool Card::addMana(int color, int numberOfMana) {
	std::pair<std::map<int, int>::iterator, bool> added = mana.insert(std::make_pair(color, numberOfMana));
	
	if (added.second) {
		convertedManaCost += added.first->second;
	}

	return added.second;
}

void Card::setText(std::string text) {
	this->text = text;
}

void Card::setTapped() {
	tapped = true;
}

void Card::setValid(bool valid) {
	this->valid = valid;
}
