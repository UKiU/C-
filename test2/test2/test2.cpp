#include "test2.h"

test2::test2(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(
		ui.btntest1,
		SIGNAL(clicked(bool)),
		this,
		SLOT(OneClicked(bool))
		);
}

test2::~test2()
{

}

int test2::OneClicked(bool checked)
{
	ui.texttest1->setPlainText("hello,world");
	return 0;
}