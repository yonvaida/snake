#define CATCH_CONFIG_RUNNER
#pragma once
#include "boost\asio.hpp"
#include <string.h>
#include <iostream>
#include "main.h"
#include "snakeServer.h"


int main(int argc, char *argv[])
{
	//int result = Catch::Session().run(argc, argv);
		try {
			
		boost::asio::io_service ioService;
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 32560);
		//boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 1080);
		snakeServer gameServer(ioService,endpoint );
		ioService.run();	
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what()<<"   --error" << "\n";
		}
	
	return 0;
}

