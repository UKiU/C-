#ifndef MYWIN_H
#define MYWIN_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QVBoxLayout>//垂直布局
#include <QLineEdit>
#include <QPlainTextEdit>


class Mywin:public QWidget{
	Q_OBJECT//每次继承都要添加宏
public:
	Mywin(QWidget *parent);
	~Mywin();
private:
	QPushButton* m_button;
	QLineEdit* m_lineetext;
	QPlainTextEdit* m_plaintext;
};

#endif // MYWIN_H