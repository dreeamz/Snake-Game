#pragma once

#include"UserInterface.h"
#include<iostream>
#include<iomanip>



void UserInterface::print_snake_and_fruit(Snake& snake) {
	gotoXY(snake.head.coor_X, snake.head.coor_Y);
	std::cout << snake._HEAD;
	gotoXY(snake.fruit.coor_X, snake.fruit.coor_Y);
	std::cout << snake.fruit.symb;
	for (int i = 0; i < snake.tail_length; i++)
	{
		gotoXY(snake.tail[i].coor_X, snake.tail[i].coor_Y);
		std::cout << snake.tail->symb;
	}
}
void UserInterface::delete_snake_and_fruit(Snake& snake) {

	gotoXY(snake.head.coor_X, snake.head.coor_Y);
	std::cout << ' ';
	gotoXY(snake.fruit.coor_X, snake.fruit.coor_Y);
	std::cout << ' ';
	for (int i = 0; i < snake.tail_length; i++)
	{
		gotoXY(snake.tail[i].coor_X, snake.tail[i].coor_Y);
		std::cout << ' ';
	}
}


////USER-INTERFACE Class functions

char* UserInterface::page_1() {
	print_welcome_label();

	print_nickname_label();
	set_buffer();
	system("CLS");

	return  get_buffer();
}



void UserInterface::page_2(Timer& timer, const std::vector<Records::PairRecord>& records) {
	print_ui_field();
	print_snake_speed_label();
	print_player_label();
	print_snake_field();
	print_timer(timer);
	print_records(records);
	print_info_text();
	print_timer_label();
	print_score_label();
	print_records_label();
	print_press_label();
	print_P_for_play_label();
	print_S_for_gamespeed_label();
	print_I_for_info_label();
	print_H_for_help_label();
	print_Esc_for_exit_label();
}



//Setters
void UserInterface::set_buffer() {
	//Probably 20 symbol is enough for User Name and Surname
	const int buffer_limit = 20;

	if (_buffer)
		delete[] _buffer;

	_buffer = new char[20];
	std::cin >> _buffer;
}

//Getters
char* UserInterface::get_buffer() {
	return _buffer;
}



//Welcome label
void UserInterface::print_welcome_label() {

	for (size_t y = 0; y < 5; y++)
		switch (y)
		{
		case 0:
			gotoXY(_console_columns / 2 - 25, (_console_rows / 2 - 5) + y);
			std::cout << "  #     # ##### #     ##### ###### ##   ## #####  ";
			break;
		case 1:
			gotoXY(_console_columns / 2 - 25, (_console_rows / 2 - 5) + y);
			std::cout << "  #     # #     #     #     #    # # # # # #      ";
			break;
		case 2:
			gotoXY(_console_columns / 2 - 25, (_console_rows / 2 - 5) + y);
			std::cout << "  #  #  # ####  #     #     #    # #  #  # ####   ";
			break;
		case 3:
			gotoXY(_console_columns / 2 - 25, (_console_rows / 2 - 5) + y);
			std::cout << "  # # # # #     #     #     #    # #     # #      ";
			break;
		case 4:
			gotoXY(_console_columns / 2 - 25, (_console_rows / 2 - 5) + y);
			std::cout << "  ##   ## ##### ##### ##### ###### #     # #####  ";
			break;
		}
}

void UserInterface::print_ui_field() {
	for (size_t y = 0; y < _uifield_length; y++)
		for (size_t x = 0; x < _uifield_width; x++)
		{
			if (y == 0 || y == _uifield_length - 1) {
				gotoXY(_uifield_X_coor + x, _uifield_Y_coor + y);
				std::cout << "=";
			}
			else if (x == 0 || x == _uifield_width - 1)
			{
				gotoXY(_uifield_X_coor + x, _uifield_Y_coor + y);
				std::cout << "|";
			}
		}
	for (size_t i = 0; i < _console_columns - _uifield_width - _uifield_X_coor; i++)
	{
		gotoXY(_uifield_X_coor + _uifield_width + i, _uifield_Y_coor);
		std::cout << '=';
	}
	for (size_t i = 0; i < _console_columns - _uifield_width - _uifield_X_coor; i++)
	{
		gotoXY(_uifield_X_coor + _uifield_width + i, _uifield_Y_coor + _uifield_length - 1);
		std::cout << '=';
	}
}


