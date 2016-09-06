#pragma once
#include "boost\asio.hpp"
#include "boost\property_tree\ptree.hpp"
#include "deserialization.h"
class networkConnection {
public:
	networkConnection(boost::asio::io_service &ioService, std::string &snakemove);
	void startConnection(boost::property_tree::ptree &data);
	void sendSnakeMove();
	void readGameData(boost::property_tree::ptree &data);
private:
	boost::asio::ip::tcp::socket clientSocket;
	boost::asio::ip::tcp::resolver resolver;
	int buf;
	std::vector<uint8_t> dataBuffer;
	std::string &move;
};
