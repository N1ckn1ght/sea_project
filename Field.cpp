#include "Field.h"

using namespace std;

Field::Field()
{
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = Cell();
		}
	}
}