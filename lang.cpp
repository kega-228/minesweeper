#include "lang.h"
#include <iostream>
using namespace std;
void langs(string& welcome, string& sd, string& isd, string& cm, string& icm, string& cord, string& cf, string& cordf, string& icord, string& fc, string& lost, string& congrat, string& nofleft, lang language) {
	if (language == ukr) {
		welcome = "Вітаємо у грі Сапер!\n";
		sd = "Виберіть розмір поля (x, y)(максимум 100 х 100): ";
		isd = "Неправильний розмір поля! Використовується розмір 10 х 10.\n";
		cm = "Введіть кількість мін (максимум половина поля ((x*y) / 2) ): ";
		icm = "Неправильна кількість мін! Використовується 15.\n";
		cord = "Введіть координати точки (x y) (-1 для прапорця): ";
		cf = "Прапорців ще є: ";
		cordf = "Введіть координати клітинки для прапорця (x y): ";
		icord = "Неправильні координати!\n";
		fc = "Цю клітинка вже відкрито або позначено!\n";
		lost = "Ви програли!\n";
		congrat = "Вітаємо, ви виграли!\n";
		nofleft = "Вже всі прапорці поставлені!\n";
	}
	else {
		welcome = "Welcome to Minesweeper!\n";
		sd = "Select the field size (x, y) (maximum 100 x 100): ";
		isd = "Invalid field size! Using default size: 10 x 10.\n";
		cm = "Enter the number of mines (maximum half of the field ((x*y) / 2) ): ";
		icm = "Invalid number of mines! Using default: 15.\n";
		cord = "Enter cell coordinates (x y) (-1 for flag): ";
		cf = "Flags remaining: ";
		cordf = "Enter cell coordinates for a flag (x y): ";
		icord = "Invalid coordinates!\n";
		fc = "This cell has already been opened or marked!\n";
		lost = "You lost!\n";
		congrat = "Congratulations, you won!\n";
		nofleft = "All flags have already been placed!\n";
	}
}
