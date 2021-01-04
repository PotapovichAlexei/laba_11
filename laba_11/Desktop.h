#pragma once
#include "Header.h"

class Desktop: public VM {
protected:
	int powerSupply;		//Мощность блока питания в Вольтах (W)
public:
	Desktop();
	Desktop(string _brand, string _processor, int _powerSupply);
	void setPowerSupply(int W);
	int getPowerSupply();
	void Table();
	bool operator > (Desktop& object);
	bool operator < (Desktop& object);
	bool operator == (Desktop& object);
	friend istream& operator>>(istream& in, Desktop& obj);
	friend ostream& operator<<(ostream& out, Desktop& obj);
	friend fstream& operator>>(fstream& in, Desktop& obj);
	friend fstream& operator<<(fstream& out, Desktop& obj);
	friend ifstream& operator>>(ifstream& in, Desktop& obj);
	friend ofstream& operator<<(ofstream& out, Desktop& obj);
//	~Desktop();

};