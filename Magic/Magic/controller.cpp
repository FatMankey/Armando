#include "controller.h"

Controller::Controller() {
	types = new Types();
}

Controller::~Controller() {
	delete types;
}
