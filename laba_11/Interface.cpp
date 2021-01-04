#include"Interface.h"
#include <vector>
#include<algorithm>
#include <direct.h>

template<class T>
Interface<T>::Interface(){
}

template<class T>
Interface<T>::~Interface()
{
}

template<class T>
void Interface<T>::BaseMenu()
{
	char location[100];
	_getcwd(location, 100);
	_mkdir("Containers");
	_chdir("Containers");

	int flag = 0, flagtwo;
	do {
	system("CLS");
	cout << "Choose action: " << endl;
	cout << " 1) vector" << endl;
	cout << " 2) MyRing" << endl;
	cout << " 0) exit" << endl;
	cout << "Your choice: ";
	flag = inputInt(0, 2);
		switch (flag)
		{
		case 1: {
			//cout << "" << endl;
			/*Interface<T> vect;
			vect.TypeMenu(1);*/
			
			do {
				system("CLS");
				cout << "\t\t~Vector" << endl << endl;
				cout << "Menu: " << endl;
				cout << " 1) Monoblock" << endl;
				cout << " 2) System Block" << endl;
				cout << " 3) Tablet" << endl;
				cout << " 4) Laptop" << endl;
				cout << " 0) exit" << endl;
				cout << endl << "Select to create: ";
				flagtwo = inputInt(0, 4);

				switch (flagtwo)
				{

				case 1:
				{
					Interface<Monoblock> vect;
					vect.VectorMenu("Monoblock");
					break;
				}

				case 2:
				{
					Interface<SystemBlock> vect;
					vect.VectorMenu("SystemBlock");
					break;
				}

				case 3:
				{
					Interface<Tablet> vect;
					vect.VectorMenu("Tablet");
					break;
				}

				case 4: {
					Interface<Laptop> vect;
					vect.VectorMenu("Laptop");
					break;
				}

				case 0: {
					break;
				}
				default: break;
				}
				cout << endl << "If you want exit input 0, another 1" << endl;
				cout << "Youe choice: " << endl;
				flagtwo = inputInt(0, 1);

			} while (flagtwo != 0);
			break;
		}
		case 2: {
			/*Interface<T> ring;
			ring.TypeMenu(2);*/

			do {
				system("CLS");
				cout << "\t\t~MyRing~" << endl << endl;
				cout << "Menu: " << endl;
				cout << " 1) Monoblock" << endl;
				cout << " 2) System Block" << endl;
				cout << " 3) Tablet" << endl;
				cout << " 4) Laptop" << endl;
				cout << " 0) exit" << endl;
				cout << endl << "Select to create: ";
				flagtwo = inputInt(0, 4);

				switch (flagtwo)
				{

				case 1:
				{
					Interface<Monoblock> ringOfMonoblocks;
					ringOfMonoblocks.RingMenu("Monoblock");
					break;
				}

				case 2:
				{
					Interface<SystemBlock> ringOSystemBlocks;
					ringOSystemBlocks.RingMenu("SystemBlock");
					break;
				}

				case 3:
				{
					Interface<Tablet> ringOfTablets;
					ringOfTablets.RingMenu("Tablet");
					break;
				}

				case 4: {
					Interface<Laptop> ringOfLaptops;
					ringOfLaptops.RingMenu("Laptop");
					break;
				}

				case 0: {
					break;
				}
				default: break;
				}

				cout << endl << "If you want exit input 0, another 1" << endl;
				cout << "Youe choice: " << endl;
				flagtwo = inputInt(0, 1);

			} while (flagtwo != 0);
			break;
		}
		case 0: {
			break;
		}
		}
	} while (flag);
	_chdir(location);
}

