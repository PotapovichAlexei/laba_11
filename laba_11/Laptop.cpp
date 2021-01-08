#include "Header.h"

Laptop::Laptop() :Portable("", "", NULL) {
	this->motherboard = "";
	//cout << "Laptop Constructor" << endl;
}

Laptop::Laptop(string _brand, string _processor, int _energyReserve, string _motherboard) : Portable(_brand, _processor, _energyReserve) {
	this->motherboard = _motherboard;
	//cout << "Laptop Constructor" << endl;
}

void Laptop::setMotherboard(string _motherboard) {
	this->motherboard = _motherboard;
}

string Laptop::getMotherboard() {
	return this->motherboard;
}

void Laptop::Table() {
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << setw(17) << "Energy reserve" << "|" << setw(17) << "Motherboard" << "|" << endl;
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
}

istream& operator>>(istream& in, Laptop& obj) {
	in >> dynamic_cast<Portable&> (obj);
	cout << "Motherboard: ";
	//char helpStr[255];
	rewind(stdin);
	//in.getline(helpStr, 255);
	obj.motherboard = stringExceptRussian(16);
	return in;
}

ostream& operator<<(ostream& out, Laptop& obj) {

	out << dynamic_cast<Portable&> (obj) << setw(17) << obj.motherboard << "|" << endl;

	return out;
}

fstream& operator>>(fstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portable&> (obj);
	size_t len;
	char* buf;
	in.read((char*)&len, sizeof(size_t));
	buf = new char[len + 1];
	in.read(buf, len);
	buf[len] = 0;
	obj.motherboard = buf;
	delete[]buf;
	return in;
}

fstream& operator<<(fstream& out, Laptop& obj) {
	out << dynamic_cast<Portable&> (obj);
	size_t len = obj.motherboard.length();
	out.write((char*)&len, sizeof(size_t));
	out.write(obj.motherboard.data(), len);
	return out;
}

ifstream& operator>>(ifstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portable&> (obj) >> obj.motherboard;
	return in;
}

ofstream& operator<<(ofstream& out, Laptop& obj) {
	out << dynamic_cast<Portable&> (obj);
	out << setw(17) << obj.motherboard << '\n';
	return out;
}

void Laptop::Initialization(Laptop* array, int amount) {
	int a, b, flag;
	//Заполнение полей
	for (int i = 0; i < amount; i++) {
		cout << endl;
		cin >> array[i];
	}
	do {
		//CHANGE VALUE Laptop
		cout << "Change.Input number of laptop: ";


		a = inputInt(1, amount);
		a--;
		cout << endl << "Input number of the parameter to change: " << endl;
		cout << "1) Brand " << endl;
		cout << "2) Processor " << endl;
		cout << "3) Energy reserve " << endl;
		cout << "4) Motherboard " << endl;
		cout << "0) Exit" << endl;
		b = inputInt(0, 4);

		string help;
		int helpint;
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
			cout << "Replace Motherboard: " << endl;
			cin >> help;
			array[a].setMotherboard(help);
			break;
		}
		case 0: break;

		default:break;
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

//Laptop::~Laptop() {
//	//cout << endl << "Laptop Destructor" << endl;
//}


bool Laptop::operator > (Laptop& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->energyReserve > object.energyReserve))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->energyReserve > object.energyReserve) && (this->motherboard > object.motherboard))
		return true;
	return false;
}

bool Laptop::operator < (Laptop& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->energyReserve < object.energyReserve))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->energyReserve < object.energyReserve) && (this->motherboard < object.motherboard))
		return true;
	return false;
}

bool Laptop::operator == (Laptop& object)
{
	/*if (this->brand == object.brand)
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor) && (this->energyReserve == object.energyReserve))
		return true;
	else*/ if ((this->brand == object.brand) && (this->processor == object.processor) && (this->energyReserve == object.energyReserve) && (this->motherboard > object.motherboard))
		return true;
	return false;
}	