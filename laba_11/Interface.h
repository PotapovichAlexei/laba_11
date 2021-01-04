#pragma once
#include "Header.h"

template <typename T>
class Interface{
private:
	T data;
public:
	Interface();
	~Interface();
	static void TypeMenu();
	static void VectorMenu(string fname);
	static void BaseMenu();
	void RingMenu(string fname);
};

//#include"Interface.inl"	