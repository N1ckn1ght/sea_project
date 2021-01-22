#include "Ship.h"

Ship::Ship()
{
	x = 0;
	y = 0;
	dir = Dir::up;
	size = 0;
	left = 0;
}

Ship::Ship(int nx, int ny, Dir ndir, int nsize)
{
	x = nx;
	y = ny;
	dir = ndir;
	size = nsize;
	left = nsize;
}