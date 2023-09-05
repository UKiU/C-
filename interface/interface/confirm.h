#ifndef CONFIRM_H
#define CONFIRM_H

#include <QDialog>
#include "ui_confirm.h"

class confirm : public QDialog
{
	Q_OBJECT
 
public:
	confirm(QWidget *parent = 0);
	void showtext();
	
	~confirm();
	QString gkj,fzs,dzs;

private:
	Ui::confirm ui;

private slots:
	void onconfirm1();
	void onconfirm2();
};

#endif // CONFIRM_H
