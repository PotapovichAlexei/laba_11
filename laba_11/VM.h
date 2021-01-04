#pragma once
#include "Header.h"


class VM {
protected:
	string brand;
	string processor;
public: 
	VM();
	VM(string _brand, string processor);
	void setBrand(string _barnd);
	string getBrand();
	void setProcessor(string _processor);
	string getProcessor();
	void Table();
	bool operator > (VM& obj);
	bool operator < (VM& obj);
	bool operator == (VM& obj);
	friend istream& operator>>(istream& in, VM& obj);
	friend ostream& operator<<(ostream& out, VM& obj);
	friend fstream& operator>>(fstream& in, VM& obj);
	friend fstream& operator<<(fstream& out, VM& obj);
	friend ifstream& operator>>(ifstream& in, VM& obj);
	friend ofstream& operator<<(ofstream& out, VM& obj);
	//virtual ~VM();
};