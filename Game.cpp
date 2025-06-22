#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include "Game.h"
#include "start.h"
#include "lang.h"
using namespace std;

void openCell(char* desk[], char* desk2[], int x, int y, int sizeX, int sizeY, bool& lost) {
	if (x < 0 || x >= sizeY || y < 0 || y >= sizeX || desk2[y][x] != '#') return;
	desk2[y][x] = desk[y][x];
	if (desk[y][x] == '0') {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				openCell(desk, desk2, x + i, y + j, sizeX, sizeY, lost);
			}
		}
	}
	else if (desk[y][x] == '*') {
		lost = true;
	}
}
void setFlag(char* desk2[], int x, int y, int sizeX, int sizeY, int& flags, int mines, string fc, string nofleft) {
	if (desk2[y][x] == '#') {
		if (flags >= mines) {
			cout << nofleft;
			return;
		}
		desk2[y][x] = 'F';
		flags++;
	}
	else if (desk2[y][x] == 'F') {
		desk2[y][x] = '#';
		flags--;
	}
	else {
		cout << fc;
	}
	printDesk(desk2, sizeX, sizeY);
}
bool checkWin(char* desk[], char* desk2[], int sizeX, int sizeY) {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			if (desk2[i][j] == '#' && desk[i][j] != '*') {
				return false;
			}
			if (desk2[i][j] == 'F' && desk[i][j] != '*') {
				return false;
			}
		}
	}
	return true;
}