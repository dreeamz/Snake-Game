#pragma once

#include"Timer.h"
#include"UsefulFunctions.h"

#include<iostream>
#include <thread>


//for milliseconds
#include <chrono>

//for setfill('0');
#include <iomanip>

#include<mutex>


void Timer::start_In_another_thread()
{
	std::thread _thread_for_tick(&Timer::start_timer, this);
	_thread_for_tick.detach();
}



void Timer::start_timer() {
	time_t _START = time(0);
	_is_ticking = true;

	std::this_thread::sleep_for(std::chrono::microseconds(1000));

	while (_is_ticking) {
		_seconds = difftime(time(0), _START);
		if (_seconds == 60) {
			_minutes++;
			_START = time(0);
		}
	}
}
void Timer::stop_timer() {
	_is_ticking = false;
}

int Timer::get_time() {

	if (!_minutes)
		return _seconds;

	return _seconds * _minutes;

}

void Timer::print_timer() {

	if ((_seconds > 9 && _seconds < 60) && (_minutes < 10))
		std::cout << '0' << _minutes << ':' << _seconds;
	else if (_seconds < 10 && _minutes < 10)
		std::cout << std::setw(2) << std::setfill('0') << _minutes << ':'
		<< std::setw(2) << std::setfill('0') << _seconds;

	_is_timer_printed = true;
}