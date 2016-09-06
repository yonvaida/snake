#pragma once
#include "boost\asio.hpp"
#include "boost\asio\buffer.hpp"
#include "snakeGame.h"
#include "snakePlayer.h"
#include "boost\enable_shared_from_this.hpp"
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
class snakeGame_session :public snakePlayer,public std::enable_shared_from_this<snakeGame_session> {

public:
	snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame);
	void startSession();
	void readSnakeMove();
	void sendSnakeData(std::vector<boost::property_tree::ptree> &data,int playerNumber);
	void initiateSnake();
	void movesnake();
	void newGame();
	void getsnake(boost::property_tree::ptree &data);

private:
	flatbuffers::FlatBufferBuilder builder;
	boost::asio::ip::tcp::socket snakeSocket;
	snakeGame &game;
	std::vector<char>buf;
	Snake playerSnake;
	int direction;
	int bufferlength;
	int score;
	std::string gameStatus;
};
