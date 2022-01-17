#pragma once

#include"SnakeGame.h"
#include<conio.h>
#include<thread>
#include<chrono>
#include<iostream>
#include<algorithm>



void SnakeGame::run() {
	_user.set_nickname(_UI.page_1());

	_records_array = _records.get_records();
	_records_array_size = _records_array.size();

	_UI.set_snake_field_coor(_sfield.coor_X, _sfield.coor_Y, _sfield.length, _sfield.width);
	_UI.print_user_nickname(_user.get_nickname());
	_UI.print_user_score(_user.get_score());
	_UI.page_2(_timer, _records_array);
	_UI.print_snake_speed(_snake_speed);

	_snake_speed = SnakeSpeed::hard;
	while (!_is_exit)
	{
		set_selection();
		execute_selection();

	}
	gotoXY(50, 28);

}



void SnakeGame::set_selection() {

	_selection = _getch();
	if (_selection != 224) {
		_selection = tolower(_selection);
		switch (_selection)
		{
		case 'i':
			_is_selection_correct = true;
			break;
		case'h':_is_selection_correct = true;
			break;
		case'p':_is_selection_correct = true;
			break;
		case 27:_is_selection_correct = true;
			break;
		case 's':_is_selection_correct = true;
			break;
		default:_is_selection_correct = false;
			break;
		}
	}
	else {
		//there is always undefined behavior when user press arrows up down right left
		_selection = _getch();
		_selection = 0;
	}

}




void SnakeGame::execute_selection() {
	if (_is_selection_correct) {

		switch (_selection)
		{
		case 'i':_UI.right_side_clear();
			_UI.print_info_text();
			break;
		case'h':_UI.right_side_clear();
			_UI.print_help_text();
			break;
		case 27:
			_is_exit = true;
			break;
		case 'p':
			game_start();
			break;
		case 's':_UI.right_side_clear();
			_UI.print_snake_speed_text();
			snake_speed_selection();
			_UI.print_snake_speed(_snake_speed);
			_UI.right_side_clear();
			_UI.print_info_text();
			break;
		}
	}
}





void SnakeGame::snake_speed_selection() {
	int selection = 0;
	bool is_correct_selection = false;
	while (!is_correct_selection)
	{
		selection = _getch();
		switch (selection)
		{
		case 51:_snake_speed = SnakeSpeed::beginner;
			is_correct_selection = true;
			break;
		case 53:_snake_speed = SnakeSpeed::easy;
			is_correct_selection = true;
			break;
		case 55:_snake_speed = SnakeSpeed::normal;
			is_correct_selection = true;
			break;
		case 57:_snake_speed = SnakeSpeed::hard;
			is_correct_selection = true;
			break;
		}

	}
}

