#include "Mywin.h"

Mywin::Mywin(QWidget *parent)
	: QWidget(parent)//��ð�ų�ʼ���б�
{
	m_button=new QPushButton(this);//ָ��������Ϊ����
	m_button->setText("hello,qt");
	m_button->setGeometry(100,100,200,50);//��Ը��������Ͻ�
	
	m_lineetext=new QLineEdit(this);
	m_plaintext=new QPlainTextEdit(this);

}

Mywin::~Mywin(){

}