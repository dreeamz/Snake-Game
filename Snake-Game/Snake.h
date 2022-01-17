#pragma once




class Snake {
	struct Coordinates {
		int coor_X;
		int coor_Y;
		char symb;
	};
public:
	const char _HEAD = '0';
	enum eDirection { Stop = 0, Left, Right, Up, Down };
	eDirection dir = Stop;
	Coordinates tail[100];
	Coordinates head;
	Coordinates fruit;

	int tail_length = 1;

	void set_direction(eDirection direction);
	void move();
	void move_tail();
	bool crashes_in_tail();
	bool eat_fruit();


};