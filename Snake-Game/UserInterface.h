#pragma once
#include"UsefulFunctions.h"
#include<string>
#include"Snake.h"
#include"Timer.h"
#include"Records.h"
#include<vector>


struct InfoText {
	static const int STR_COUNT = 8;
	std::string info_str[STR_COUNT] = {
		{"  This game was created by"},
		{"  developers from Ukrainian"},
		{"  company PushkaStudios.  "},
		{"  We hope you will enjoy it."},
		{"  For additional information "},
		{"  about us, you can visit  "},
		{"  our website at"},
		{"  'pushkastudios.com'"} };
};

struct HelpText {
	static const int STR_COUNT = 4;
	std::string help_str[STR_COUNT] = {
		{"  a , <-  :    Left "},
		{"  d , ->  :    Rigth"},
		{"  s , down_arrow :   Down "},
		{"  w , up_arrow   :   Up  "} };
};

struct SnakeSpeedText {
	static const int STR_COUNT = 4;
	std::string snake_speed_str[STR_COUNT] = {
		{"  3  - Beginner"},
		{"  5  - Easy"},
		{"  7  - Normal"},
		{"  9  - Hard"} };
};







class UserInterface {
public:
	//Menu pages
	char* page_1();
	void page_2(Timer& timer, const std::vector<Records::PairRecord>& records);

	//Prints new and delete old snake coordinates
	void print_snake_and_fruit(Snake& snake);
	void delete_snake_and_fruit(Snake& snake);


	void print_user_nickname(const char* nickname);
	void print_records(const std::vector<Records::PairRecord>& records);
	void print_user_score(int score);
	void print_timer(Timer& timer);
	void set_snake_field_coor(int coor_X, int coor_Y, int length, int width);
	void print_snake_speed(int speed);

#pragma region Prints constant data (labels, frame, text,snake_field) that will not be changed
	//this function will invoke all below functions
	void print_welcome_label();
	void print_nickname_label();
	void print_ui_field();
	void print_snake_field();
	void print_player_label();
	void print_snake_speed_label();
	void print_records_label();
	void print_score_label();
	void print_timer_label();
	void print_press_label();
	void print_P_for_play_label();
	void print_H_for_help_label();
	void print_I_for_info_label();
	void print_S_for_gamespeed_label();
	void print_Esc_for_exit_label();
	//Print constant text on the rigth side
	void print_info_text();
	void print_help_text();
	void print_snake_speed_text();
#pragma endregion



	//clear constant text on the right side 
	void right_side_clear();
	//Setters
	void set_buffer();
	//Getters
	char* get_buffer();

	~UserInterface();
private:


	//Constant text on the rigth side 
	InfoText _info;
	HelpText _help;
	SnakeSpeedText _snake_speed;


	//buffer for User's Name and Surname
	char* _buffer = nullptr;

	//Console size and coor
	int _console_columns = get_console_columns();
	int _console_rows = get_console_rows();
	int _middle_Y_coor = _console_rows / 2;
	int _middle_X_coor = _console_columns / 2;


	//Frame size and coor
	int _uifield_length = _console_rows - 5;
	int _uifield_width = _console_columns - 40;
	int _uifield_X_coor = 5;
	int _uifield_Y_coor = 2;

	//SnakeField size and coor
	int _sfield_coor_X;
	int _sfield_coor_Y;
	int _sfield_length;
	int _sfield_width;
};




