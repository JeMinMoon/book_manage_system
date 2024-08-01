#include <iostream>
#include <string>
using namespace std;
#include "book.h"
#include "person.h"
#include "bookManage.h"

int main() {
	int menu;

	cout << "====================================" << endl;
	cout << "------- Library System Start -------" << endl << endl;

	while (1) {
		cout << "--------------- Menu ---------------" << endl;
		cout << "1. Add Books " << endl;
		cout << "2. Delete Books" << endl;
		cout << "3. Search Books" << endl;
		cout << "4. Rent Book" << endl;
		cout << "Enter 0 to exit" << endl;
		cout << "Select Menu: ";
		cin >> menu;
		if (menu == 0) break;

		switch (menu) {
		case 1:
			break;
		case 2:
			break; 
		case 3:
			break;
		case 4:
			break;
		}
	}
	
	cout << endl;
	cout << "-------- Library System End --------" << endl;
	cout << "====================================" << endl;
}