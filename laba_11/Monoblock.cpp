#include "Header.h"

Monoblock::Monoblock() :Desktop("", "", NULL) {
	this->videoCard = "";
	//cout << "Monoblock Constructor" << endl;
}

Monoblock::Monoblock(string _brand, string _processor, int _powerSupply, string _motherboard) : Desktop(_brand, _processor, _powerSupply) {
	this->videoCard = _motherboard;
	cout << "Monoblock Constructor" << endl;
}

void Monoblock::setVideoCard(string _videoCard) {
	this->videoCard = _videoCard;
}

string Monoblock::getVideoCard() {
	return this->videoCard;
}

void Monoblock::Table() {
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(17) << "Brand" << "|" << setw(17) << "Processor" << "|" << setw(17) << "Power supply" << "|" << setw(17) << "Video card" << "|" << endl;
	cout << "|"; for (int i = 0; i < 71; i++) cout << "~"; cout << "|" << endl;
}

istream& operator>>(istream& in, Monoblock& obj) {
	in >> dynamic_cast<Desktop&> (obj);
	cout << "VideoCard: ";
	rewind(stdin);
	//in >> obj.videoCard;
	obj.videoCard = inputString(16);
	return in;
}

ostream& operator<<(ostream& out, Monoblock& obj) {
	out << dynamic_cast<Desktop&> (obj) << setw(17) << obj.videoCard << "|" << endl;

	return out;
}


fstream& operator>>(fstream& in, Monoblock& obj)
{
	in >> dynamic_cast<Desktop&> (obj);
	size_t len;
	char* buf;
	in.read((char*)&len, sizeof(size_t));
	buf = new char[len + 1];
	in.read(buf, len);
	buf[len] = 0;
	obj.videoCard = buf;
	delete[]buf;
	return in;
}

fstream& operator<<(fstream& out, Monoblock& obj) {
	out << dynamic_cast<Desktop&> (obj);
	size_t len = obj.videoCard.length();
	out.write((char*)&len, sizeof(size_t));
	out.write(obj.videoCard.data(), len);

	return out;
}


ifstream& operator>>(ifstream& in, Monoblock& obj)
{
	in >> dynamic_cast<Desktop&> (obj) >> obj.videoCard;
	return in;
}

ofstream& operator<<(ofstream& out, Monoblock& obj) {
	out << dynamic_cast<Desktop&> (obj);
	out << setw(17) << obj.videoCard << '\n';
	return out;
}

void Monoblock::Initialization(Monoblock* array, int amount) {
	int a, b, flag;

	//Заполнение полей
	for (int i = 0; i < amount; i++) {
		cout << endl;
		cin >> array[i];
	}


	//CHANGE VALUE systemBlocks
	do {
		cout << "Change.Input number of monoblock: ";

		a = inputInt(1, amount);
		a--;
		cout << endl << "Input number of the parameter to change: " << endl;
		cout << "1) Brand " << endl;
		cout << "2) Processor " << endl;
		cout << "3) Power supply " << endl;
		cout << "4) Videocard " << endl;
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
			array[a].setVideoCard(help);
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
//
//Monoblock::~Monoblock() {
//	//cout << endl << "Monoblock Destructor" << endl;
//}


bool Monoblock::operator > (Monoblock& object)
{
	if (this->brand > object.brand)
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor))
		return true;
	else if ((this->brand > object.brand) && (this->processor > object.processor) && (this->powerSupply > object.powerSupply) && (this->videoCard > object.videoCard))
		return true;
	return false;
}

bool Monoblock::operator < (Monoblock& object)
{
	if (this->brand < object.brand)
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor))
		return true;
	else if ((this->brand < object.brand) && (this->processor < object.processor) && (this->powerSupply < object.powerSupply) && (this->videoCard < object.videoCard))
		return true;
	return false;
}

bool Monoblock::operator == (Monoblock& object)
{
	/*if (this->brand == object.brand)
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor))
		return true;
	else if ((this->brand == object.brand) && (this->processor == object.processor) && (this->powerSupply == object.powerSupply))
		return true;
	else*/ if ((this->brand == object.brand) && (this->processor == object.processor) && (this->powerSupply == object.powerSupply) && (this->videoCard == object.videoCard))
		return true;
	return false;
}