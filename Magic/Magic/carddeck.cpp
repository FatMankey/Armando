#include "carddeck.h"

CardDeck::CardDeck(std::string fileName, Types* types) {
	this->types = types;
	create(fileName);
}

CardDeck::~CardDeck() {
}

std::pair<bool, std::vector<std::string>>  CardDeck::create(std::string fileName) {
	std::pair<bool, std::vector<std::string>> result;
	bool valid = true;

	std::vector<std::string> messages;
	std::vector<std::string> errors;
	std::vector<std::string> warnings;

	XMLTree<std::string, std::string>* rootTree = Tools::XMLParser(DATA_PATH, fileName, messages);

	if (!rootTree->isEmpty()) {
		if (!rootTree->hasErrors()) {
			std::vector<XMLTree<std::string, std::string>*> rootTreeSubtrees = rootTree->getTreesInPreOrder();

			// Temp: only 2 Cards defined in xml file
			if (rootTreeSubtrees.size() >= 2) {
				for (XMLTree<std::string, std::string>* cardSubTree : rootTreeSubtrees) {
					// Retrieve all nodes in whatever order they appear in the file.
					// The name and type nodes are required. Validate and issue errors.
					std::vector<std::pair<std::string, std::string>> nodes = cardSubTree->getNodesInOrder();
					for (std::pair<std::string, std::string> pair : nodes) {
						// add to name?
						if (pair.first == "name") {
							std::string name = Tools::toUpper(pair.second);
							//little hiccup -come back to this
						}
						if (pair.first == "type") {
							std::string type = Tools::toUpper(pair.second);

							// Validate the type against the Types cardType
							if (types->findCardType(type)) {
								  
							}
							else {
								// Skip rest of unknown Card
								errors.emplace_back("Error: CardDeck::create(): Invalid Card type " + type);
								break;
							}
						}
						if (pair.first == "text") {
							std::string FillerText = Tools::toUpper(pair.second);
							// same with above come back to this..
						}
						std::vector<XMLTree<std::string, std::string>*> SubTree = cardSubTree->getTreesInPreOrder();
						//if(TapTree.empty())
						//{
						//	continue;
						//}
						//std::vector<XMLTree<std::string, std::string>*> choosetree = TapTree->getTreesInPreOrder();
						for(XMLTree<std::string,std::string>* TapTree : SubTree)
						{
							std::vector<XMLTree<std::string, std::string>*> choosetree = TapTree->getTreesInPreOrder();
							for(XMLTree<std::string,std::string>* ChooseTree : choosetree)
							{
								std::vector<XMLTree<std::string, std::string>*> optiontree = ChooseTree->getTreesInPreOrder();
								//if(!OptionTree.empty())
								//{
								//	printf("no poo");
								//}
								//add 'add' and 'mana' tree next
								for(XMLTree<std::string, std::string>* OptionTree :optiontree)
								{
									std::vector<XMLTree<std::string, std::string>*> addtree = OptionTree->getTreesInPreOrder();
									for(XMLTree<std::string, std::string>*ManaTree : addtree)
									{
										std::vector<XMLTree<std::string, std::string>*> mana_tree = ManaTree->getTreesInPreOrder();
										if (ManaTree->getTreeKey() == "add")
										{
											for (XMLTree<std::string, std::string>* Mana_Tree : mana_tree) {
												std::vector<std::pair<std::string, std::string>> mana_nodes = Mana_Tree->getNodesInOrder();
												/*for()*/
												//get nodes next
												for (std::pair<std::string, std::string> mana_pair : mana_nodes)
												{
													if (mana_pair.first == "color")
													{
														std::string color = Tools::toUpper(mana_pair.second);
													}
													if (mana_pair.first == "count")
													{
														int count = stoi(mana_pair.second);
													}
													else
														printf("error");
												}
											}
										}
										if(ManaTree->getTreeKey() == "pay")
										{
											for (XMLTree<std::string, std::string>* Pay_Tree : mana_tree) {
												std::vector<std::pair<std::string, std::string>> Pay_nodes = Pay_Tree->getNodesInOrder();
												/*for()*/
												//get nodes next
												for (std::pair<std::string, std::string> pay_pair : Pay_nodes)
												{
													if (pay_pair.first == "color")
													{
														std::string color = Tools::toUpper(pay_pair.second);
													}
													if (pay_pair.first == "count")
													{
														int count = stoi(pay_pair.second);
													}
													else
														printf("error");
												}

											}
										}
										//third option after pay not all have this option...
										//
										if (ManaTree->getTreeKey() == "choose")
										{
											for (XMLTree<std::string, std::string>* Choose_Option : mana_tree)
											{
												std::vector<XMLTree<std::string, std::string>*> choose_option = Choose_Option->getTreesInPreOrder();
												for (XMLTree<std::string, std::string>* s_add_tree : choose_option)
												{
													std::vector<XMLTree<std::string, std::string>*> S_Add_Tree = s_add_tree->getTreesInPreOrder();
													for(XMLTree<std::string, std::string>* add_option_node : S_Add_Tree)
													{
														std::vector<std::pair<std::string, std::string>> addition_nodes = add_option_node->getNodesInOrder();
														for (std::pair<std::string,std::string> ADD_NODES : addition_nodes) {
															if (ADD_NODES.first == "color")
															{
																std::string color = Tools::toUpper(ADD_NODES.second);
															}
															if (ADD_NODES.first == "count")
															{
																int count = stoi(ADD_NODES.second);
															}
														}
													}
												}
											}
										}
									}
								}
							}


						}
					}

				}


			}
			else {
				errors.emplace_back("Error: CardDeck::create(): Found " + std::to_string(rootTreeSubtrees.size()) + std::string(" Cards. Card Deck must have at least 60 Cards. Please correct and re-run."));
			}
		}
		else {
			errors.emplace_back("Error: CardDeck::create(): Error(s) found parsing the Card Deck file. Please correct and re-run.");
		}
	}
	else {
		errors.emplace_back("CardDeck::create(): Card Deck file is empty or was not found");
	}

	if (!errors.empty()) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
		valid = false;
	}

	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}

	result.first	= valid;
	result.second	= messages;

	return result;
}
