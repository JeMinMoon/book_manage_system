#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "person.h"

Person::Person() { borrowCount = 0; }
Person::Person(const char* s) { borrowCount = 0; strcpy(name, s); }
char* Person::getName() { return name; }
int Person::getId() { return id; }
bool Person::checkCanBorrow() {
	if (borrowCount < 2) { // 대출 권수 2권 미만이라 대출 가능 
		// 연체되지 않았는지 확인 
		for (int i = 0; i < borrowCount; i++) {
			if (borrowBooks[i]->getreturnDate() < 801) { // 연체된 상황
				cout << "cannot borrow. due date is over. return book first." << endl;
				return false;
			}
		}
		// 연체되지도 않았고 대출 권수도 가능해서 대출 가능 
		return true;
	}
	// else if (borrowCount == 0) return true;
	else {
		cout << "cannot borrow. you already borrowed 2 books." << endl;
		return false; // 대출 권수 초과로 대출 불가 
	}
}

void Person::Borrow(Book* b) {
	borrowBooks[borrowCount] = b;
	borrowCount++;
}