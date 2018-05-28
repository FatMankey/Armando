#pragma once

#include <string>

// With the magic directory in the same folder as the unittests.exe file (solution dir/x64/debug)
// this path works if running with or without debugging outside Visual Studio, but not if running within VS
//const std::string	DATA_PATH	= "magic/";

// When running with or without debugging within Visual Studio, the working directory is the UnitTests project folder.
// With the magic directory in the UnitTests project folder this path works.
const std::string	DATA_PATH	= "magic/";
const std::string	TYPES_FILE	= "types.xml";

const int BLANK_CARD = 0;

enum class SIDES {
	BLANK_CARD,
	FRONT_SIDE,
	BACK_SIDE
};
