#pragma once
#include "snake.h"
#include <iostream>
#include <vector>
#include <algorithm>

Snake::Snake() {
};
void Snake::startSnake() {
	point snakehead;
	snakehead.x = 0;
	snakehead.y = 0;
	snakebody.resize(0);
	snakeBodyMoves.resize(0);
	elongate(snakehead, Direction::right);
}
void Snake::move() {
	if (nextHeadPosition().x == food.x && nextHeadPosition().y==food.y) {
		elongate(food, snakeBodyMoves.back());
	}
	else {
		for (int index = 0; index < snakebody.size(); index++) {
			switch (snakeBodyMoves[index])
			{
			case Direction::left:
				snakebody[index].x--;
				break;
			case Direction::right:
				snakebody[index].x++;
				break;
			case Direction::up:
				snakebody[index].y--;
				break;
			case Direction::down:
				snakebody[index].y++;
				break;
			default:
				break;
			};
			snakeBodyMoves[index] = (index<snakebody.size() - 1) ? snakeBodyMoves[index + 1] : snakeBodyMoves[index];
		}
	}
}
point Snake::nextHeadPosition() {
	point position;
	position = snakebody.back();
	switch (snakeBodyMoves.back()) {
	case Direction::left:
		position.x--;
		break;
	case Direction::right:
		position.x++;
		break;
	case Direction::up:
		position.y--;
		break;
	case Direction::down:
		position.y++;
		break;
	}
	return position;
};

void Snake::changeDirection(Direction direction) {
	snakeBodyMoves.back() = direction;
	move();
}

bool Snake::findFood(point foodPoint) {

	if (snakebody.back().x == foodPoint.x && snakebody.back().y == foodPoint.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Snake::onTable(int width,int height) {
	return (snakebody.back().x<0 || snakebody.back().y<0 || snakebody.back().x>width-1 || snakebody.back().y>height-1) ? false : true;
} 

void Snake::elongate(point elongatePoint,Direction direction) {
	snakebody.push_back(elongatePoint);
	snakeBodyMoves.push_back(direction);
}

bool Snake::collision(std::vector<point> collisionList) {
	point temppoint = snakebody.back();
	for (int i = 0; i < collisionList.size(); i++) {
		if (temppoint.x == collisionList.at(i).x && temppoint.y == collisionList.at(i).y) return true;
	}
	return false;	
}

void Snake::getData(boost::property_tree::ptree &data) {
	
	for (int i = 0; i < snakebody.size(); i++) {
		data.put("snakebody.point."+ std::to_string(i)+".x", snakebody[i].x);
		data.put("snakebody.point." + std::to_string(i) + ".y", snakebody[i].y);
		data.put("snakebody.point." + std::to_string(i) + ".move", (int)snakeBodyMoves[i]);
		data.put("snakebody.length", snakebody.size());
	}
}

void Snake::setFoodPoint(point foodpoint) {
	food = foodpoint;
}