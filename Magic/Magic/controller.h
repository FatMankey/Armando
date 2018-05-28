#pragma once

#include "constants.h"
#include "types.h"
#include <vector>
#include <string>

class Controller {
	private:
		// OOP Composition: the Controler HAS A Types
		Types*	types;

	public:
		Controller();
		~Controller();
};
