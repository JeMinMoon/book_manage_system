#include <iostream>
using namespace std;
#include "person.h"

Person::Person() { borrowCount = 0; }
Person::Person(string s) { name = s; borrowCount = 0; }
string Person::getName() { return name; }
int Person::getId() { return id; }
bool Person::checkCanBorrow() {
	if (borrowCount < 2) { // 대출 권수 2권 미만이라 대출 가능 
		// 연체되지 않았는지 확인 
		for (int i = 0; i < 2; i++) {
			if (borrowBooks[i]->getreturnDate() < 801) { // 연체된 상황
				cout << "cannot borrow. due date is over. return book first." << endl;
				return false;
			}
		}
		// 연체되지도 않았고 대출 권수도 가능해서 대출 가능 
		return true;
	}
	else return false; // 대출 권수 초과로 대출 불가 
}

void Person::Borrow(Book* b) {
	borrowCount++;
	borrowBooks[borrowCount] = b;
}