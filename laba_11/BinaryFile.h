#pragma once
#include "Header.h"

template<typename T>
class BinaryFile : public File
{
public:
	fstream FileStream;
public:
	BinaryFile(const string = "");
	bool openToInput();
	bool openToOutput();
	void rewindFile();
	void inputToFile(T& Object);
	void printFromFile(T& Object);
	bool endFile();
	~BinaryFile();
};
