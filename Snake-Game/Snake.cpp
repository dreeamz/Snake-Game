#pragma once

#include"Snake.h"


void Snake::set_direction(eDirection direction) {

	switch (direction)
	{
	case Snake::Stop:
		break;
	case Snake::Left:
		if (tail[0].coor_X == head.coor_X)
			dir = Snake::eDirection::Left;
		break;
	case Snake::Right:
		if (tail[0].coor_X == head.coor_X)
			dir = Snake::eDirection::Right;
		break;
	case Snake::Up:
		if (tail[0].coor_Y == head.coor_Y)
			dir = Snake::eDirection::Up;
		break;
	case Snake::Down:
		if (tail[0].coor_Y == head.coor_Y)
			dir = Snake::eDirection::Down;
		break;
	}
}

void Snake::move() {
	switch (dir)
	{
	case Snake::eDirection::Left:head.coor_X--;
		break;
	case Snake::eDirection::Right:head.coor_X++;
		break;
	case Snake::eDirection::Up:head.coor_Y--;
		break;
	case Snake::eDirection::Down:head.coor_Y++;
		break;
	}
}

void Snake::move_tail() {
	int tail_coor_X = head.coor_X;
	int tail_coor_Y = head.coor_Y;
	int tail_coor_X1;
	int tail_coor_Y1;
	if (tail_length > 1)
		for (int i = 0; i < tail_length; i++)
		{
			tail_coor_X1 = tail[i].coor_X;
			tail_coor_Y1 = tail[i].coor_Y;
			tail[i].coor_X = tail_coor_X;
			tail[i].coor_Y = tail_coor_Y;
			tail_coor_X = tail_coor_X1;
			tail_coor_Y = tail_coor_Y1;
		}
	else
	{
		tail[0].coor_X = head.coor_X;
		tail[0].coor_Y = head.coor_Y;
	}
}

bool Snake::crashes_in_tail() {
	for (int i = 0; i < tail_length; i++)
	{
		if (head.coor_X == tail[i].coor_X && head.coor_Y == tail[i].coor_Y)
			return true;
	}
	return false;
}
bool Snake::eat_fruit() {
	if (head.coor_X == fruit.coor_X && head.coor_Y == fruit.coor_Y)
	{
		tail_length++;
		return true;
	}
	return false;
}