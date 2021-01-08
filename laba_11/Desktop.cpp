#include "Header.h"

Desktop::Desktop() :VM() {
	this->powerSupply = NULL;
	//cout << "Desktop Constructor" << endl;
}

Desktop::Desktop(string _brand, string _processor, int _powerSupply) : VM(_brand, _processor) {
	this->powerSupply = _powerSupply;
	//cout << "Desktop Constructor" << endl;
}


void Desktop::setPowerSupply(int W) { this->powerSupply = W; }

int Desktop::getPowerSupply() { return this->powerSupply; }

void Desktop::Table() {
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << setw(17) << "Power supply" << "|" << endl << endl;
}

istream& operator>>(istream& in, Desktop& obj) {
	in >> dynamic_cast<VM&> (obj);
	cout << "Power supply: ";
	rewind(stdin);
	//in >> obj.powerSupply;
	obj.powerSupply = inputInt(0, 10000);
	return in;
}

ostream& operator<<(ostream& out, Desktop& obj) {
	out << dynamic_cast<VM&> (obj) << setw(17) << obj.powerSupply << "|";

	return out;
}

fstream& operator>>(fstream& in, Desktop& obj)
{
	in >> dynamic_cast<VM&> (obj);
	in.read((char*)&obj.powerSupply, sizeof(int));
	return in;
}

fstream& operator<<(fstream& out, Desktop& obj) {
	out << dynamic_cast<VM&> (obj);
	out.write((char*)&obj.powerSupply, sizeof(int));
	//out << obj.powerSupply;
	return out;
}

ifstream& operator>>(ifstream& in, Desktop& obj)
{
	in >> dynamic_cast<VM&> (obj) >> obj.powerSupply;
	return in;
}

ofstream& operator<<(ofstream& out, Desktop& obj) {
	out << dynamic_cast<VM&> (obj);
	out << setw(17) << obj.powerSupply;
	return out;
}


//Desktop::~Desktop() {
//	//cout << "Desktop Destructor" << endl;
//}


bool Desktop::operator > (Desktop& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->powerSupply > object.powerSupply))
		return true;
	return false;
}

bool Desktop::operator < (Desktop& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->powerSupply < object.powerSupply))
		return true;
	return false;
}

bool Desktop::operator == (Desktop& object)
{
	/*if (this->brand == object.brand)
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	else*/ if ((this->brand == object.brand) && (this->processor == object.processor) && (this->powerSupply == object.powerSupply))
		return true;
	return false;
}