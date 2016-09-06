#include "proxyServer.h"
proxyServer::proxyServer(boost::asio::io_service &ioService):socket(ioService),resolver(ioService) {

};
void proxyServer::startConnection() {
	boost::asio::ip::tcp::resolver::query query("127.0.0.1", "32560");
	boost::asio::ip::tcp::resolver::iterator endpoint = resolver.resolve(query);
	boost::asio::async_connect(socket, endpoint, [&](const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator iterator) {
		read();
	});
};
void proxyServer::read() {
	boost::asio::async_read(socket, boost::asio::buffer(&buf, 4), [&](const boost::system::error_code &ec, size_t length) {
		if (!ec) {
			dataBuffer.resize(buf);
			boost::asio::async_read(socket, boost::asio::buffer(dataBuffer, buf), [&](const boost::system::error_code ec, size_t length) {
				deserialize(dataBuffer, snakeData);
				send();
				read();
			});
		}
	});
}
void proxyServer::send() {
	
	boost::asio::async_write(socket, boost::asio::buffer(move), [](const boost::system::error_code ec,size_t length) {});


}
void proxyServer::getData(boost::property_tree::ptree &data) {
	data = snakeData;
}
void proxyServer::setMove(std::string snakeMove) {
	move = snakeMove;
};
void proxyServer::closeConnection() {
	socket.close();
};