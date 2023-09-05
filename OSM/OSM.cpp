#include"OSM.h"
#include <iostream>
#include<stdlib.h>



using namespace std;
using namespace tinyxml2;

const char* filename = "map-2.osm";


/*
Node（节点）：地理位置点，以经纬度坐标形式存储，通常代表没有尺寸的要素，比如POI（Points Of Interest，兴趣点）或山峰的制高点；

Way（通道）：一系列节点的列表，可以是多义线，当形成闭合路径时也可以是面；既可以代表线性要素，如街道、河流等，也可以代表面状要素，如森林、公园、停车场、湖泊等；

Relation（关系）：节点、通道、关系的有序列表，合在一起叫做“member（成员）”，member可以有“role（地位）”属性（字符串格式）；Relation用来表示已存在的节点和通道的相互关系，比如道路的转弯限制，高速公路跨越多条普通道路（并不相交），以及中间有洞的环形面等；

Tag（标签）：关键值，键名、键值均为字符串格式，用于存储地图要素的元数据，比如类型、名称、物理属性等；标签是独立要素，但总是附着到地图要素（节点、通道、关系）， 推荐的各类地图要素的标签定义及含义在一个wiki网站上进行维护（https://wiki.openstreetmap.org/wiki/Tags）。
*/


bool Judg(int num, Coordinate* & Coors, double lat,double lon)//采用射线法判断点在多边形内,lat对应y坐标，lon对应x坐标
{	//多边形经纬度集按顺序
	int i, j = 0;
	bool c = 0;
	for (i = 0, j = num - 1; i < num; j = i++) {
		//判断向右射线
		//待测点纬度在两点纬度中间，待测点经度小于垂线交点经度
		if (((Coors[i].GetLat() > lat) != (Coors[j].GetLat() > lat)) &&
			(lon < (Coors[j].GetLon() - Coors[i].GetLon()) * (lat - Coors[i].GetLat()) / (Coors[j].GetLat() - Coors[i].GetLat()) + Coors[i].GetLon()))
			c = !c;
	}
	return c;//0为外,1为内
}

