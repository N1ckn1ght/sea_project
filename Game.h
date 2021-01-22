#pragma once
#include "Field.h"
#include "Ship.h"
#include <vector>

class GameException {};

class Game
{
private:
	Field afield;
	Field bfield;
	vector <Ship> aships;
	vector <Ship> bships;

public:
	Game();
	Game start();
};