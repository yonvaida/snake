#include "flatbuffer\snakedata_generated.h"
#include "boost\property_tree\ptree.hpp"
#include <iostream>
void deserialize(std::vector<unsigned char> &buf, boost::property_tree::ptree &data);