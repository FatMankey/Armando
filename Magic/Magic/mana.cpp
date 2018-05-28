#include "mana.h"

Mana::Mana(int numberOfMana, int color) {
	this->numberOfMana	= numberOfMana;
	this->color			= color;
}

Mana::~Mana() {
}

int Mana::getNumberOfMana() const {
	return numberOfMana;
}

int Mana::getColor() const {
	return color;
}
