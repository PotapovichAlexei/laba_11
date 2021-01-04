#include "Header.h"


VM::VM() : brand(""), processor("") {
	//cout << "VM Constructor" << endl;
}

VM::VM(string _brand, string _processor) : brand(_brand), processor(_processor) {
	//cout << "VM Constructor" << endl;
}

void VM::setBrand(string _barnd) {
	this->brand.clear();
	this->brand = _barnd;
}
string VM::getBrand() { return this->brand; }

void VM::setProcessor(string _processor) {
	this->processor.clear();
	this->processor = _processor;
}
string VM::getProcessor() { return this->processor; }

void VM::Table() {
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << endl << endl;
}

//VM::~VM() {
//	brand.clear();
//	processor.clear();
//	//cout << endl << "VM Destructor" << endl;
//}


bool VM::operator > (VM& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	return false;
}

bool VM::operator<(VM& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	return false;
}

bool VM::operator == (VM& object)
{
	/*if (this->brand == object.brand)
		return true;
	else */if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	return false;
}

istream& operator>>(istream& in, VM& obj)
{
	rewind(stdin);
	cout << "Brand: ";
	obj.brand = inputString(16);
	//in >> obj.brand;

	rewind(stdin);
	cout << "Processor: ";
	//char helpStr[255];
	//in.getline(helpStr, 255);
	obj.processor = stringExceptRussian(16);

	return in;
}

ostream& operator<<(ostream& out, VM& obj) {
	out << "|" << setw(17) << obj.brand << "|" << setw(17) << obj.processor << "|";
	return out;
}


fstream& operator>>(fstream& in, VM& obj)
{
	in >> obj.brand >> obj.processor;
	return in;
}

fstream& operator<<(fstream& out, VM& obj) {
	out << setw(17) << obj.brand;
	out << setw(17) << obj.processor;
	return out;
}

ifstream& operator>>(ifstream& in, VM& obj)
{
	in >> obj.brand >> obj.processor;
	return in;
}
 
ofstream& operator<<(ofstream& out, VM& obj) {
	out << setw(17) << obj.brand;
	out << setw(17) << obj.processor;
	return out;
}
