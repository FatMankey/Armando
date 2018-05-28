#pragma once

#include "constants.h"
#include "tools.h"
#include "xmltree.h"
#include "xmlnode.h"
#include <map>
#include <string>
#include <vector>

class Types {
	private:
		std::map<std::string, int>		cardTypes;
		std::map<int, std::string>		cardTypeIndexes;
		std::map<std::string, int>		cardColors;
		std::map<int, std::string>		cardColorIndexes;
		std::map<std::string, int>		cardSubTypes;
		std::map<int, std::string>		cardSubTypeIndexes;
		std::map<std::string, int>		artifactTypes;
		std::map<int, std::string>		artifactTypeIndexes;
		std::map<std::string, int>		enchantmentTypes;
		std::map<int, std::string>		enchantmentTypeIndexes;
		std::map<std::string, int>		landTypes;
		std::map<int, std::string>		landTypeIndexes;
		std::map<std::string, int>		basicLandTypes;
		std::map<int, std::string>		basicLandTypeIndexes;
		std::map<std::string, int>		planeswalkerTypes;
		std::map<int, std::string>		planeswalkerTypeIndexes;
		std::map<std::string, int>		creatureTypes;
		std::map<int, std::string>		creatureTypeIndexes;
		std::map<std::string, int>		tribalTypes;
		std::map<int, std::string>		tribalTypeIndexes;
		std::map<std::string, int>		spellTypes;
		std::map<int, std::string>		spellTypeIndexes;
		std::map<std::string, int>		planeTypes;
		std::map<int, std::string>		planeTypeIndexes;
		std::map<std::string, int>		demonTypes;
		std::map<int, std::string>		demonTypeIndexes;

		// Helper functions
		bool create();

		public:
			Types();
			~Types();

			bool		findCardType(std::string name);
			bool		findCardType(int number);
			int			getCardType(std::string name);
			std::string getCardType(int number);
			bool		addCardType(std::string name, int number);
};