// [] - prints field for Snake
void UserInterface::set_snake_field_coor(int coor_X, int coor_Y, int length, int width) {
	_sfield_coor_X = coor_X;
	_sfield_coor_Y = coor_Y;
	_sfield_length = length;
	_sfield_width = width;
}

void UserInterface::print_snake_field() {
	for (size_t y = 0; y < _sfield_length; y++)
		for (size_t x = 0; x < _sfield_width; x++)
		{
			//left and right borders 
			if (y == 0 || y == _sfield_length - 1) {
				gotoXY(_sfield_coor_X + x, _sfield_coor_Y + y);
				std::cout << "#";
			}
			//top and bottom borders
			else if (x == 0 || x == _sfield_width - 1) {
				gotoXY(_sfield_coor_X + x, _sfield_coor_Y + y);
				std::cout << "#";
			}
		}
}


//Functions for Records
void UserInterface::print_records_label() {
	int coor_X = _sfield_coor_X + _sfield_width + 1;
	int coor_Y = _sfield_coor_Y + 1;
	gotoXY(coor_X, coor_Y);
	std::cout << "Records:";
}
void UserInterface::print_records(const std::vector<Records::PairRecord>& records) {
	int coor_X = _sfield_coor_X + _sfield_width + 2;
	int coor_Y = _sfield_coor_Y + 3;

	int records_count = records.size();
	for (size_t i = 0, skip = 0; i < records_count; i++, skip++)
	{
		gotoXY(coor_X, coor_Y + i + skip);
		std::cout << records[i].nickname << '-' << records[i].score;
	}
}


//Page 1 nickname label
void UserInterface::print_nickname_label() {
	int _distance_to_WELCOME = 3 + _middle_Y_coor;

	gotoXY(_middle_X_coor - 10, _distance_to_WELCOME);
	std::cout << "Nickname: ";
	gotoXY(_middle_X_coor, _distance_to_WELCOME);
};

//Page 2 
//Player label
void UserInterface::print_player_label() {
	int coor_X = _uifield_X_coor + 2;
	int coor_Y = _uifield_Y_coor + 1;
	gotoXY(coor_X, coor_Y);
	std::cout << "Player:";
}

//User nickname
void UserInterface::print_user_nickname(const char* nickname) {
	int player_label_length = 7;
	int coor_X = _uifield_X_coor + player_label_length + 2;
	int coor_Y = _uifield_Y_coor + 1;

	gotoXY(coor_X, coor_Y);
	std::cout << nickname;
}

#pragma region Print Score and Timer

void UserInterface::print_score_label() {
	int coor_X = _sfield_coor_X + _sfield_width - 13;
	int coor_Y = _sfield_coor_Y - 2;
	gotoXY(coor_X, coor_Y);
	std::cout << "Score:";
}
void UserInterface::print_user_score(int score) {
	int score_label_length = 6;
	int coor_X = _sfield_coor_X + _sfield_width - score_label_length;
	int coor_Y = _sfield_coor_Y - 2;
	gotoXY(coor_X, coor_Y);
	std::cout << std::setw(6) << std::setfill(' ') << score;
}
void UserInterface::print_timer_label() {
	int timer_length = 5;
	int timer_label_lenght = 7;
	int length = timer_length + timer_label_lenght;
	int coor_X = _sfield_coor_X + _sfield_width - length;
	int coor_Y = _sfield_coor_Y - 1;
	gotoXY(coor_X - 1, coor_Y);
	std::cout << "Timer: ";
}

void UserInterface::print_timer(Timer& timer) {
	int timer_length = 5;
	int coor_X = _sfield_coor_X + _sfield_width - 5;
	int coor_Y = _sfield_coor_Y - 1;
	gotoXY(coor_X, coor_Y);
	timer.print_timer();
}


#pragma endregion

