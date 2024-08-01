#include <iostream>
using namespace std;
#include "person.h"

Person::Person() { borrowCount = 0; }
Person::Person(string s) { name = s; borrowCount = 0; }
string Person::getName() { return name; }
int Person::getId() { return id; }
bool Person::checkCanBorrow() {
	if (borrowCount < 2) { // ���� �Ǽ� 2�� �̸��̶� ���� ���� 
		// ��ü���� �ʾҴ��� Ȯ�� 
		for (int i = 0; i < 2; i++) {
			if (borrowBooks[i]->getreturnDate() < 801) { // ��ü�� ��Ȳ
				cout << "cannot borrow. due date is over. return book first." << endl;
				return false;
			}
		}
		// ��ü������ �ʾҰ� ���� �Ǽ��� �����ؼ� ���� ���� 
		return true;
	}
	else return false; // ���� �Ǽ� �ʰ��� ���� �Ұ� 
}

void Person::Borrow(Book* b) {
	borrowCount++;
	borrowBooks[borrowCount] = b;
}