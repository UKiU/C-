#include "initial.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	initial w;
	Data d;
	w.show();
	return a.exec();
}

