#pragma once
#include <boost\asio.hpp>
#include <websocketpp\config\asio_no_tls.hpp>
#include <websocketpp\server.hpp>
#include "boost\property_tree\ptree.hpp"
#include <deserialization.h>

class proxyServer {
public:
	proxyServer(boost::asio::io_service &ioService);
	void startConnection();
	void read();
	void send();
	void setMove(std::string snakeMove);
	void getData(boost::property_tree::ptree &data);
	void closeConnection();
private:
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::resolver resolver;
	int buf;
	std::vector<uint8_t> dataBuffer;
	boost::property_tree::ptree snakeData;
	std::string move;
};