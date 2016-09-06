#pragma once
#include "snakeServer.h"

snakeServer::snakeServer(boost::asio::io_service &ioService, boost::asio::ip::tcp::endpoint &endpoint) :acceptor(ioService, endpoint), socket(ioService),snakeTimer(ioService) {
	acceptConnection();
	makemoves();
};
void snakeServer::acceptConnection() {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		
		if (!ec) {
			std::make_shared<snakeGame_session>(std::move(socket), game)->startSession();
			std::cout << "Connection accepted" << std::endl;
		}
		
		acceptConnection();
	});
}
void snakeServer::makemoves() {
	snakeTimer.expires_from_now(boost::posix_time::milliseconds(200));
	snakeTimer.async_wait([&](const boost::system::error_code ec) {
		game.moveSnakes();
		makemoves();
	});
}