template<class T>
inline void Interface<T>::RingMenu(string fname) {
	char location[100];
	_getcwd(location, 100);
	_mkdir("Ring");
	_chdir("Ring");

	MyRing<T> ring;
	MyRing<T> helpRing;
	int flag = 0, index = 0;

	do {
		system("CLS");
		cout << "\t\t~MyRing~" << endl;
		if (ring.getSize() != -1) ring.Begin()->data.Table();
		Iterator<T> begin = ring.Begin();
		if(ring.getSize() != -1) printContByIt(begin);
		cout << "Choose action: " << endl;
		cout << " 1) Push to front" << endl;
		cout << " 2) Push to back" << endl;
		cout << " 3) Insert in index" << endl;
		cout << " 4) Delete element of ring" << endl;
		cout << " 5) Clear ring" << endl;
		cout << " 6) Sort Ascending elements of ring" << endl;
		cout << " 7) Descending sort elements of ring" << endl;
		cout << " 8) Find data" << endl;

		cout << " 9) Print in text file" << endl;
		cout << " 10) Read from text file" << endl;
		cout << " 11) Print in binary file" << endl;
		cout << " 12) Read from binary file" << endl;
		cout << " 13) Clear text file" << endl;
		cout << " 14) Clear binary file" << endl;

		cout << " 0) exit" << endl;
		cout << "Your choice: ";
		flag = inputInt(0, 14);

		switch (flag)
		{
		case 1: {
			//cout << "" << endl;
			ring.inputRing(0);
			break;
		}
		case 2: {
			ring.inputRing(ring.getSize() + 1);
			break;
		}
		case 3: {
			cout << endl << "Enter index from 1 to " << ring.getSize() + 1 << " to push Node: ";

			index = inputInt(1, ring.getSize() + 1);
			T data;
			cin >> data;
			ring.insert(data, index);
			break;
		}
		case 4: {

			if (ring.getSize() != -1) {
				cout << endl << "Enter index from 1 to " << ring.getSize() + 1 << " to delete Node: ";
				index = inputInt(1, ring.getSize() + 1);
				ring.deleteElement(index);
			}
			else {
				cout << "Ring is empty" << endl;
				system("pause");
			}
			break;
		}
		case 5: {
			if (ring.getSize() != -1) {
				ring.clear();
			}
			else {
				cout << "Ring is empty" << endl;
				system("pause");
			}
			break;
		}

		case 6: {
			Iterator<T> begin = ring.Begin();
			sortAscendingCont(begin, ring.getSize());
			break;
		}
		case 7: {
			Iterator<T> begin = ring.Begin();
			sortDescendingCont(begin, ring.getSize());
			break;
		}
		case 8: {

			helpRing.clear();
			findObjectCont(helpRing, ring);
			ring.Begin()->data.Table();
			Iterator<T> begin = helpRing.Begin();
			printContByIt(begin);
			system("pause");
			break;
		}

		case 9: {
			if (ring.Begin()) {
				Iterator<T> tmp = ring.Begin();
				//cout << endl << "Enter file name: ";
				//string name ="CCC";
				//cin >> name;
				TextFile<T> TFile((fname + ".txt").c_str());
				if (TFile.openToInput() && ring.getSize() != -1) {
					do {						
						TFile.inputToFile(tmp.curr->data);
						++tmp;					
					} while (tmp != ring.Begin());					
				}
				else if (ring.getSize() == -1)
					TFile.openToInput();
			}
			break;
		}
		case 10: {

			ring.clear();
			T tmp;
			TextFile<T> TFile((fname + ".txt").c_str());
			if (TFile.openToOutput()) {
				while (true)
				{
					TFile.outputToFile(tmp);
					
					if (TFile.endFile())
						break;
					ring.push_back(tmp);
				}
			}
			break;
		}
		case 11: {
			if (ring.Begin()) {
				Iterator<T> tmp = ring.Begin();
				BinaryFile<T> BFile((fname + ".bin").c_str());
				if (BFile.openToInput() && ring.getSize() != -1) {
					do {
						BFile.inputToFile(tmp.curr->data);
						++tmp;
					} while (tmp != ring.Begin());
					
				}
				else if (ring.getSize() == -1)
					BFile.openToInput();
			}
			break;
		}
		case 12: {

			ring.clear();
			T tmp;
			BinaryFile<T> BFile((fname + ".bin").c_str());
			if (BFile.openToOutput()) {
				while (true)
				{
					BFile.outputToFile(tmp);
					
					if (BFile.endFile())
						break;
					ring.push_back(tmp);

				}
			}
			break;	
		}
		case 13: {
			TextFile<T> TFile((fname + ".txt").c_str());
			TFile.openToInput();
			break;
		}
		case 14: {
			BinaryFile<T> BFile((fname + ".bin").c_str());
			BFile.openToInput();
			break;
		}

		case 0: {
			break;
		}
		default:break;
		}
	} while (flag);
	_chdir(location);
}