void UserInterface::print_snake_speed_label() {
	int coor_X = _uifield_X_coor + 2;
	int coor_Y = _uifield_Y_coor + 3;
	gotoXY(coor_X, coor_Y);
	std::cout << "Snake speed - ";
}
void UserInterface::print_snake_speed(int speed) {
	int snake_speed_length = 14;
	int coor_X = _uifield_X_coor + 2 + snake_speed_length;
	int coor_Y = _uifield_Y_coor + 3;
	gotoXY(coor_X, coor_Y);
	std::cout << speed;
}

void UserInterface::print_press_label() {

	int coor_X = _uifield_X_coor + 2;
	int coor_Y = _sfield_coor_Y + 3;
	gotoXY(coor_X, coor_Y);
	std::cout << "Press:";
}
void UserInterface::print_P_for_play_label() {
	int coor_X = _uifield_X_coor + 3;
	int coor_Y = _sfield_coor_Y + 5;
	gotoXY(coor_X, coor_Y);
	std::cout << "P - to Play";
}

void UserInterface::print_S_for_gamespeed_label() {
	int coor_X = _uifield_X_coor + 3;
	int coor_Y = _sfield_coor_Y + 7;
	gotoXY(coor_X, coor_Y);
	std::cout << "S - to change Snake";
	gotoXY(coor_X + 4, coor_Y + 1);
	std::cout << "speed";
}
void UserInterface::print_H_for_help_label() {
	int coor_X = _uifield_X_coor + 3;
	int coor_Y = _sfield_coor_Y + 10;
	gotoXY(coor_X, coor_Y);
	std::cout << "H - for Help ";
}
void UserInterface::print_I_for_info_label() {
	int coor_X = _uifield_X_coor + 3;
	int coor_Y = _sfield_coor_Y + 12;
	gotoXY(coor_X, coor_Y);
	std::cout << "I - for Info";
}
void UserInterface::print_Esc_for_exit_label() {
	int coor_X = _uifield_X_coor + 3;
	int coor_Y = _sfield_coor_Y + 14;
	gotoXY(coor_X, coor_Y);
	std::cout << "Esc - for Exit";
}

void UserInterface::print_info_text() {
	int coor_X = _uifield_width + _uifield_X_coor + 1;
	int coor_Y = _sfield_coor_Y + 3;
	gotoXY(coor_X, _uifield_Y_coor + 1);
	std::cout << "INFO";

	for (int i = 0, skip = 0; i < _info.STR_COUNT; i++, skip++)
	{
		gotoXY(coor_X, coor_Y + i + skip);
		std::cout << _info.info_str[i];
	}
}
void UserInterface::print_help_text() {
	int coor_X = _uifield_width + _uifield_X_coor + 1;
	int coor_Y = _sfield_coor_Y + 3;
	gotoXY(coor_X, _uifield_Y_coor + 1);
	std::cout << "HELP";

	for (int i = 0, skip = 0; i < _help.STR_COUNT; i++, skip++)
	{
		gotoXY(coor_X, coor_Y + i + skip);
		std::cout << _help.help_str[i];
	}
}
void UserInterface::print_snake_speed_text() {
	int coor_X = _uifield_width + _uifield_X_coor + 1;
	int coor_Y = _sfield_coor_Y + 3;
	gotoXY(coor_X, _uifield_Y_coor + 1);
	std::cout << "SNAKE SPEED";
	gotoXY(coor_X, _uifield_Y_coor + 4);
	std::cout << "Press:";
	for (int i = 0, skip = 0; i < _snake_speed.STR_COUNT; i++, skip++)
	{
		gotoXY(coor_X, coor_Y + i + skip);
		std::cout << _snake_speed.snake_speed_str[i];
	}
}

void UserInterface::right_side_clear() {
	int coor_X = _uifield_width + _uifield_X_coor + 1;
	int coor_Y = _uifield_Y_coor + 1;

	for (int i = 0, skip = 0; i < _uifield_length - 2; i++, skip++)
	{
		for (size_t j = 0; j < _console_columns - _uifield_width - _uifield_X_coor + 1; j++)
		{
			gotoXY(coor_X + j, coor_Y + i);
			std::cout << ' ';
		}
	}
}





UserInterface::~UserInterface() {
	if (_buffer)
		delete[]_buffer;
}

