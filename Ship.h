#pragma once
#include "Enums.h"

using namespace std;

class Ship {
public:
	int x;
	int y;
	Dir dir;
	int size;
	int left;

	Ship();
	Ship(int nx, int ny, Dir ndir, int nsize);
};