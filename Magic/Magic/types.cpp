#include "types.h"

Types::Types() {
	if (!create()) {
		std::string message = "Types::Types(): unable to create rules. File not found or errors found: " + DATA_PATH + TYPES_FILE;
		throw std::runtime_error(message.c_str());
	}
}

Types::~Types() {
}

bool Types::create() {
	bool valid = true;

	std::vector<std::string> messages;
	std::vector<std::string> errors;
	std::vector<std::string> warnings;

	XMLTree<std::string, std::string>* rootTree = Tools::XMLParser(DATA_PATH, TYPES_FILE, messages);

	if (rootTree->isValid()) {
		// Get the root Tree's subtrees
		std::vector<XMLTree<std::string, std::string>*>  rootTreeSubTrees = rootTree->getTreesInPreOrder();

		for (XMLTree<std::string, std::string>* tree : rootTreeSubTrees) {
			// <type> tags are organized by the tag name (type), not by the tag value!
			// Retrieved in-order (alphabetical by "type") causes them to be retrieved last-type-tag first.
			// Retrieved in-pre-oder causes them to be retrieved first-type-tag first.
			std::vector<std::pair<std::string, std::string>> nodes = tree->getNodesInOrder();

			if (tree->getTreeKey() == "card-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!cardTypes.emplace(std::make_pair(pair.second, cardTypes.size())).second || !cardTypeIndexes.emplace(std::make_pair(cardTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <card-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "colors") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!cardColors.emplace(std::make_pair(pair.second, cardColors.size())).second || !cardColorIndexes.emplace(std::make_pair(cardColorIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <colors>: duplicate <color> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "card-subtypes") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!cardSubTypes.emplace(std::make_pair(pair.second, cardSubTypes.size())).second || !cardSubTypeIndexes.emplace(std::make_pair(cardSubTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <card-subtypes>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "artifact-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!artifactTypes.emplace(std::make_pair(pair.second, artifactTypes.size())).second || !artifactTypeIndexes.emplace(std::make_pair(artifactTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <artifact-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "enchantment-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!enchantmentTypes.emplace(std::make_pair(pair.second, enchantmentTypes.size())).second || !enchantmentTypeIndexes.emplace(std::make_pair(enchantmentTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <enchantment-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "land-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!landTypes.emplace(std::make_pair(pair.second, landTypes.size())).second || !landTypeIndexes.emplace(std::make_pair(landTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <land-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "basic-land-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!basicLandTypes.emplace(std::make_pair(pair.second, basicLandTypes.size())).second || !basicLandTypeIndexes.emplace(std::make_pair(basicLandTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <basic-land-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "planeswalker-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!planeswalkerTypes.emplace(std::make_pair(pair.second, planeswalkerTypes.size())).second || !planeswalkerTypeIndexes.emplace(std::make_pair(planeswalkerTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <planeswalker-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "creature-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!creatureTypes.emplace(std::make_pair(pair.second, creatureTypes.size())).second || !creatureTypeIndexes.emplace(std::make_pair(creatureTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <creature-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "tribal-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!tribalTypes.emplace(std::make_pair(pair.second, tribalTypes.size())).second || !tribalTypeIndexes.emplace(std::make_pair(tribalTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <tribal-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "spell-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!spellTypes.emplace(std::make_pair(pair.second, spellTypes.size())).second || !spellTypeIndexes.emplace(std::make_pair(spellTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <spell-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "plane-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!planeTypes.emplace(std::make_pair(pair.second, planeTypes.size())).second || !planeTypeIndexes.emplace(std::make_pair(planeTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <plane-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else if (tree->getTreeKey() == "demon-types") {
				for (std::pair<std::string, std::string> pair : nodes) {
					if (!demonTypes.emplace(std::make_pair(pair.second, demonTypes.size())).second || !demonTypeIndexes.emplace(std::make_pair(demonTypeIndexes.size(), pair.second)).second) {
						errors.emplace_back("Types::create(): <demon-types>: duplicate <type> tag found: " + pair.second);
					}
				}
			}
			else {
				errors.emplace_back("Types::create(): invalid tag found: <" + tree->getTreeKey() + ">");
			}
		}
	}
	else if (rootTree->isEmpty()) {
		errors.emplace_back("Types::create(): Types file is empty or was not found");
	}
	else {
		errors.emplace_back("Types::create(): Error(s) found parsing the Types file. Please correct and re-run.");
	}

	if (!errors.empty()) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
		valid = false;
	}

	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}

	return valid;
}

bool Types::findCardType(std::string name) {
	bool found = false;

	/*
	// Long way
	const std::map<std::string, int>::const_iterator iterator = cardTypes.find(name);

	if (iterator != cardTypes.end()) {
		found = true;
	}
	*/

	// Short way
	if (cardTypes.find(name) != cardTypes.end()) {
		found = true;
	}

	return found;
}

bool Types::findCardType(int number) {
	bool found = false;

	if (cardTypeIndexes.find(number) != cardTypeIndexes.end()) {
		found = true;
	}

	return found;
}

int Types::getCardType(std::string name) {
	int number = 0;

	const std::map<std::string, int>::const_iterator iterator = cardTypes.find(name);

	if (iterator != cardTypes.end()) {
		number = iterator->second;
	}

	return number;
}

std::string Types::getCardType(int number) {
	std::string name = "";

	const std::map<int, std::string>::const_iterator iterator = cardTypeIndexes.find(number);

	if (iterator != cardTypeIndexes.end()) {
		name = iterator->second;
	}

	return name;
}

bool Types::addCardType(std::string name, int number) {
	bool added = false;

	/*
	// Long way
	const std::pair<std::map<std::string, int>::iterator, bool> result = cardTypes.emplace(std::make_pair(name, number));

	if (result.second) {
		const std::pair<std::map<int, std::string>::iterator, bool> result = cardTypeIndexes.emplace(std::make_pair(number, name));

		if (result.second) {
			added = true;
		}
	}
	*/

	// Short way
	if (cardTypes.emplace(std::make_pair(name, number)).second && cardTypeIndexes.emplace(std::make_pair(number, name)).second) {
		added = true;
	}

	return added;
}
