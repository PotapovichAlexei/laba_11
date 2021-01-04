#pragma once
#include "Header.h"


class Portable : public VM {
protected:
	int energyReserve;	//Запас энергии Вт*ч
public:
	Portable();
	Portable(string _brand, string _processor, int _energyReserve);
	void setEnergyReserve(int _energyReserve);
	int getEnergyReserve();
	void Table();
	bool operator > (Portable& object);
	bool operator < (Portable& object);
	bool operator == (Portable& object);
	friend istream& operator>>(istream& in, Portable& obj);
	friend ostream& operator<<(ostream& out, Portable& obj);
	friend fstream& operator>>(fstream& in, Portable& obj);
	friend fstream& operator<<(fstream& out, Portable& obj);
	friend ifstream& operator>>(ifstream& in, Portable& obj);
	friend ofstream& operator<<(ofstream& out, Portable& obj);
	//~Portable();
};