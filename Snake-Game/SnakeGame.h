#pragma once

#include"UserInterface.h"
#include"Snake.h"
#include"Timer.h"
#include"Records.h"
#include"User.h"



class SnakeGame {
public:

	void run();
	void setup();
	void set_selection();
	void execute_selection();
	void snake_speed_selection();
	void game_start();
	void input();
	void logic();
	void slow_snake_speed();
	void fruit_score_increase();
	bool get_is_allow_to_add_pair();
	void add_pair_to_records();
	void records_array_sort();
private:

	enum SnakeSpeed { beginner = 3, easy = 5, normal = 7, hard = 9 };
	struct SnakeField {
		const int length = 20;
		const int width = 24;
		const int coor_X = 29;
		const int coor_Y = 6;
	};

	SnakeField _sfield;
	Timer _timer;
	User _user;

	std::vector<Records::PairRecord> _records_array;
	int _records_array_size = 0;
	bool _is_allow_to_add_pair = false;
	bool _is_pair_added_to_records = false;

	Records _records;
	Records::PairRecord _current_pair;

	UserInterface _UI;
	Snake _snake;

	SnakeSpeed _snake_speed;

	bool _is_gameover = false;
	bool _is_paused = false;
	bool _is_exit = false;
	int  _selection = 0;
	bool _is_selection_correct = false;
	int _score_for_fruit;
};