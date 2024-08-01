#include <iostream>
#include <string>
#include "book.h"
#include "person.h"
#include "bookManage.h"

int main() {
	int menu, idx, idx_b, idx_u;
	string s;
	BookManage bm;
	string n, w, i;

	cout << "====================================" << endl;
	cout << "------- Library System Start -------" << endl << endl;

	while (1) {
		cout << "--------------- Menu ---------------" << endl;
		cout << "0. Exit Program" << endl;
		cout << "1. Add Books " << endl;
		cout << "2. Delete Books" << endl;
		cout << "3. Search Books" << endl;
		cout << "4. Rent Book" << endl;
		cout << "5. Add UserInfo" << endl;
		cout << "6. Delete UserInfo" << endl;
		cout << "Select Menu: ";
		cin >> menu;
		if (menu == 0) break;
		cout << endl;

		switch (menu) {
		case 1: { // add books 
			while (1) {
				cout << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter book name: ";
				cin >> n;
				if (n == "0") break;
				cout << "Enter writer: ";
				cin >> w;
				cout << "Enter ISBN: ";
				cin >> i;
				bm.addBook(n, w, i);
			}
			break;
		}
		case 2: // delete book
			cout << "Enter book name: ";
			cin >> n;
			idx = bm.searchByName(n);
			if (idx != -1) bm.deleteBook(idx);
			break; 
		case 3: // search book
			cout << "Enter book name: ";
			cin >> n;
			idx = bm.searchByName(n);
			if (idx != -1) {
				cout << "Info of book that you've found" << endl;
				// 정보 입출력해줘야 함 
			}
			break;
		case 4: // rent book 
			cout << "Enter book name: ";
			cin >> n;
			idx_b = bm.searchByName(n);
			cout << "Enter user name: ";
			cin >> s;
			idx_u = bm.findUserIdx(s);
			if (idx != -1) {
				bm.Borrow(idx_b, idx_u);
			}
			break;
		case 5: // add user info
			cout << "Enter user name: ";
			cin >> s;
			bm.addUser(s);
			break;
		case 6:
			cout << "Enter user name: ";
			cin >> s;
			bm.deleteUser(s);
			break;
		}
	}
	
	cout << endl;
	cout << "-------- Library System End --------" << endl;
	cout << "====================================" << endl;
}