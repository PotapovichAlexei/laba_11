#pragma once
#include "Header.h"


class Laptop : public Portable {
protected:
	string motherboard;
public:
	Laptop();
	Laptop(string _brand, string _processor, int _energyReserve, string _motherboard);
	void setMotherboard(string _motherboard);
	string getMotherboard();
	void Table();
	bool operator > (Laptop& object);
	bool operator < (Laptop& object);
	bool operator == (Laptop& object);
	friend istream& operator>>(istream& in, Laptop& obj);
	friend ostream& operator<<(ostream& out, Laptop& obj);
	friend fstream& operator>>(fstream& in, Laptop& obj);
	friend fstream& operator<<(fstream& out, Laptop& obj);
	friend ifstream& operator>>(ifstream& in, Laptop& obj);
	friend ofstream& operator<<(ofstream& out, Laptop& obj);
	void Initialization(Laptop* array, int amount);
	//~Laptop();

};