#include <QApplication>
#include "dogemainwindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	DogeMainWindow* main = new DogeMainWindow;
	main->show();

	return app.exec();
}
