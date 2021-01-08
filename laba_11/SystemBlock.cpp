#include "Header.h"

SystemBlock::SystemBlock() :Desktop("", "", NULL) {
	this->monitor = "";
	//cout << "SystemBlock Constructor" << endl;
}

SystemBlock::SystemBlock(string _brand, string _processor, int _powerSupply, string _monitor) : Desktop(_brand, _processor, _powerSupply) {
	this->monitor = _monitor;
	//cout << "SystemBlock Constructor" << endl;
}

void SystemBlock::setMonitor(string _monitor) {
	this->monitor = _monitor;
}

string SystemBlock::getMonitor() {
	return this->monitor;
}

void SystemBlock::Table() {
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << setw(17) << "Power supply" << "|" << setw(17) << "Monitor" << "|" << endl;
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
}

istream& operator>>(istream& in, SystemBlock& obj) {
	in >> dynamic_cast<Desktop&> (obj);
	cout << "Monitor: ";
	rewind(stdin);
	//char helpStr[255];
	//in.getline(helpStr, 255);
	obj.monitor = inputString(16);
	return in;
}

ostream& operator<<(ostream& out, SystemBlock& obj) {
	out << dynamic_cast<Desktop&> (obj) << setw(17) << obj.monitor << "|" << endl;

	return out;
}

fstream& operator>>(fstream& in, SystemBlock& obj)
{
	in >> dynamic_cast<Desktop&> (obj);
	size_t len;
	char* buf;
	in.read((char*)&len, sizeof(size_t));
	buf = new char[len + 1];
	in.read(buf, len);
	buf[len] = 0;
	obj.monitor = buf;
	delete[]buf;
	return in;
}

fstream& operator<<(fstream& out, SystemBlock& obj) {
	out << dynamic_cast<Desktop&> (obj);
	size_t len = obj.monitor.length();
	out.write((char*)&len, sizeof(size_t));
	out.write(obj.monitor.data(), len);
	return out;
}
ifstream& operator>>(ifstream& in, SystemBlock& obj)
{
	in >> dynamic_cast<Desktop&> (obj) >> obj.monitor;
	return in;
}

ofstream& operator<<(ofstream& out, SystemBlock& obj) {
	out << dynamic_cast<Desktop&> (obj);
	out << setw(17) << obj.monitor << '\n';
	return out;
}

void SystemBlock::Initialization(SystemBlock* array, int amount) {

	int a, b, flag;
	//Заполнение полей
	for (int i = 0; i < amount; i++) {
		cout << endl;
		cin >> array[i];
	}

	//CHANGE VALUE systemBlocks
	do {
		cout << "Change.Input number of system block: ";

		a = inputInt(1, amount);
		a--;
		cout << endl << "Input number of the parameter to change: " << endl;
		cout << "1) Brand " << endl;
		cout << "2) Processor " << endl;
		cout << "3) Power supply " << endl;
		cout << "4) Monitor " << endl;
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
			array[a].setPowerSupply(helpint);
			break;
		}
		case 4: {
			cout << "Replace Diagonal: " << endl;
			cin >> help;
			array[a].setMonitor(help);
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

//SystemBlock::~SystemBlock() {
//	//cout << "SystemBlock Destructor" << endl;
//}

bool SystemBlock::operator > (SystemBlock& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->powerSupply > object.powerSupply) && (this->monitor > object.monitor))
		return true;
	return false;
}

bool SystemBlock::operator < (SystemBlock& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->powerSupply < object.powerSupply) && (this->monitor < object.monitor))
		return true;
	return false;
}


bool SystemBlock::operator == (SystemBlock& object)
{
	/*if (this->brand == object.brand)
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor) && (this->powerSupply == object.powerSupply))
		return true;
	else */if ((this->brand == object.brand) && (this->processor == object.processor) && (this->powerSupply == object.powerSupply) && (this->monitor == object.monitor))
		return true;
	return false;
}