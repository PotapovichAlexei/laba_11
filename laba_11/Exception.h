#pragma once
#include "Header.h"

#define inputError 100 //������ ����� 1xx

//����� ����������
class Exception {
protected:
	string message;
public:
	Exception(string message) : message(message) { }
	virtual ~Exception() { }
};
	
//����� ���������� �����
class ExceptionInput : public Exception {
private:
	int code;
public:
	ExceptionInput(int code, string message) : code(code + inputError), Exception(message) { }
	void printError() { cout << endl << "!!! Error " << this->code << " : " << this->message << " !!!" << endl; }
	~ExceptionInput()override { }
};

inline void error() {
	cout << "-! ERROR !-" << endl;
	exit(0);
}


//����� ����� ����� float � �������� ��������� 
inline float inputFloat(const float& minSize, const float& maxSize) {

	bool flag;
	float number;

	rewind(stdin);
	cin.clear();

	do {
		
		try {

			if (!(cin >> number) || cin.get() != '\n')
				throw ExceptionInput(1, "Type is incorrect");

			if (number < minSize || number > maxSize)
				throw ExceptionInput(2, "Range doesn't match");

			flag = false;
		}
		catch (ExceptionInput& obj) {
			flag = true;
			cin.clear();
			obj.printError();
			cout << "-! Enter the number between " << setprecision(3) << minSize << " and " << setprecision(3) << maxSize << " !-" << endl;
			cout << "Try again: ";
		}
		catch (...) {
			flag = true;
			cin.clear();
			cout << endl << "Uknown error" << endl;
			cout << "Try again:" << endl;
		}


	} while (flag);

	return number;
}



//����� ����� ����� int � �������� ��������� 
inline int inputInt (const int& minSize, const int& maxSize) {

	bool flag;
	int number;
	
	rewind(stdin);
	cin.clear();

	do
	{
		try
		{
			try
			{

				if (!(cin >> number) || cin.get() != '\n')
					throw ExceptionInput(4, "Type is incorrect");
				//if (number == 33) throw;
				if (number < minSize || number > maxSize)
					throw ExceptionInput(5, "Range doesn't match");
				
				flag = false;
			}
			catch (ExceptionInput& obj) {
				flag = true;
				rewind(stdin);
				cin.clear();
				if (number == 33) throw;
				obj.printError();
				cout << "-! Enter the number between " << minSize << " and " << maxSize << " !-" << endl;
				cout << "Try again: ";
			}
			catch (...) {
				flag = true;
				cin.clear();
				if (number == 33) throw;
				cout << endl << "Uknown error" << endl;
				cout << "Try again:" << endl;
			}
		}
		catch (...) {
			cout << "Transfer errors" << endl;
		}


	} while (flag);

	return number;
}

//�������� �� ���� ���������� ������
inline string inputString(const int& length) {

	bool flag;
	string str;

	rewind(stdin);
	cin.clear();

	do {
		try {

			getline(cin, str);

			if ( (str.size() > (length - 1)) || (str[0] == '\n' || str[0] == '\0') ) throw ExceptionInput(6, "Lenght error");

			for (int i = 0; i < str.size(); ++i) {
				if (((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))) {
					throw ExceptionInput(7, "The string contains forbidden characters");
				}
			}
			flag = false;
		}
		catch (ExceptionInput& obj) {
			flag = true;
			cin.clear();
			obj.printError();
			cout << "-! Enter information consisting of English " << " !-" << endl;
			cout << "Try again: ";
		}
		catch (...) {
			flag = true;
			cin.clear();
			cout << endl << "Unknown error" << endl;
			cout << "Try again: " << endl;
		}

	} while (flag);

	return str;
}


//������� ����� ������ ����������� �� ����� �������� �����
inline string stringExceptRussian(const int& length) {

	bool flag;
	string str;

	rewind(stdin);
	cin.clear();

	do {
		try {

			getline(cin, str);
			
			if ((str.size() > (length - 1)) || (str[0] == '\n' || str[0] == '\0')) throw ExceptionInput(6, "Lenght error");

			for (int i = 0; str[i]; ++i) {
				if ((str[i] >= '�' && str[i] <= '�') || (str[i] >= '�' && str[i] <= '�')) {
					throw ExceptionInput(8, "The string contains forbidden characters");
				}
			}
			flag = false;
		}
		catch (ExceptionInput& obj) {
			flag = true;
			cin.clear();
			obj.printError();
			cout << "-! Enter information consisting of English and any character !-" << endl;
			cout << "Try again:" << endl;
		}
		catch (...) {
			flag = true;
			cin.clear();
			cout << endl << "Unknown error" << endl;
			cout << "-! Try again !-" << endl;
		}

	} while (flag);

	return str;
}
