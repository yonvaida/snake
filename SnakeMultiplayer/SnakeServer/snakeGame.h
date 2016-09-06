#pragma once
#include "snake.h"
#include "table.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>
#include <iostream>
#include "snakePlayer.h"
#include "serialization.h"
#include "boost\property_tree\json_parser.hpp"

class snakeGame {
public:
	snakeGame();
	void joinGame(std::shared_ptr<snakePlayer> player);
	void leaveGame(std::shared_ptr<snakePlayer> player);
	void getGameBoard(boost::property_tree::ptree &data);
	snakeFood food;	
	void getGameFood(boost::property_tree::ptree &data);
	void getAllSnakes(boost::property_tree::ptree &allSnakes);
	std::vector<boost::property_tree::ptree> allSnakes; 
	std::vector<point> collisionList();
	void moveSnakes();
private:
	table board;
	snakeFood foodpoint;
	std::set<std::shared_ptr<snakePlayer>> playersList;
	
};

