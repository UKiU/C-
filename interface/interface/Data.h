#ifndef DATA_H
#define DATA_H

#include <QWidget>
#include "ui_Data.h"

class Data : public QWidget
{
	Q_OBJECT

public:
	Data(QWidget *parent = 0);
	~Data();

	Data returnData();
	Ui::Data ui;


private:
	

private slots:
	void onrestart();

};

#endif // DATA_H
