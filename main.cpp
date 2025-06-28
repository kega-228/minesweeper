#include <iostream>
#include <windows.h>
#include "start.h"
#include "Game.h"
#include "lang.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	string welcome, sd, isd, cm, icm, cord, cf, cordf, icord, fc, lost, congrat, nofleft;
    SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(static_cast<unsigned int>(time(0)));
	int sizeX, sizeY;
	short lg;
	lang language;
	do{
		cout << "choose your language (1-ua, 2-en): ";
		cin >> lg;
		switch (lg) {
		case 1:
			language = ukr;
			break;
		case 2:
			language = eng;
			break;
		default:
			cout << "incorrect choice.\n";
			break;
		}
	} while (lg != 1 && lg != 2);
	langs(welcome, sd, isd, cm, icm, cord, cf, cordf, icord, fc, lost, congrat, nofleft, language);
	cout << welcome;
	cout << sd;
	cin >> sizeX >> sizeY;
	if (sizeX < 2 || sizeX > 100 || sizeY < 2 || sizeY > 100) {
		cout << isd;
		sizeX = sizeY = 10;
	}
	cout << cm;
	int mines;
	cin >> mines;
	if (mines < 1 || mines > sizeX * sizeY / 2) {
		cout << icm;
		mines = 15;
	}
	int flags = 0;
	char** desk = new char*[sizeX];
	for (int i = 0; i < sizeX; i++) {
		desk[i] = new char[sizeY];
	}
	char** desk2 = new char*[sizeX];
	for (int i = 0; i < sizeX; i++) {
		desk2[i] = new char[sizeY];
	}
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			desk[i][j] = '#';
			desk2[i][j] = '#';
		}
	}
	createDesk(desk, sizeX, sizeY, mines );
	printDesk(desk2, sizeX, sizeY );
	bool gameover = false, win = false;
	while (!gameover && !win) {
		cords cor;
		cout << cord;
		cin >> cor.x;
		if (cor.x == -1) {
			cout << cf << (mines - flags) << "\n";
			cout << cordf;
			cin >> cor.x >> cor.y;
			if (cor.x < 0 || cor.x >= sizeY || cor.y < 0 || cor.y >= sizeX) {
				cout << icord;
				continue;
			}
			setFlag(desk2, cor.x, cor.y, sizeX, sizeY, flags, mines, fc, nofleft);
			continue;
		}
		cin	>> cor.y;
		if (cor.x < 0 || cor.x >= sizeY || cor.y < 0 || cor.y >= sizeX) {
			cout << icord;
			continue;
		}
		if (desk2[cor.y][cor.x] != '#') {
			cout << fc;
			continue;
		}
		openCell(desk, desk2, cor.x, cor.y, sizeX, sizeY, gameover);
		printDesk(desk2, sizeX, sizeY);
		win = checkWin(desk, desk2, sizeX, sizeY);
	}
	if (gameover) {
		cout << lost;
		printDesk(desk, sizeX, sizeY);
	}
	else {
		cout << congrat;
	}
	ofstream out("score.txt", ios::app);
	if (out.is_open()) {
		out << "Size: " << sizeX << " x " << sizeY << "\n";
		out << "Mines: " << mines << "\n";
		out << "Flags used: " << flags << "\n";
		if (win) {
			out << "Result: Win\n";
		} else {
			out << "Result: Lose\n";
		}
	}
	for (int i = 0; i < sizeX; i++) {
		delete[] desk[i];
		delete[] desk2[i];
	}
	delete[] desk;
	delete[] desk2;
	return 0;
}