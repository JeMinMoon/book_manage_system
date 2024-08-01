#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "person.h"

Person::Person() { borrowCount = 0; }
Person::Person(const char* s) { borrowCount = 0; strcpy(name, s); }
char* Person::getName() { return name; }
int Person::getId() { return id; }
bool Person::checkCanBorrow() {
	if (borrowCount < 2) { // ���� �Ǽ� 2�� �̸��̶� ���� ���� 
		// ��ü���� �ʾҴ��� Ȯ�� 
		for (int i = 0; i < borrowCount; i++) {
			if (borrowBooks[i]->getreturnDate() < 801) { // ��ü�� ��Ȳ
				cout << "cannot borrow. due date is over. return book first." << endl;
				return false;
			}
		}
		// ��ü������ �ʾҰ� ���� �Ǽ��� �����ؼ� ���� ���� 
		return true;
	}
	// else if (borrowCount == 0) return true;
	else {
		cout << "cannot borrow. you already borrowed 2 books." << endl;
		return false; // ���� �Ǽ� �ʰ��� ���� �Ұ� 
	}
}

void Person::Borrow(Book* b) {
	borrowBooks[borrowCount] = b;
	borrowCount++;
}