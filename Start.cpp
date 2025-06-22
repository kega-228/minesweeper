#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include "start.h"
using namespace std;

void createDesk(char* desk[], int sizeX, int sizeY, int mines) {
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			desk[i][j] = '0';
		}
	}
	for (int i = 0; i < mines; i++) {
		int x = rand() % (sizeY - 1) + 1;
		int y = rand() % (sizeX - 1) + 1;
		if (desk[x][y] == '*') {
			i--;
			continue;
		}
		desk[rand() % (sizeY - 1) + 1][rand() % (sizeX - 1) + 1] = '*';
	}
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (desk[i][j] == '*') continue;
			int count = 0;
			for (int x = -1; x <= 1; x++) {
				for (int y = -1; y <= 1; y++) {
					if (i + x < 0 || i + x >= sizeY || j + y < 0 || j + y >= sizeX) continue;
					if (desk[i + x][j + y] == '*') count++;
				}
			}
			desk[i][j] = count + '0';
		}
	}
}

void printDesk(char* desk[], int sizeX, int sizeY) {
	cout << "\t ";
	for (int i = 0; i < sizeX; i++) {
		if (i <= 10){
			cout << " ";
		}
		cout << i << " ";
	}
	cout << "\n\t ";
	for (int i = 0; i < sizeX; i++) {
		cout <<"---";
	}
	cout << "\n";
	for (int i = 0; i < sizeY; i++) {
		cout << i << "\t|";
		for (int j = 0; j < sizeX; j++) {
			cout << " " << desk[i][j] << " ";
		}
		cout << endl;
	}
}