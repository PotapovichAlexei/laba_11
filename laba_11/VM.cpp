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
	size_t len;
	char* buf;

	in.read((char*)&len, sizeof(size_t));
	buf = new char[len + 1];
	in.read(buf, len);
	buf[len] = 0;
	obj.brand = buf;
	delete[]buf;

	in.read((char*)&len, sizeof(size_t));
	buf = new char[len + 1];
	in.read(buf, len);
	buf[len] = 0;
	obj.processor = buf;
	delete[]buf;

	//in >> obj.brand >> obj.processor;
	return in;
}

fstream& operator<<(fstream& out, VM& obj) {
	size_t len = obj.brand.length();
	out.write((char*)&len, sizeof(size_t));
	out.write(obj.brand.data(), len);
	//out << obj.brand;
	len = obj.processor.length();
	out.write((char*)&len, sizeof(size_t));
	out.write(obj.processor.data(), len);
	//out << obj.processor;
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
