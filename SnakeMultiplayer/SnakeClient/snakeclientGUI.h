#pragma once
#include <QKeyEvent>
#include <qobject.h>
#include <qlabel.h>
#include "boost\property_tree\ptree.hpp"
#include <QPainter>
#include <QLabel>

enum class Direction { left, right, up, down, stay,newGame };

class label :public QLabel {
public:
	void keyPressEvent(QKeyEvent * event);
	Direction direction = Direction::right;
};
char moveSnake(Direction direction);

void drawSnake(boost::property_tree::ptree &snakeData, std::unique_ptr<QPainter> &painter,std::unique_ptr<label> &l);