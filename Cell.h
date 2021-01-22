#pragma once
#include "Enums.h"

class Cell {
public:
	Status status;
	int link;

	Cell();
	Cell(int nlink);
};