template<class T>
void Interface<T>::VectorMenu(string fname)
{
	char location[100];
	_getcwd(location, 100);
	_mkdir("Vector");
	_chdir("Vector");

	vector<T> vect;
	vector<T> helpVect;
	int flag = 0, index = 0;
	do {
		system("CLS");
		cout << "\t\t~Vector~" << endl;

		if (!vect.empty()) {
			vect[0].Table();
			for (auto it : vect) cout << it;
		}
		else {
			cout << "Your vector is empty" << endl << endl;
		}

		cout << "Choose action: " << endl;
		cout << " 1) Push to front" << endl;
		cout << " 2) Push to back" << endl;
		cout << " 3) Insert in index" << endl;
		cout << " 4) Delete element of vector" << endl;
		cout << " 5) Clear vector" << endl;
		cout << " 6) Sort Ascending elements of vector" << endl;
		cout << " 7) Descending sort elements of vector" << endl;
		cout << " 8) Find data" << endl;

		cout << " 9) Print in text file" << endl;
		cout << " 10) Read from text file" << endl;
		cout << " 11) Print in binary file" << endl;
		cout << " 12) Read from binary file" << endl;
		cout << " 13) Clear text file" << endl;
		cout << " 14) Clear binary file" << endl;

		cout << " 0) exit" << endl;
		cout << "Your choice: ";
		flag = inputInt(0, 14);

		switch (flag)
		{
		case 1: {
			//cout << "" << endl;
			T data;
			cin >> data;
			vect.insert(vect.begin(),data);
			break;
		}
		case 2: {
			T data;
			cin >> data;
			vect.push_back(data);
			break;
		}
		case 3: {
			cout << endl << "Enter index from 1 to " << vect.size() + 1 << " to push Node: ";

			index = inputInt(1, vect.size() + 1);
			T data;
			cin >> data;
			if (vect.empty()) {
				vect.push_back(data);
			}else
			vect.emplace(vect.begin() + index - 1, data);
			break;
		}
		case 4: {

			if (!vect.empty()) {
				cout << endl << "Enter index from 1 to " << vect.size()  << " to delete Node: ";
				index = inputInt(1, vect.size() );
				vect.erase(vect.begin() + index -1);
			}
			else {
				cout << "Vector is empty" << endl;
				system("pause");
			}
			break;
		}
		case 5: {
			if (!vect.empty()) {
				vect.clear();
			}
			else {
				cout << "Vector is empty" << endl;
				system("pause");
			}
			break;
		}

		case 6: {
			if (!vect.empty()) sort(vect.begin(), vect.end());
			break;
		}
		case 7: {
			if(!vect.empty()) sort(vect.end(), vect.begin());
			break;
		}
		
		case 8: {
			
			helpVect.clear();
			cout << endl << "Enter information to find: ";
			T obj;
			cin >> obj;
			for (auto it : vect) {
				if (it == obj)
					helpVect.push_back(it);
			}

			if (!vect.empty()) {
				vect[0].Table();
				for (auto it : helpVect) cout << it;
			}
			else {
				cout << "Your vector is empty" << endl << endl;
			}
			system("pause");
			break;
		}

		case 9: {
			TextFile<T> TFile((fname + ".txt").c_str());
			if (!vect.empty()) {				
				if (TFile.openToInput()) {

					for (auto it : vect) {
						TFile.inputToFile(it);
					}
				}
			}
			else TFile.openToInput();
			break;
		}
		case 10: {

			vect.clear();
			T tmp;
			TextFile<T> TFile((fname + ".txt").c_str());
			if (TFile.openToOutput()) {
				while (true)
				{
					TFile.outputToFile(tmp);

					if (TFile.endFile())
						break;
					vect.push_back(tmp);
				}
			}
			break;
		}
		case 11: {
			BinaryFile<T> BFile((fname + ".bin").c_str());
			if (!vect.empty()) {
				if (BFile.openToInput()) {
					for (auto it : vect) {
						BFile.inputToFile(it);
					}
				}
			}
			else BFile.openToInput();
			break;
		}
		case 12: {

			vect.clear();
			T tmp;
			BinaryFile<T> BFile((fname + ".bin").c_str());
			if (BFile.openToOutput()) {
				while (true)
				{
					BFile.outputToFile(tmp);

					if (BFile.endFile())
						break;
					vect.push_back(tmp);

				}
			}
			break;
		}
		case 13: {
			TextFile<T> TFile((fname + ".txt").c_str());
			TFile.openToInput();
			break;
		}
		case 14: {
			BinaryFile<T> BFile((fname + ".bin").c_str());
			BFile.openToInput();
			break;
		}

		case 0: {
			break;
		}
		default:break;
		}
	} while (flag);
	_chdir(location);
}

//template<class T>
//void Interface<T>::TypeMenu(){
//
//	int flag = 0;
//	do {
//		system("CLS");
//		cout << "Menu: " << endl;
//		cout << " 1) Monoblock" << endl;
//		cout << " 2) System Block" << endl;
//		cout << " 3) Tablet" << endl;
//		cout << " 4) Laptop" << endl;
//		cout << " 0) exit" << endl;
//		cout << endl << "Select to create: ";
//		flag = inputInt(0, 4);
//
//		switch (flag)
//		{
//
//		case 1:
//		{
//			Interface<Monoblock> ringOfMonoblocks;
//			ringOfMonoblocks.RingMenu();
//			break;
//		}
//
//		case 2:
//		{
//			Interface<SystemBlock> ringOSystemBlocks;
//			ringOSystemBlocks.RingMenu();
//			break;
//		}
//
//		case 3:
//		{
//			Interface<Tablet> ringOfTablets;
//			ringOfTablets.RingMenu();
//			break;
//		}
//
//		case 4: {
//			Interface<Laptop> ringOfLaptops;
//			ringOfLaptops.RingMenu();
//			break;
//		}
//
//		case 0: {
//			return;
//		}
//		default: break;
//		}
//
//		cout << endl << "If you want exit input 0, another 1" << endl;
//		cout << "Youe choice: " << endl;
//		flag = inputInt(0, 1);
//
//	} while (flag != 0);
//}
