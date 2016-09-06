#pragma once
#include "boost\asio.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <boost\property_tree\ptree.hpp>
#include <QLabel>
#include <QPicture>
#include <QPainter>
#include <qapplication.h>
#include "QtCore\qobject.h"
#include <qtimer.h>
#include <memory>
#include "snakeclient.h"
#include "snakeclientGUI.h"
#include "deserialization.h"
#include "boost\thread.hpp"
#include "boost\date_time\posix_time\posix_time.hpp"
boost::mutex mutex;
boost::property_tree::ptree data;
std::string move;

int draw(int argc, char * argv[]) {
	boost::property_tree::ptree snakeData;
	QApplication a(argc, argv);
	std::unique_ptr<label> l(new label);
	std::unique_ptr<QPixmap> pixmap(new QPixmap(550, 500));
	std::unique_ptr<QPainter> painter(new QPainter(pixmap.get()));
	std::unique_ptr<QTimer> timer(new QTimer);
	move = moveSnake(l->direction);;
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		mutex.lock();
		snakeData = data;
		move = moveSnake(l->direction);
		mutex.unlock();
		if (!snakeData.empty()) {
			drawSnake(snakeData, painter, l);
		}
		
		l->setPixmap(*pixmap);
	});
	timer->start(50);	
	l->setGeometry(300, 300, 50 * 11, 50 * 10);
	l->show();
	return a.exec();
}

void clientCommunication() {
	std::string lastmove;
	boost::asio::io_service ioService;
	std::unique_ptr<networkConnection> connection(new networkConnection(ioService,move));
	connection->startConnection(data);
	ioService.run();
}
int main(int argc, char * argv[])
{
	boost::thread drawThread(boost::bind(draw,argc, argv));
	boost::thread communication(boost::bind(&clientCommunication));
	communication.join();
	drawThread.join();
}