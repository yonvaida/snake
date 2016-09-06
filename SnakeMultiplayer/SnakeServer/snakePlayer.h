#pragma once
class snakePlayer {
public:
	virtual void movesnake() = 0;
	virtual void getsnake(boost::property_tree::ptree &data) = 0;
	virtual void sendSnakeData(std::vector<boost::property_tree::ptree> &data,int playerNumber) = 0;
};