#include <iostream>
#include <string>
#include "book.h"
#include "person.h"
#include "bookManage.h"

int main() {
	const char* book_file_directory = "book_file.txt";
	int menu;
	BookManage bm;
	char n[30];
	char w[30];
	char i[20];
	char s[30];
	int idx;
	int idx_b;
	int idx_u;
	
	cout << "====================================" << endl;
	cout << "------- Library System Start -------" << endl << endl;

	while (1) {
		cout << "--------------- Menu ---------------" << endl;
		cout << "0. Exit Program" << endl;
		cout << "1. Add Books " << endl;
		cout << "2. Delete Books" << endl;
		cout << "3. Search Books" << endl;
		cout << "4. Rent Book" << endl;
		cout << "Select Menu: ";
		cin >> menu;
		if (menu == 0) break;
		cout << endl;

		switch (menu) {
		case 1: { // add books 
			while (1) {
				cout << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter book name: " << endl;
				cin >> n;
				if (n == "0") break;
				cout << "Enter writer: " << endl;
				cin >> w;
				cout << "Enter ISBN: " << endl;
				cin >> i;
				bm.addBook(n, w, i);
			}
			break;
		}
		case 2: // delete book
			cout << "Enter book name: " << endl;
			cin >> n;
			idx = bm.searchByName(n);
			if (idx != -1) bm.deleteBook(idx);
			break; 
		case 3: // search book
			cout << "Enter book name: " << endl;
			cin >> n;
			idx = bm.searchByName(n);
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
		}
	}
	
	cout << endl;
	cout << "-------- Library System End --------" << endl;
	cout << "====================================" << endl;

	return 0;
}