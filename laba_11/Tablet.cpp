#include "Header.h"

Tablet::Tablet() :Portable("", "", NULL) {
	this->diagonal = NULL;
	//cout << "Tablet Constructor" << endl;
}

Tablet::Tablet(string _brand, string _processor, int _energyReserve, float _diagonal) : Portable(_brand, _processor, _energyReserve) {
	this->diagonal = _diagonal;
	//cout << "Tablet Constructor" << endl;
}

void Tablet::setDiagonal(float _diagonal) {
	this->diagonal = _diagonal;
}

float Tablet::getDiagonal() {
	return this->diagonal;
}

void Tablet::Table() {
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << setw(17) << "Energy reserve" << "|" << setw(17) << "Diagonal" << endl;
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
}

istream& operator>>(istream& in, Tablet& obj) {
	in >> dynamic_cast<Portable&> (obj);
	cout << "Diagonal: ";
	rewind(stdin);
	//in >> obj.diagonal;
	obj.diagonal = inputFloat(0.0, 50.0);
	return in;
}

ostream& operator<<(ostream& out, Tablet& obj) {
	out << dynamic_cast<Portable&> (obj) << setw(17) << obj.diagonal << "|" << endl;

	return out;
}

fstream& operator>>(fstream& in, Tablet& obj)
{
	in >> dynamic_cast<Portable&> (obj);
	in.read((char*)&obj.diagonal, sizeof(float));
	return in;
}

fstream& operator<<(fstream& out, Tablet& obj) {
	out << dynamic_cast<Portable&> (obj);
	out.write((char*)&obj.diagonal, sizeof(float));
	return out;
}

ifstream& operator>>(ifstream& in, Tablet& obj)
{
	in >> dynamic_cast<Portable&> (obj) >> obj.diagonal;
	return in;
}

ofstream& operator<<(ofstream& out, Tablet& obj) {
	out << dynamic_cast<Portable&> (obj);
	out << setw(17) << obj.diagonal << '\n';
	return out;
}

bool Tablet::operator > (Tablet& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->energyReserve > object.energyReserve))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->energyReserve > object.energyReserve) && (this->diagonal > object.diagonal))
		return true;
	return false;
}

bool Tablet::operator < (Tablet& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->energyReserve < object.energyReserve))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->energyReserve < object.energyReserve) && (this->diagonal < object.diagonal))
		return true;
	return false;
}

bool Tablet::operator == (Tablet& object)
{
	/*if (this->brand == object.brand)
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor) && (this->energyReserve == object.energyReserve))
		return true;
	else */if ((this->brand == object.brand) && (this->processor == object.processor) && (this->energyReserve == object.energyReserve) && (this->diagonal > object.diagonal))
		return true;
	return false;
}

void Tablet::Initialization(Tablet* array, int amount) {
	int a, b, flag;

	//Заполнение полей
	for (int i = 0; i < amount; i++) {
		cout << endl;
		cin >> array[i];
	}

	//CHANGE VALUE Tablet
	do {
		cout << "Change.Input number of tablet: ";

		a = inputInt(1, amount);
		a--;
		cout << endl << "Input number of the parameter to change: " << endl;
		cout << "1) Brand " << endl;
		cout << "2) Processor " << endl;
		cout << "3) Energy reserve " << endl;
		cout << "4) Diagonal " << endl;
		cout << "0) Exit" << endl;
		b = inputInt(0, 4);

		string help;
		int helpint;
		float helpf;

		switch (b) {
		case 1: {
			cout << "Replace Brand: " << endl;
			cin >> help;
			array[a].setBrand(help);
			break;
		}
		case 2: {
			cout << "Replace Processor: " << endl;
			cin >> help;
			array[a].setProcessor(help);
			break;
		}
		case 3: {
			cout << "Replace Energy reserve : " << endl;
			cin >> helpint;
			array[a].setEnergyReserve(helpint);
			break;
		}
		case 4: {
			cout << "Replace Diagonal: " << endl;
			cin >> helpf;
			array[a].setDiagonal(helpf);
			break;
		}
		case 0: break;
		default: break;
		}
		//END CHANGE

		cout << "To end change input 0 (zero), to continue - 1 (one)" << endl << "Your choice: ";
		rewind(stdin);
		cin >> flag;
	} while (flag);

	//Вывод
	(*array).Table();

	for (int i = 0; i < amount; i++) {
		cout << array[i];
		cout << endl;
	}
}

//Tablet::~Tablet() {
//	//cout << "Tablet Destructor" << endl;
//}
