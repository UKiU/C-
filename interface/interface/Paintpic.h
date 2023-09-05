#ifndef PAINTPIC_H
#define PAINTPIC_H

#include <QFrame>

class Paintpic : public QFrame
{
	Q_OBJECT

public:
	Paintpic(QWidget *parent);
	~Paintpic();
	

	QPoint origin0();


private:
	void paintEvent(QPaintEvent * event);
};

#endif // PAINTPIC_H
