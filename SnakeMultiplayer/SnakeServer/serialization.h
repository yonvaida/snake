#pragma once
#include "flatbuffer\snakedata_generated.h"
#include <boost\property_tree\ptree.hpp>
void serialize(flatbuffers::FlatBufferBuilder &builder, std::vector<boost::property_tree::ptree> data, int playerNumber);
