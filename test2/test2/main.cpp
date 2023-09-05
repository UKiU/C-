#include "test2.h"
#include "Mywin.h"
#include <QtGui/QApplication>
#include <QtCore/qglobal.h>
#include <QtGui/QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	test2 w;
	w.show();

	/*Mywin w(NULL);
	w.show();*/
	
	//QWidget w;
	//w.setGeometry(0,0,400,300);//²»º¬±ß¿ò
	//w.move(0,0);//º¬±ß¿ò
	//w.show();
	return a.exec();
}