void SnakeGame::input() {
	int input = 0;
	if (_kbhit())
	{//if keyboard was hitten
		input = _getch();
		if (input != 224 && input != 65)
			switch (input)
			{
			case 'w': _snake.set_direction(Snake::eDirection::Up);
				break;
			case 'a': _snake.set_direction(Snake::eDirection::Left);
				break;
			case 's':_snake.set_direction(Snake::eDirection::Down);
				break;
			case 'd': _snake.set_direction(Snake::eDirection::Right);
				break;
			case 32:  _is_paused = true;
				break;
			}
		else
			switch (_getch()) {
			case 72://Up arrow
				_snake.set_direction(Snake::eDirection::Up);
				break;
			case 75://Left arrow
				_snake.set_direction(Snake::eDirection::Left);
				break;
			case 80://Down arrow				
				_snake.dir = Snake::eDirection::Down;
				break;
			case 77:
				//Rigth arrow
				_snake.set_direction(Snake::eDirection::Right);
				break;
			}
	}
}
void SnakeGame::logic() {
	//Move tail after head
	_snake.move_tail();
	//Then move head
	_snake.move();

	//Check if snake crashed into the borders
	if (_snake.head.coor_X == _sfield.coor_X + _sfield.width - 1)
		_is_gameover = true;
	else if (_snake.head.coor_X == _sfield.coor_X)
		_is_gameover = true;

	if (_snake.head.coor_Y == _sfield.coor_Y + _sfield.length - 1)
		_is_gameover = true;
	else if (_snake.head.coor_Y == _sfield.coor_Y)
		_is_gameover = true;

	//Check if snake creshed into its tail
	if (_snake.crashes_in_tail())
		_is_gameover = true;

	if (_snake.eat_fruit())
	{
		_snake.fruit.coor_X = rand() % (_sfield.width - 2) + 1 + _sfield.coor_X;
		_snake.fruit.coor_Y = rand() % (_sfield.length - 2) + 1 + _sfield.coor_Y;
		fruit_score_increase();
	}

	int seconds = _timer.get_time();
	// points are scoring, according to this formula
	int score = _snake_speed * seconds + _score_for_fruit;
	_user.set_score(score);
	_current_pair.score = score;
}
void SnakeGame::fruit_score_increase() {
	switch (_snake_speed)
	{
	case 3:
		_score_for_fruit += 3;
		break;
	case 5:
		_score_for_fruit += 5;
		break;
	case 7:
		_score_for_fruit += 7;
		break;
	case 9:
		_score_for_fruit += 9;
		break;
	}
}
void SnakeGame::slow_snake_speed() {
	switch (_snake_speed)
	{
	case 3:
		std::this_thread::sleep_for(std::chrono::milliseconds(600));
		break;
	case 5:
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		break;
	case 7:
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		break;
	case 9:
		std::this_thread::sleep_for(std::chrono::milliseconds(75));
		break;
	}
}

//is current pair allowed to be added in _records_array
bool SnakeGame::get_is_allow_to_add_pair()
{
	if (_records_array_size == _records._MAX_RECORDS_COUNT) {

		_is_allow_to_add_pair = _current_pair.score > _records_array[_records_array_size - 1].score;
	}
	//If there is an empty place then we can add new pair without comparison
	else
		_is_allow_to_add_pair = true;

	return _is_allow_to_add_pair;
}

void SnakeGame::add_pair_to_records() {
	if (_is_allow_to_add_pair) {
		if (_records_array_size < _records._MAX_RECORDS_COUNT) {

			_records_array.push_back(_current_pair);
			_is_pair_added_to_records = true;
			_records._is_added = true;
			_records_array_size++;


		}
		else if (_records_array_size == _records._MAX_RECORDS_COUNT)
			_records_array[_records_array_size - 1] = _current_pair;
		_is_pair_added_to_records = true;
	}
}
void SnakeGame::records_array_sort() {
	std::sort(_records_array.begin(), _records_array.end());
}

void SnakeGame::game_start() {
	setup();
	while (!_is_gameover)
	{
		_UI.print_user_score(_user.get_score());
		_UI.print_records(_records_array);
		_UI.print_snake_and_fruit(_snake);
		_UI.print_timer(_timer);
		slow_snake_speed();
		input();
		_UI.delete_snake_and_fruit(_snake);
		logic();


	}

	if (get_is_allow_to_add_pair()) {
		add_pair_to_records();
		records_array_sort();
	}

	if (_is_pair_added_to_records)
		_records.set_records(_records_array);
	_timer.stop_timer();
	_user.set_score(0);

}

void SnakeGame::setup() {
	_score_for_fruit = 0;
	_is_gameover = false;
	slow_snake_speed();
	_user.set_score(0);

	_current_pair.nickname = _user.get_nickname();
	_current_pair.score = _user.get_score();

	_snake.tail_length = 1;
	_snake.head.coor_X = _sfield.width / 2 + _sfield.coor_X;
	_snake.head.coor_Y = _sfield.length / 2 + _sfield.coor_Y;
	_snake.tail[0].coor_X = _snake.head.coor_X + 1;
	_snake.tail[0].coor_Y = _snake.head.coor_Y;
	_snake.tail->symb = 'o';
	_snake.dir = Snake::eDirection::Left;
	_snake.fruit.symb = char(3);
	_snake.fruit.coor_X = rand() % (_sfield.width - 2) + 1 + _sfield.coor_X;
	_snake.fruit.coor_Y = rand() % (_sfield.length - 2) + 1 + _sfield.coor_Y;


	_timer.start_In_another_thread();
}

