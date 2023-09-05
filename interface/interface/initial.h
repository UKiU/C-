#ifndef INITIAL_H
#define INITIAL_H


#include <QtGui/QMainWindow>
#include "ui_initial.h"
#include "Data.h"


class initial : public QMainWindow
{
	Q_OBJECT

public:
	initial(QWidget *parent = 0, Qt::WFlags flags = 0);
	~initial();

private:
	Ui::initialClass ui;

	Data* datawin;
	double gkjkd,gkjhd,gkjmd,dzsrsnl,dzsbj;
	double cyzgs,hyzgs,oyzgs;
	int N;


private slots:
	double ongkjkd();
	double ongkjhd();
	double ongkjmd();
	int oncyzgs();
	int onhyzgs();
	int onoyzgs();
	double ondzsrsnl();
	double ondzsbj();
	int ondzgs();
	void onstart();
};

#endif // INITIAL_H

