#pragma once
#include "main.h"

class table {
public:
	table();
	table(int w,int h);
	void resizeTable(int w,int h);
	void getData(boost::property_tree::ptree &data);
private:
	int width;
	int height;
};