#include "Data.h"
#include <QPainter>

Data::Data(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.Restart,SIGNAL(clicked(bool)),this,SLOT(onrestart()));
}

Data::~Data()
{

}
void Data::onrestart(){
	this->close();
}
