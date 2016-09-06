#include "snakeclientGUI.h"

void label::keyPressEvent(QKeyEvent * event) {
	if (event->key() == Qt::Key_Up) {
		direction = Direction::up;
	}
	if (event->key() == Qt::Key_Down) {
		direction = Direction::down;
	}
	if (event->key() == Qt::Key_Left) {
		direction = Direction::left;
	}
	if (event->key() == Qt::Key_Right) {
		direction = Direction::right;
	}
	if (event->key() == Qt::Key_F5) {
		direction = Direction::newGame;
	}
}
char moveSnake(Direction direction) {
	//direction is converted in it's index as string to be sent
	switch (direction) {
	case Direction::left:
		return '0';
	case Direction::right:
		return '1';
	case Direction::up:
		return '2';
	case Direction::down:
		return '3';
	case Direction::newGame:
		return '5';
	default:
		return '4';
	}
}

void drawSnake(boost::property_tree::ptree &snakeData, std::unique_ptr<QPainter> &painter, std::unique_ptr<label> &l) {
	if (snakeData.empty()) {
		painter->fillRect(500, 0, 50, 500, Qt::darkGray);
	}
	else {
		if (snakeData.get<std::string>("game_status") == "GAME OVER") {
			QFont font;
			font.setPixelSize(50);
			font.setBold(true);
			painter->setFont(font);
			painter->drawText(snakeData.get<int>("table.width") * 2, snakeData.get<int>("table.height") * 2, "GAME OVER");
			painter->drawText(snakeData.get<int>("table.width") * 2 + 60, snakeData.get<int>("table.height") * 2 + 50, "SCORE:");
			painter->drawText(snakeData.get<int>("table.width") * 2 + 130, snakeData.get<int>("table.height") * 2 + 100, QString::number(snakeData.get<int>("game_score")));
			painter->drawText(snakeData.get<int>("table.width") * 2, snakeData.get<int>("table.height") * 2 + 150, "F5 - New Game");
		}
		else {
			if (l->direction == Direction::newGame)l->direction = Direction::right;
			QFont font;
			font.setPixelSize(10);
			font.setBold(true);
			painter->setFont(font);
			painter->fillRect(0, 0, snakeData.get<int>("table.width") * 10, snakeData.get<int>("table.height") * 10, Qt::gray);
			painter->drawPixmap(snakeData.get<int>("snakefood.x") * 10, snakeData.get<int>("snakefood.y") * 10, 10, 10, QPixmap("strawberry.png"));
			painter->fillRect(snakeData.get<int>("table.width") * 10, 0, 50, snakeData.get<int>("table.height") * 10, Qt::darkGray);
			painter->drawText(snakeData.get<int>("table.width") * 10 + 5, 10, "SCORE:");
			painter->drawText(snakeData.get<int>("table.width") * 10 + 20, 10 + 20, QString::number(snakeData.get<int>("game_score")));
			for (int j = 0; j < snakeData.get<int>("numberofsnakes"); j++) {
				for (int i = 0; i < snakeData.get<int>("snakebody."+std::to_string(j)+".length"); i++) {
					painter->fillRect(snakeData.get<int>("snakebody."+std::to_string(j)+".point." + std::to_string(i) + ".x") * 10, snakeData.get<int>("snakebody."+std::to_string(j)+".point." + std::to_string(i) + ".y") * 10, 10, 10, Qt::Dense2Pattern);
				};
			}
			
		}
	}
	

};