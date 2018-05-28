#pragma once

// CURRENTLY NOT USED
// A "wrapper" class
class Mana {
	private:
		int			numberOfMana;
		int			color;

	public:
		Mana(int numberOfMana, int color);
		~Mana();

		// Getters
		int getNumberOfMana() const;
		int getColor() const;
};

