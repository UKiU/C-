#include "initial.h"
#include "confirm.h"
//#include "formula.h"
//#include "eupdate.h"
#include "ui_Data.h"
#include "ogl.h"
initial::initial(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	datawin =new Data(this);
	datawin->setWindowFlags(Qt::Window);
	gkjkd=1,gkjhd=1,gkjmd=1,dzsrsnl=1,dzsbj=1;
	cyzgs=1,hyzgs=1,oyzgs=1,N=1;

	connect(ui.gkjkd,SIGNAL(currentIndexChanged(int)),this,SLOT(ongkjkd()));
	connect(ui.gkjhd,SIGNAL(currentIndexChanged(int)),this,SLOT(ongkjhd()));
	connect(ui.gkjmd,SIGNAL(currentIndexChanged(int)),this,SLOT(ongkjmd()));
	connect(ui.oyzgs,SIGNAL(currentIndexChanged(int)),this,SLOT(onoyzgs()));
	connect(ui.cyzgs,SIGNAL(currentIndexChanged(int)),this,SLOT(oncyzgs()));
	connect(ui.hyzgs,SIGNAL(currentIndexChanged(int)),this,SLOT(onhyzgs()));
	connect(ui.dzsrsnl,SIGNAL(currentIndexChanged(int)),this,SLOT(ondzsrsnl()));
	connect(ui.dzsbj,SIGNAL(currentIndexChanged(int)),this,SLOT(ondzsbj()));
	connect(ui.dzgs,SIGNAL(currentIndexChanged(int)),this,SLOT(ondzgs()));
	
	connect(ui.gkjkd,SIGNAL(editTextChanged ( const QString)),this,SLOT(ongkjkd()));
	connect(ui.gkjhd,SIGNAL(editTextChanged ( const QString)),this,SLOT(ongkjhd()));
	connect(ui.gkjmd,SIGNAL(editTextChanged ( const QString)),this,SLOT(ongkjmd()));
	connect(ui.oyzgs,SIGNAL(editTextChanged ( const QString)),this,SLOT(onoyzgs()));
	connect(ui.cyzgs,SIGNAL(editTextChanged ( const QString)),this,SLOT(oncyzgs()));
	connect(ui.hyzgs,SIGNAL(editTextChanged ( const QString)),this,SLOT(onhyzgs()));
	connect(ui.dzsrsnl,SIGNAL(editTextChanged ( const QString)),this,SLOT(ondzsrsnl()));
	connect(ui.dzsbj,SIGNAL(editTextChanged ( const QString)),this,SLOT(ondzsbj()));
	connect(ui.dzgs,SIGNAL(editTextChanged ( const QString)),this,SLOT(ondzgs()));
	
	connect(ui.start,SIGNAL(clicked(bool)),this,SLOT(onstart()));
}

int initial::ondzgs(){
	int index=ui.dzgs->currentIndex();
	QString temp_gs=ui.dzgs->currentText();
	N=temp_gs.toInt();
	return N;
}
double initial::ongkjkd(){
	int index=ui.gkjkd->currentIndex();
	QString temp_kd=ui.gkjkd->currentText();
	gkjkd=temp_kd.toDouble();
	
	return gkjkd;
}
double initial::ongkjhd(){
	int index=ui.gkjhd->currentIndex();
	QString temp_hd=ui.gkjhd->currentText();
	gkjhd=temp_hd.toDouble();

	return gkjhd;
}
double initial::ongkjmd(){
	int index=ui.gkjmd->currentIndex();
	QString temp_md=ui.gkjmd->currentText();
	gkjmd=temp_md.toDouble();

	return gkjmd;
}
int initial::oncyzgs(){
	int index=ui.cyzgs->currentIndex();
	QString temp=ui.cyzgs->currentText();
	cyzgs=temp.toInt();

	return cyzgs;
}
int initial::onhyzgs(){
	int index=ui.hyzgs->currentIndex();
	QString temp=ui.hyzgs->currentText();
	hyzgs=temp.toInt();

	return hyzgs;
}
int initial::onoyzgs(){
	int index=ui.oyzgs->currentIndex();
	QString temp=ui.oyzgs->currentText();
	oyzgs=temp.toInt();

	return oyzgs;
}
double initial::ondzsrsnl(){
	int index=ui.dzsrsnl->currentIndex();
	QString temp=ui.dzsrsnl->currentText();
	dzsrsnl=temp.toDouble();

	return dzsrsnl;
}
double initial::ondzsbj(){
	int index=ui.dzsbj->currentIndex();
	QString temp=ui.dzsbj->currentText();
	dzsbj=temp.toDouble();

	return dzsbj;
}

