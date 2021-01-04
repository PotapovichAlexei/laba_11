#pragma once
#include "Header.h"


class  SystemBlock : public Desktop {
private:
	string monitor;		//Видеокарта
public:
	SystemBlock();
	SystemBlock(string _brand, string _processor, int _powerSupply, string _monitor);
	void setMonitor(string _monitor);
	string getMonitor();
	void Table();
	bool operator > (SystemBlock& object);
	bool operator < (SystemBlock& object);
	bool operator == (SystemBlock& object);
	friend istream& operator>>(istream& in, SystemBlock& obj);
	friend ostream& operator<<(ostream& out, SystemBlock& obj);
	friend fstream& operator>>(fstream& in, SystemBlock& obj);
	friend fstream& operator<<(fstream& out, SystemBlock& obj);
	friend ifstream& operator>>(ifstream& in, SystemBlock& obj);
	friend ofstream& operator<<(ofstream& out, SystemBlock& obj);
	void Initialization(SystemBlock *array, int amount);
	//~SystemBlock();

};