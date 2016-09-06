/*#pragma once
#include "catch.hpp"
#include "snakeServer.h"
SCENARIO("Test snake server game") {
	GIVEN("create new game server") {
		snakeServer testServer;
		WHEN("connect a client") {
			testServer.moveSnakeInGame(1, "127.0.0.1");
			testServer.moveSnakeInGame(1, "10.60.17.19");
			THEN("game number increase") {
				CHECK(testServer.numberOfClients() == 2);
			}
		}
		WHEN("disconnect a client") {
			testServer.moveSnakeInGame(1, "127.0.0.1");
			testServer.moveSnakeInGame(1, "10.60.17.19");
			testServer.removeGame("127.0.0.1");
			THEN("Number of games decrease") {
				CHECK(testServer.numberOfClients() == 1);
			}
		}
	}
}*/