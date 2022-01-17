#pragma once



#pragma region Goto XY Function
// I use gotoXY cause i don't want flickering console 
// all time while it's beeing update;

void gotoXY(int coor_X, int coor_Y);

#pragma endregion

#pragma region Get size of Console

int  get_console_columns();
int get_console_rows();

#pragma endregion
