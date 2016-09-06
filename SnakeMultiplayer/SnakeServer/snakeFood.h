#pragma once
#include "main.h"
#include <stdlib.h>
#include <time.h>


class snakeFood {

public:
	snakeFood();
	snakeFood(int x, int y);
	void randomize(int tableWidth, int tableHeight);
	void getData(boost::property_tree::ptree &data);
private:
	point foodPosition;
};