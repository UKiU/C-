#pragma once

#include<tinyxml2.h>
#include<string>
using namespace tinyxml2;
using namespace std;


class Coordinate {//����
private:
	double Lat = NULL, Lon = NULL;
public:
	Coordinate() {
	}
	Coordinate(double lat, double lon) {
		Lat = lat;
		Lon = lon;
	}

	double SetLat(double lat) {
		this->Lat = lat;
		return Lat;
	}
	double GetLat() {
		return this->Lat;
	}
	double SetLon(double lon) {
		this->Lon = lon;
		return Lon;
	}
	double GetLon() {
		return this->Lon;
	}
	Coordinate Setcoor(Coordinate coor) {
		Lat = coor.GetLat();
		Lon = coor.GetLon();
		return *this;
	}
};

class XmlNode0 {//�����ڵ�
private:
	long long Id;//�ڵ�id
	Coordinate Coor;//�ڵ㾭γ��
public:
	XmlNode0() {
		Id = NULL;
	}
	XmlNode0(long long id, Coordinate& coor) {
		Id = id;
		Coor = coor;
	}
	XmlNode0(long long id, double lat, double lon) {
		Id = id;
		Coor.SetLat(lat);
		Coor.SetLon(lon);
	}

	
	long long GetId() {
		return this->Id;
	}
	Coordinate GetCoor() {
		return this->Coor;
	}
	
	long long SetId(long long id) {
		this->Id = id;
		return this->Id;
	}
	Coordinate SetCoor(Coordinate& coor) {
		this->Coor = coor;
		return this->Coor;
	}
	Coordinate SetCoor(double lat, double lon) {
		this->Coor.SetLat(lat);
		this->Coor.SetLon(lon);
		return this->Coor;
	}
};

class XmlNode {//�����ڵ�
private:
	long long Id;//�ڵ�id
	string Name;//�ڵ�����
	Coordinate Coor;//�ڵ㾭γ��
public:
	XmlNode() {
		Id = NULL;
	}
	XmlNode(long long id, string& name, Coordinate& coor) {
		Id = id;
		Name = name;
		Coor = coor;
	}
	XmlNode(long long id, string& name, double lat, double lon) {
		Id = id;
		Name = name;
		Coor.SetLat(lat);
		Coor.SetLon(lon);
	}


	long long GetId() {
		return this->Id;
	}
	string GetName() {
		return this->Name;
	}
	Coordinate GetCoor() {
		return this->Coor;
	}

	long long SetId(long long id) {
		this->Id = id;
		return this->Id;
	}
	string SetName(string& name) {
		this->Name = name;
		return this->Name;
	}
	Coordinate SetCoor(Coordinate& coor) {
		this->Coor = coor;
		return this->Coor;
	}
	Coordinate SetCoor(double lat, double lon) {
		this->Coor.SetLat(lat);
		this->Coor.SetLon(lon);
		return this->Coor;
	}
};
class XmlWay {//����
private:
	long long Id;
	string Name;
	long long* Noderef = nullptr;//�߽��id����

	int Nodenum = 0;//�߽�����
	Coordinate* Coors = nullptr;//�߽�㾭γ��
public:
	//���캯��
	XmlWay() {
		Id = NULL;
	}
	XmlWay(long long id, string& name) {
		Id = id;
		Name = name;
		Nodenum = 0;
	}
	XmlWay(long long id, string& name,long long*& noderef, int nodenum) {
		Id = id;
		Name = name;
		Noderef = noderef;
		Nodenum = nodenum;
	}
	XmlWay(long long id, string& name,long long*& noderef, int nodenum, Coordinate*& coors) {
		Id = id;
		Name = name;
		Noderef = noderef;
		Nodenum = nodenum;
		Coors = coors;
	}

	//��ȡ����
	long long GetId() {
		return this->Id;
	}
	string GetName() {
		return this->Name;
	}
	long long* GetNoderef() {
		return this->Noderef;
	}
	long long GetNoderef(int n) {
		if (n < Nodenum)
			return this->Noderef[n];
	}//��ȡ��nλ
	int GetNodenum() {
		return this->Nodenum;
	}
	Coordinate* GetCoors() {
		if (this->Coors)return this->Coors;
		else return nullptr;
	}
	Coordinate GetCoors(int n) {
		if (n < this->Nodenum) {
			return this->Coors[n];
		}
	}//��ȡ��nλ

	//��д����
	long long SetId(long long id) {
		this->Id = id;
		return this->Id;
	}
	string SetName(string& name) {
		this->Name = name;
		return this->Name;
	}
	int SetNodenum(int n) {
		Nodenum = n;
		return this->Nodenum;
	}
	long long* SetNoderef(long long* & noderef,int nodenum) {
		this->Noderef= noderef;
		this->Nodenum = nodenum;
		return this->Noderef;
	} //ֱ�ӿ�������Ϊn�Ľڵ�����
	long long AddNoderef(long long node) {
		Noderef[Nodenum] = node;
		Nodenum++;
		return this->Noderef[Nodenum-1];
	} //�����Ӻ�ӽڵ�
	Coordinate InsertCoors(Coordinate& coor,int n) {
		Coors[n] = coor;
		return Coors[n];
	} //��n������ڵ㾭γ����
	Coordinate* SetCoors(Coordinate*& coor) {
		Coors=coor;
		return Coors;
	} //��n������ڵ㾭γ����
};

