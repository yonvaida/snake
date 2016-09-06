#pragma once
#include "catch.hpp"
#include "table.h"


SCENARIO("Test for table class") {

	GIVEN("") {
		WHEN("Create table without dimensions ") {
			table board;
			boost::property_tree::ptree data;
			board.getData(data);
			THEN("Create a table with dimensions 100X100") {
				CHECK(data.get<int>("table.width") == 100);
				CHECK(data.get<int>("table.height") == 100);
			}
		}
		WHEN("Create a table with specific dimensions"){
			table board(3,3);
			boost::property_tree::ptree data;
			board.getData(data);
			THEN("Create a table with dimensions 3x3") {
				CHECK(data.get<int>("table.width") == 3);
				CHECK(data.get<int>("table.height") == 3);
			}
		}
		WHEN("Create a table with specific dimensions and resize") {
			table board(3, 3);
			board.resizeTable(9,9);
			boost::property_tree::ptree data;
			board.getData(data);
			THEN("change table dimensions") {
				CHECK(data.get<int>("table.width") == 9);
				CHECK(data.get<int>("table.height") == 9);
			}
		}
	}
}