#include "Header.h"

void menu() {
	//¬вод типа машины
	cout << "Input type of VM" << endl;
	cout << "1) Laptop" << endl;
	cout << "2) Tablet" << endl;
	cout << "3) System block" << endl;
	cout << "4) Monoblock" << endl;
	cout << "Your choice: ";

	int typeOfVM = 0;
	typeOfVM = inputInt(1, 4);

	int amount;
	switch (typeOfVM) {
		//Laptops
	case 1: {
		cout << "Input amoung of laptops: ";

		amount = inputInt(1, 20);
		Laptop* laptops = new Laptop[amount];

		laptops->Initialization(laptops, amount);
		break;
	}

		  //Tablets
	case 2: {
		cout << "Input amoung of tablets: ";
		amount = inputInt(1, 20);
		Tablet* tablets = new Tablet[amount];

		tablets->Initialization(tablets, amount);
		break;
	}

		  //System Blocks
	case 3: {
		cout << "Input amoung of system blocks: ";
		amount = inputInt(1, 20);
		SystemBlock* systemBlocks = new SystemBlock[amount];

		systemBlocks->Initialization(systemBlocks, amount);

		break;
	}

		  //Monoblocks
	case 4: {
		cout << "Input amoung of monoblocks: ";
		amount = inputInt(1, 20);
		Monoblock* monoblocks = new Monoblock[amount];

		monoblocks->Initialization(monoblocks, amount);
		break;
	}
		  break;
	}
}