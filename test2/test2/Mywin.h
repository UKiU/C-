#ifndef MYWIN_H
#define MYWIN_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QVBoxLayout>//��ֱ����
#include <QLineEdit>
#include <QPlainTextEdit>


class Mywin:public QWidget{
	Q_OBJECT//ÿ�μ̳ж�Ҫ��Ӻ�
public:
	Mywin(QWidget *parent);
	~Mywin();
private:
	QPushButton* m_button;
	QLineEdit* m_lineetext;
	QPlainTextEdit* m_plaintext;
};

#endif // MYWIN_H