#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"
using namespace std;

Book::Book() { state = 0; borrowDate = 0; returnDate = 0; }
Book::Book(const char* name, const char* writer, const char* isbn) {
	state = 0; 
	borrowDate = 0; 
	returnDate = 0;
	strcpy(this->name, name);
	strcpy(this->writer, writer);
	strcpy(this->isbn, isbn);
}
int Book::getState() { return state; }
char* Book::getName() { return name; }
char* Book::getWriter() { return writer; }
char* Book::getIsbn() { return isbn; }
Person* Book::getBorrower() { return borrower; }		
int Book::getborrowData() { return borrowDate; }
int Book::getreturnDate() { return returnDate; }
void Book::stateToggle() { 
	state = (state == 0) ? 1 : 0;
}
void Book::borrow(Person* p) {
	borrower = p;
	borrowDate = 801;
	returnDate = 815;
}
void Book::returnBook() {
	borrower = NULL;
	borrowDate = 0;
	returnDate = 0;
}

void Book::printBook() {
	cout << "������: " << name << " / ����: " << writer << " / ISBN: " << isbn << endl;
	if (!state) {
		cout << "���� ���� ����: O" << endl;
	}
	else {
		cout << "���� ���� ����: X" << endl;
		cout << "������: " << borrowDate << " / �ݳ�������: " << returnDate << '\n';
	}
}