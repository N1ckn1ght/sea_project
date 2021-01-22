#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void print(const Field& field) {
	cout << "Текущее поле:\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (field.field[i][j].status == Status::ship) {
				cout << "X ";
			}
			else {
				cout << ". ";
			}
		}
		cout << "\n";
	}
	cout << endl;
}

void interact_place(Field& field, vector <Ship>& ships) {
	vector <short> ships_left({ 4, 3, 2, 1 });
	
	cout << "Для создания поля вам нужно разместить 10 кораблей.\nКорабли должны быть размещены в линию и не пересекаться между собой.\nУ вас может быть 4 однопалубных корабля, 3 двупалубных, 2 трёхпалубных, 1 четырёхпалубный.\nЧтобы задать корабли, вам нужно указать стартовую клетку, направление корабля и кол-во палуб.\nНапример, C10 UP 4 поставит линкор клетках C7, C8, C9, C10.\nКлетки A-J, 1-10, направления UP/RIGHT/DOWN/LEFT, длина корабля 1-4.\n\n";	
	while (ships_left[0] + ships_left[1] + ships_left[2] + ships_left[3]) {
		print(field);

		string spoint, sdir, ssize;
		cin >> spoint >> sdir >> ssize;

		int nx = 0, ny = 0, nsize = 0;
		Dir dir = Dir::up;

		bool correct = true;

		if (spoint.size() == 2) {
			if (spoint[0] >= 'A' && spoint[0] <= 'J' && spoint[1] >= '1' && spoint[1] <= '9') {
				ny = spoint[0] - 'A';
				nx = spoint[1] - '1';
			}
			else {
				correct = false;
			}
		}
		else if (spoint.size() == 3) {
			if (spoint[0] >= 'A' && spoint[0] <= 'J' && spoint[1] == '1' && spoint[2] == '0') {
				ny = spoint[0] = 'A';
				nx = 10;
			}
			else {
				correct = false;
			}
		}
		else {
			correct = false;
		}

		if (sdir == "UP") {
			dir = Dir::up;
		}
		else if (sdir == "RIGHT") {
			dir = Dir::right;
		}
		else if (sdir == "DOWN") {
			dir = Dir::down;
		}
		else if (sdir == "LEFT") {
			dir = Dir::left;
		}
		else {
			correct = false;
		}

		if (ssize.size() == 1 && ssize[0] >= '1' && ssize[0] <= '4') {
			nsize = stoi(ssize);
			if (ships_left[nsize - 1] <= 0) {
				correct = false;
			}
			else {
				// проверить невыход за границы поля xy + nsize <> 0/10 
			}
		}
		else {
			correct = false;
		}

		if (correct) {
			// проверить непересечение
			// добавить корабль класса ship в массив, разместить его на поле, отнять нужную переменную
			
			ships_left[nsize - 1]--;
			Ship current_ship(nx, ny, dir, nsize);
			Cell current_cell(ships.size());
			ships.push_back(current_ship);

			if (dir == Dir::up) {
				for (int i = nx; i > (nx - nsize); i--) {
					field.field[i][ny] = current_cell;
				}
			}
			else if (dir == Dir::right) {
				//
			}

		}
		else {
			cout << "Произошла ошибка. Убедитесь в правильности введёных аргументов.\n";
			continue;
		}
	}
}

Game::Game()
{
	Field afield;
	Field bfield;
}

Game Game::start()
{
	interact_place(afield, aships);
	interact_place(bfield, bships);

	return Game();
}
