#pragma once
#include "table.h"
table::table() {
	width = 100;
	height = 100;
}
table::table(int w,int h) {
	width = w;
	height = h;
}
void table::resizeTable(int w,int h) {
	width = w;
	height = h;
}

void table::getData(boost::property_tree::ptree &data) {
	data.put("table.width", width);
	data.put("table.height", height);
}