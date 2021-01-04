#pragma once
#include "Header.h"

class Tablet : public Portable {
protected:
	float diagonal; 
public:
	Tablet();
	Tablet(string _brand, string _processor, int _energyReserve, float _diagonal);
	void setDiagonal(float _diagonal);
	float getDiagonal();
	void Table();
	bool operator > (Tablet& object);
	bool operator < (Tablet& object);
	bool operator == (Tablet& object);
	friend istream& operator>>(istream& in, Tablet& obj);
	friend ostream& operator<<(ostream& out, Tablet& obj);
	friend fstream& operator>>(fstream& in, Tablet& obj);
	friend fstream& operator<<(fstream& out, Tablet& obj);
	friend ifstream& operator>>(ifstream& in, Tablet& obj);
	friend ofstream& operator<<(ofstream& out, Tablet& obj);
	void Initialization(Tablet* array, int amount);
	//~Tablet();

};