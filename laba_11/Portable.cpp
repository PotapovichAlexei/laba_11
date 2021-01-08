#include "Header.h"

Portable::Portable() :VM() {
	this->energyReserve = NULL;
	//cout << "Portable Constructor" << endl;
}

Portable::Portable(string _brand, string _processor, int _energyReserve) : VM(_brand, _processor) {
	this->energyReserve = _energyReserve;
	//cout << "Portable Constructor" << endl;
}

void Portable::setEnergyReserve(int _energyReserve) { this->energyReserve = _energyReserve; }

int Portable::getEnergyReserve() { return this->energyReserve; }

void Portable::Table() {
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << setw(17) << "Energy reserve" << "|" << endl;
}

istream& operator>>(istream& in, Portable& obj) {
	in >> dynamic_cast<VM&> (obj);
	cout << "Energy reserve: ";
	rewind(stdin);
	//in >> obj.energyReserve;
	obj.energyReserve = inputInt(0, 150);
	return in;
}

ostream& operator<<(ostream& out, Portable& obj) {
	out << dynamic_cast<VM&> (obj) << setw(17) << obj.energyReserve << "|";
	return out;
}


fstream& operator>>(fstream& in, Portable& obj)
{
	in >> dynamic_cast<VM&> (obj);
	in.read((char*)&obj.energyReserve, sizeof(int));
	return in;
}

fstream& operator<<(fstream& out, Portable& obj) {
	out << dynamic_cast<VM&> (obj);
	out.write((char*)&obj.energyReserve, sizeof(int));
	return out;
}


ifstream& operator>>(ifstream& in, Portable& obj)
{
	in >> dynamic_cast<VM&> (obj) >> obj.energyReserve;
	return in;
}

ofstream& operator<<(ofstream& out, Portable& obj) {
	out << dynamic_cast<VM&> (obj);
	out << setw(17) << obj.energyReserve;
	return out;
}
//Portable::~Portable() {
//	//cout << "Portable Destructor" << endl;
//}


bool Portable::operator > (Portable& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->energyReserve > object.energyReserve))
		return true;
	return false;
}

bool Portable::operator < (Portable& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->energyReserve < object.energyReserve))
		return true;
	return false;
}

bool Portable::operator == (Portable& object)
{
	/*if (this->brand == object.brand)
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	else*/ if ((this->brand == object.brand) && (this->processor == object.processor) && (this->energyReserve == object.energyReserve))
		return true;
	return false;
}