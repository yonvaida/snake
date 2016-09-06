#include "deserialization.h"
void deserialize(std::vector<unsigned char> &buf,boost::property_tree::ptree &data) {
	auto snake_data = snakedata::Getsnakepacketdata(buf.data());
	auto numberofsnakes = snake_data->numberofsnakes();
	data.put("numberofsnakes", numberofsnakes);
	data.put("table.width", snake_data->board()->width());
	data.put("table.height", snake_data->board()->height());
	data.put("snakefood.x", snake_data->snakefood()->x());
	data.put("snakefood.y", snake_data->snakefood()->y());
	data.put("game_status", snake_data->gamestatus()->str());
	data.put("game_score", snake_data->gamescore());
	for (int i = 0; i < numberofsnakes; i++) {
	auto snakebodylength = snake_data->allsnakes()->Get(i)->snakebody()->Length();
	for (int j = 0; j < snakebodylength; j++) {
		data.put("snakebody." + std::to_string(i) + ".point." + std::to_string(j) + ".x", snake_data->allsnakes()->Get(i)->snakebody()->Get(j)->x());
		data.put("snakebody." + std::to_string(i) + ".point." + std::to_string(j) + ".y", snake_data->allsnakes()->Get(i)->snakebody()->Get(j)->y());
	}
	data.put("snakebody." + std::to_string(i) + ".length", snake_data->allsnakes()->Get(i)->snakebody()->Length());
	}
	
};