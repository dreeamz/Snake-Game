#pragma once




class Timer {
public:

	void start_In_another_thread();
	int get_time();

	void start_timer();
	void print_timer();

	void stop_timer();

private:


	bool _is_timer_printed = false;
	int _timer_coor_X = 0, _timer_coor_Y = 0;
	bool _is_ticking = false;
	int _minutes = 0, _seconds = 0;
};

