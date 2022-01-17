#pragma once

#include"User.h"
#include<iostream>
//for setfill('0');
#include <iomanip>




//Setters
void User::set_nickname(const char* nickname) {
	//+1 for \0
	const int name_lenght = strlen(nickname) + 1;

	_nickname = new char[name_lenght];
	for (size_t i = 0; i < name_lenght; i++)
		_nickname[i] = nickname[i];
}

void User::set_score(int score) {
	_score = score;
}

//Getters
char* User::get_nickname() {
	return _nickname;
}

int User::get_score() {
	return _score;
}



void User::print_nickname()
{
	std::cout << _nickname;
}

void User::print_score() {
	std::cout << std::setw(6) << std::setfill(' ') << _score;
}

//Distructor
User::~User() {
	delete[] _nickname;
}
