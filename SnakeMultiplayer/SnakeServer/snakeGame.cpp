#pragma once
#include "snakeGame.h"
snakeGame::snakeGame() {
	board.resizeTable(50,50);
	food.randomize(50, 50);
}
void snakeGame::joinGame(std::shared_ptr<snakePlayer> player) {
	playersList.insert(player);
}
void snakeGame::leaveGame(std::shared_ptr<snakePlayer> player) {
	int i = 0;
	for(auto snakeplayer:playersList){
		if (player == snakeplayer) {
			allSnakes.erase(allSnakes.begin()+i);
		}
		else { i++; }
	}
	playersList.erase(player);
}
void snakeGame::moveSnakes() {
	boost::property_tree::ptree data;
	int i = 0;
	for (auto player : playersList) {
		data.clear();
		player->movesnake();
		if (allSnakes.size() < i + 1) {
			getGameBoard(data);
			getGameFood(data);
			player->getsnake(data);
			allSnakes.push_back(data);
		}else{
			player->getsnake(allSnakes.at(i));
		}
		i++;
	}
	i = 0;
	for (auto player : playersList) {
		std::stringstream datastring;
			player->sendSnakeData(allSnakes,i);	
			i++;
	}	
}
void snakeGame::getGameBoard(boost::property_tree::ptree &data) {
	board.getData(data);
}
void snakeGame::getGameFood(boost::property_tree::ptree &data) {
	foodpoint.getData(data);
}
std::vector<point> snakeGame::collisionList() {
	std::vector<point> list;
	point snakePoint;
	for (auto playerSnake : allSnakes) {
		for (int i = 1; i < playerSnake.get<int>("snakebody.length"); i++) {
			snakePoint.x = playerSnake.get<int>("snakebody.point." + std::to_string(i) + ".x");
			snakePoint.y = playerSnake.get<int>("snakebody.point." + std::to_string(i) + ".y");
			list.push_back(snakePoint);
		}
	}
	return list;
};
