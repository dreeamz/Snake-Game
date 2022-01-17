#pragma once

#include"UsefulFunctions.h"
#include<windows.h>

int get_console_columns() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int get_console_rows() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return  csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}


void gotoXY(int coor_X, int coor_Y) {
	COORD c;
	c.X = coor_X;
	c.Y = coor_Y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
};
