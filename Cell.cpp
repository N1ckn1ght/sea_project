#include "Cell.h"

Cell::Cell()
{
	status = Status::unknown;
	link = -1;
}

Cell::Cell(int nlink)
{
	status = Status::ship;
	link = nlink;
}