void initial::onstart(){
	confirm con(this);
	con.gkj=QString::fromLocal8Bit("光刻胶宽度；")+QString::number(gkjkd)+"\n"
		+QString::fromLocal8Bit("光刻胶厚度；")+QString::number(gkjhd)+"\n"+
		QString::fromLocal8Bit("光刻胶密度；")+QString::number(gkjmd);
	double yzl=(double)((12*cyzgs+hyzgs+16*oyzgs)/(cyzgs+hyzgs+oyzgs)),
		yzxs=(double)((6*cyzgs+hyzgs+8*oyzgs)/(cyzgs+hyzgs+oyzgs));
	
	con.fzs=QString::fromLocal8Bit("光刻胶分子式：")
		+"C"+QString::number(cyzgs)+"H"+QString::number(hyzgs)+"O"+QString::number(oyzgs)+"\n"
		+QString::fromLocal8Bit("平均原子量：")+QString::number(yzl)+"\n"
		+QString::fromLocal8Bit("平均原子序数：")+QString::number(yzxs);
	con.dzs=QString::fromLocal8Bit("电子束入射能量：")+QString::number(dzsrsnl)+"\n"
		+QString::fromLocal8Bit("电子束半径：")+QString::number(dzsbj)+"\n"
		+QString::fromLocal8Bit("模拟电子个数：")+QString::number(N);
	con.showtext();


	int ret=con.exec();
	if(ret==QDialog::Accepted){
	
		////创建Q3DScatter三维散点图类对象
		//QtDataVisualization::Q3DScatter scatter;
		//scatter.setFlags(scatter.flags() ^ Qt::FramelessWindowHint);
		////新建序列和数据，在序列中加入3个点，把序列添加到图形
		//QtDataVisualization::QScatter3DSeries *series = new QtDataVisualization::QScatter3DSeries;
		//QtDataVisualization::QScatterDataArray data;
		//data << QVector3D(0.5f, 0.5f, 0.5f) << QVector3D(-0.3f, -0.5f, -0.4f) << QVector3D(0.0f, -0.3f, 0.2f);
		//series->dataProxy()->addItems(data);
		//scatter.addSeries(series);
		//scatter.show();


		//srand((unsigned)time(NULL));
		//substrate *Subtest1;
		//epos EP;
		//vector<epos> *eline;

		//double w,l,d,E,R;
		//int c,h,o,i,j,N,NS;
		//int num;

		//cout<<"本次模拟__个电子轨迹："<<endl;
		//cin>>N;
		//eline=new vector<epos>[N];


		////初始化材料
		//cout<<"模拟__层材料："<<endl;
		//cin>>NS;
		//Subtest1=new substrate[NS];
		//for(i=0;i<NS;i++)
		//{
		//	cout<<"初始化第"<<i+1<<"层介质："<<endl;
		//	cout<<"输入介质材料序号："<<endl;
		//	cin>>num;
		//	Subtest1[i].type=num;
		//	switch(Subtest1[i].type)
		//	{
		//		//PMMA
		//	case 0:
		//		{
		//		cout<<"请输入材料宽度（nm），厚度（nm），密度（g/nm^3）："<<endl;
		//		cin>>w>>l>>d;
		//
		//		cout<<"请输入光刻胶CHO原子个数"<<endl;
		//		cin>>c>>h>>o;
		//		subinitialize(Subtest1[i],num,w,l,d,c,h,o);
		//		break;
		//		}
		//		//Si
		//	case 1:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;

		//			subinitialize(w,l,2.33e-21,28,14,0.822,172.25,Subtest1[i]);
		//			break;
		//		}
		//		//Al
		//	case 2:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;

		//			subinitialize(w,l,2.7e-21,27,13,0.815,163,Subtest1[i]);
		//			break;
		//		}
		//
		//		//Ni
		//	case 3:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;
		//			subinitialize(w,l,8.9e-21,58.69,28,0.83,304.499,Subtest1[i]);
		//			break;
		//		}
		//		//Fe
		//	case 4:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;
		//			subinitialize(w,l,7.86e-21,56,26,0.83,285.422,Subtest1[i]);
		//			break;
		//		}
		//		//Cu
		//	case 5:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;
		//			subinitialize(w,l,8.96e-21,63.546,29,0.83,314.051,Subtest1[i]);
		//			break;
		//		}
		//		//Ag
		//	case 6:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;
		//			subinitialize(w,l,10.53e-21,108,47,0.852,487,Subtest1[i]);
		//			break;
		//		}
		//		//Au
		//	case 7:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;
		//			subinitialize(w,l,19.32e-21,197,79,0.851,796.675,Subtest1[i]);
		//			break;
		//		}
		//		//SiO2
		//	case 8:
		//		{
		//			cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
		//			cin>>w>>l;
		//			subinitialize(w,l,2.2e-21,20,10,0.82,115,Subtest1[i]);
		//		}
		//	default:break;
		//		}
		//	//显示材料
		//	Subtest1[i].display(Subtest1[i].type);
		//
		//}
		////初始化电子束
		//cout<<"请输入电子束入射能量(kev)："<<endl;
		//cin>>E;
		//einitialize(EP,Subtest1[1],dzsrsnl);
		//cout<<"请输入电子束半径："<<endl;
		//cin>>R;
	
		//for(i=0;i<N;i++)
		//{
		//	cout<<"第"<<i<<"个电子轨迹："<<endl;
		////初始化电子入射位置
		//	XYinitialize(EP,dzsbj);
		//	EP.display();

		////更新，直到电子能量降到50ev,测试先用1kev
		//	eline[i].push_back(EP);
		//	for(j=1;j<=NS;j++)
		//	{
		//		while((eline[i].back().E>0.05)&&!outofrange(eline[i].back(),Subtest1[j]))
		//		{
		//		eupdate(eline[i],Subtest1[j]);
		//		eline[i].back().display();
		//		}
		//		if((eline[i].back().flag==1)&&(j<NS))
		//			BoundryDeal(eline[i],Subtest1[j],Subtest1[j+1]);
		//	}
		//}

		//delete[] eline;
		//delete[] Subtest1;

	}

} 

initial::~initial()
{

}
