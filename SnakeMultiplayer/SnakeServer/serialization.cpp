#pragma once
#include "serialization.h"
void serialize(flatbuffers::FlatBufferBuilder &builder, std::vector<boost::property_tree::ptree> data,int playerNumber) {
	auto board = snakedata::Createboarddata(builder, data.at(0).get<int>("table.width"), data.at(0).get<int>("table.height"));
	auto snakefood = snakedata::Createsnakefooddata(builder,data.at(0).get<int>("snakefood.x"), data.at(0).get<int>("snakefood.y"));
	std::vector<flatbuffers::Offset<snakedata::snakebodydata>> allsnakesdata;
	
	for (int j = 0; j < data.size(); j++) {
		std::vector<flatbuffers::Offset<snakedata::snakebodypoint>> snakebodypoints;
		for (int i = 0; i < data.at(j).get<int>("snakebody.length"); i++) {
			snakebodypoints.push_back(snakedata::Createsnakebodypoint(builder, data.at(j).get<int>("snakebody.point." + std::to_string(i) + ".x"), data.at(j).get<int>("snakebody.point." + std::to_string(i) + ".y")));
		};
		auto snakebodypointsvector = builder.CreateVector(snakebodypoints);
		allsnakesdata.push_back(snakedata::Createsnakebodydata(builder,snakebodypointsvector));
	}
	auto allsnakesdatavector = builder.CreateVector(allsnakesdata);
	
	auto gamestatus = builder.CreateString(data.at(playerNumber).get<std::string>("game_status"));
	auto gamescore = data.at(playerNumber).get<int>("game_score");
	auto numberofsnakes = data.size();
	auto snake_data = snakedata::Createsnakepacketdata(builder,allsnakesdatavector, board,snakefood,gamestatus,gamescore,numberofsnakes);
	snakedata::FinishsnakepacketdataBuffer(builder, snake_data);
		
}
