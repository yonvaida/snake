#include "snakeclient.h"

networkConnection::networkConnection(boost::asio::io_service &ioService,std::string &snakemove) :clientSocket(ioService),resolver(ioService),move(snakemove) {
}
void networkConnection::startConnection(boost::property_tree::ptree &data) {
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::ip::tcp::resolver::iterator end;
	boost::asio::ip::tcp::resolver::query query("127.0.0.1", "32560");
	endpoint = resolver.resolve(query);
	boost::asio::async_connect(clientSocket, endpoint, [&](const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator iterator) {
		if (!ec) {
			sendSnakeMove();
			readGameData(data);
		}
	});
}
void networkConnection::sendSnakeMove() {
	boost::asio::async_write(clientSocket, boost::asio::buffer(move), [&](const boost::system::error_code &ec, size_t length) {
		if (!ec) {
		}
	});
}
void networkConnection::readGameData(boost::property_tree::ptree &data) {
	boost::asio::async_read(clientSocket, boost::asio::buffer(&buf, 4), [&](const boost::system::error_code &ec, size_t length) {
		if (!ec) {			
			dataBuffer.resize(buf);
			boost::asio::async_read(clientSocket, boost::asio::buffer(dataBuffer, buf), [&](const boost::system::error_code ec, size_t length) {
				deserialize(dataBuffer, data);
				sendSnakeMove();
				readGameData(data);
			});
		}
	});
}