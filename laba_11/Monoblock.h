#pragma once
#include "Header.h"


class  Monoblock : public Desktop {
private:
	string videoCard;		//Видеокарта
public:
	Monoblock();
	Monoblock(string _brand, string _processor, int _powerSupply, string _videoCard);
	void setVideoCard(string _videoCard);
	string getVideoCard();
	void Table();
	bool operator > (Monoblock& object);
	bool operator < (Monoblock& object);
	bool operator == (Monoblock& object);
	friend istream& operator>>(istream& in, Monoblock& obj);
	friend ostream& operator<<(ostream& out, Monoblock& obj);
	friend fstream& operator>>(fstream& in, Monoblock& obj);
	friend fstream& operator<<(fstream& out, Monoblock& obj);
	friend ifstream& operator>>(ifstream& in, Monoblock& obj);
	friend ofstream& operator<<(ofstream& out, Monoblock& obj);
	void Initialization(Monoblock* array, int amount);
	//~Monoblock();

};