#include "Paintpic.h"
#include<QPainter>

Paintpic::Paintpic(QWidget *parent)
	: QFrame(parent)
{
	
}

Paintpic::~Paintpic()
{

}
QPoint Paintpic::origin0(){
	QRect r=this->rect();
	return r.center();
}



void Paintpic::paintEvent(QPaintEvent * event){
	QPainter pic(this);
	QPen pen;
	pen.setColor(Qt::red);
	pic.setPen(pen);
	pic.setBrush(Qt::NoBrush);
	
}
