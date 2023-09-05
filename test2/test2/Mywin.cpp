#include "Mywin.h"

Mywin::Mywin(QWidget *parent)
	: QWidget(parent)//单冒号初始化列表
{
	m_button=new QPushButton(this);//指定父窗口为自身
	m_button->setText("hello,qt");
	m_button->setGeometry(100,100,200,50);//相对父窗口左上角
	
	m_lineetext=new QLineEdit(this);
	m_plaintext=new QPlainTextEdit(this);

}

Mywin::~Mywin(){

}