int main()
{
	system("chcp 65001");

	int AllNum=0;
	XMLDocument Doc;
	XMLError err = Doc.LoadFile(filename);

	if (tinyxml2::XML_SUCCESS == err) {
		cout << "open successfully" << endl;

		XMLElement* DocRoot = Doc.RootElement();
		XMLElement* Count = DocRoot->FirstChildElement("node");
		while (Count) {
			AllNum++;
			Count= Count->NextSiblingElement("node");
		}
		Count= DocRoot->FirstChildElement("way");
		while (Count) {
			AllNum++;
			Count = Count->NextSiblingElement("way");
		}

		XMLElement* Node1 = DocRoot->FirstChildElement("node");
		XMLElement* Way1 = DocRoot->FirstChildElement("way");
		

		XmlNode0* DocNodes0 = new XmlNode0[++AllNum];//无名坐标点集
		XmlNode* DocNodes = new XmlNode[++AllNum];//有名坐标点集
		XmlWay* DocWays = new XmlWay[++AllNum];//有名区域集
		int NodesNum0 = 0, NodesNum = 0, WaysNum = 0;
		
		//解析点集
		while(Node1) {//Node1存在
			const char* Id1 = Node1->Attribute("id");
			if (Id1) {//Node1的id存在
				string Id1s = Id1;
				long long Id1i = stoll(Id1s.c_str());//id转ll型
				
				string Node1lats = Node1->Attribute("lat"),
					Node1lons = Node1->Attribute("lon");
				double Node1lati = stod(Node1lats.c_str()),
					Node1loni = stod(Node1lons.c_str());
				Coordinate Node1coor = *new Coordinate(Node1lati, Node1loni);//创建经纬度坐标点

				XMLElement* Tag1 = Node1->FirstChildElement("tag");//寻找tag，寻找name
				if (Tag1) {
					while (Tag1) {//循环查找tag有没有name属性
						const char* k = Tag1->Attribute("k");
						if (!(strcmp(k,"name"))) {//有name，加入有名坐标点集
							const char* Node1namec = Tag1->Attribute("v");
							string Node1name = Node1namec;
							//wstring Node1namew = UTF8ToUnicode();
							DocNodes[NodesNum] = *new XmlNode(Id1i,Node1name,Node1coor);
							NodesNum++;
							break;
						}
						else Tag1 = Tag1->NextSiblingElement("tag");	//下一个tag
					}
					if(!Tag1){//tag循环结束未找到name
						DocNodes0[NodesNum0] = *new XmlNode0(Id1i, Node1coor);
						NodesNum0++;
					}
				}
				else {//无tag，肯定无name
					DocNodes0[NodesNum0] = *new XmlNode0(Id1i, Node1coor);
					NodesNum0++;
				}				
			}
			else cout << "no id";
			Node1 = Node1->NextSiblingElement("node");
		}
		//解析区域集
		while (Way1) {
			const char* Id2 = Way1->Attribute("id");
			if (Id2) {
				string Id2s = Id2;
				long long Id2i = stoll(Id2s.c_str());
				XMLElement* Tag2 = Way1->FirstChildElement("tag");//寻找tag，寻找name
				if (Tag2) {
					bool bname= 0;//记录区域有无名
					while (Tag2) {//循环查找tag有没有name属性
						const char* k = Tag2->Attribute("k");
						if (!(strcmp(k, "name"))) {//有name，加入有区域集
							string Way1name = Tag2->Attribute("v");
							//wstring Node1namew = UTF8ToUnicode();
							DocWays[WaysNum] = * new XmlWay(Id2i, Way1name);
							WaysNum++;
							bname = 1;
							break;
						}
						else Tag2 = Tag2->NextSiblingElement("tag");	//下一个tag
					}
					if (bname == 1) {
						XMLElement* Nd = Way1->FirstChildElement("nd");
						int tempnum = 0;
						while (Nd) {
							tempnum++;
							Nd = Nd->NextSiblingElement("nd");
						}
						long long* WayNd = new long long[++tempnum];
						
						tempnum = 0;
						Nd = Way1->FirstChildElement("nd");
						string refs;
						long long refi;
						while (Nd) {
							refs = Nd->Attribute("ref");
							refi = stoll(refs.c_str());
							WayNd[tempnum] = refi;
							tempnum++;
							Nd = Nd->NextSiblingElement("nd");
						}
						DocWays[WaysNum - 1].SetNoderef(WayNd, tempnum);
						
						Coordinate* tempcoor = new Coordinate[++tempnum];
						bool bnode = 0;//判断有无找到点
						for (int i = 0; i < tempnum; i++) {
							bnode = 0;
							int tempcount = 0;
							for (tempcount = 0; tempcount < NodesNum0; tempcount++) {
								if (DocNodes0[tempcount].GetId() == DocWays[WaysNum - 1].GetNoderef(i)) {
									tempcoor[i].Setcoor(DocNodes0[tempcount].GetCoor());
									bnode = 1;
									break;
								}
							}
							for (tempcount = 0; bnode == 0 && ( tempcount < NodesNum ); tempcount++) {
								if (DocNodes[tempcount].GetId() == DocWays[WaysNum - 1].GetNoderef(i)) {
									tempcoor[i].Setcoor(DocNodes[tempcount].GetCoor());
									bnode = 1;
									break;
								}
							}
						}
						DocWays[WaysNum - 1].SetCoors(tempcoor);
					}
				}
			}
			else cout << "no id";
			Way1 = Way1->NextSiblingElement("way");
		}
		
		////输出无名点集
		//if (NodesNum0 > 0) {
		//	cout << "无名点集" << endl;
		//	for (int i = 0; i < NodesNum0; i++) {
		//		cout << DocNodes0[i].GetId() << endl;
		//	}
		//}
		////输出有名点集
		//if (NodesNum > 0) {
		//	cout << "有名点集" << endl;
		//	for (int i = 0; i < NodesNum; i++) {
		//		cout << DocNodes[i].GetId()<< " " << DocNodes[i].GetName() << endl;
		//	}
		//}
		////输出区域点集
		//if (WaysNum > 0) {
		//	cout << "有名区域" << endl;
		//	for (int i = 0; i < WaysNum; i++) {
		//		cout << DocWays[i].GetId() << " " << DocWays[i].GetName() << endl;
		//		for (int j = 0; j < DocWays[i].GetNodenum(); j++) {
		//			cout << "边界点" << j << ": " << DocWays[i].GetNoderef(j)<<" ( "
		//				<<DocWays[i].GetCoors(j).GetLat()<<"," << DocWays[i].GetCoors(j).GetLon()<<" ) " << endl;
		//		}
		//	}
		//}
		
		//判定并输出
		if (WaysNum > 0) {
			cout << "有名区域" << endl;
			for (int i = 0; i < WaysNum; i++) {
				cout << DocWays[i].GetId() << " " << DocWays[i].GetName() << endl;
				int n = 0;
				for (int j = 0; j < NodesNum; j++) {
					Coordinate* p = DocWays[i].GetCoors();
					if (Judg(DocWays[i].GetNodenum(), p, DocNodes[j].GetCoor().GetLat(), DocNodes[j].GetCoor().GetLon())) {
						cout<<DocNodes[j].GetId()<<" "<<DocNodes[j].GetName()<<" is in "
							<< DocWays[i].GetId() << " " << DocWays[i].GetName() << endl;
						n++;
					}
				}
				if(!n)cout<<"No node is in "<< DocWays[i].GetId() << " " << DocWays[i].GetName() << endl;
			}
		}
	

		if(DocNodes0)delete[]DocNodes0;
		if(DocNodes)delete[] DocNodes;
		if (DocWays) {
			for (int i = 0; i < WaysNum; i++) {
				delete[] DocWays[i].GetCoors();
				delete[] DocWays[i].GetNoderef();
			}
			delete[] DocWays;
		}
	}
	else cout << "open failed";


}


/*
	成功为0；
*/
/*	测试Judg
	Coordinate* Coors=new Coordinate;
	Coors[0] = Coordinate(2.5, 5.8);
	Coors[1] = Coordinate(3.7, 2.1);
	Coors[3] = Coordinate(7.9, 1.9);
	Coors[2] = Coordinate(5.3, 4.3);
	bool a = Judg(4, Coors, 3.75, 2.9);
	bool b = Judg(4, Coors, 0, 2.9);
	if (a == 1)cout << "a is in" << endl;
	else cout << "a is out" << endl;
	if (b == 1)cout << "b is in" << endl;
	else cout << "b is out" << endl;
*/
	