#pragma once
#include <iostream>
using namespace std;
void openCell(char* desk[], char* desk2[], int x, int y, int sizeX, int sizeY, bool& lost);
void setFlag(char* desk2[], int x, int y, int sizeX, int sizeY, int& flags, int mines, string fc, string nofleft);
bool checkWin(char* desk[], char* desk2[], int sizeX, int sizeY);