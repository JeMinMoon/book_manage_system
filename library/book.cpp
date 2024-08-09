#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"
using namespace std;
tm null_tm = { 0, 0, 0, 1, 0, 0, 0, 0, 0 };
Book::Book() { state = 0; borrowDate = null_tm; returnDate = null_tm; }
Book::Book(const char* name, const char* writer, const char* isbn) {
	state = 0; 
	borrowDate = null_tm;
	returnDate = null_tm;
	strcpy(this->name, name);
	strcpy(this->writer, writer);
	strcpy(this->isbn, isbn);
}
int Book::getState() { return state; }
char* Book::getName() { return name; }
char* Book::getWriter() { return writer; }
char* Book::getIsbn() { return isbn; }
Person* Book::getBorrower() { return borrower; }		
tm* Book::getborrowDate() { return &borrowDate; }
tm* Book::getreturnDate() { return &returnDate; }
void Book::stateToggle() { 
	state = (state == 0) ? 1 : 0;
}
void Book::borrow(Person* p) {
	state = (state == 0) ? 1 : 0;
	Date d;
	tm now = d.getNow_time_t(); // 현재 날짜 저장
	tm after_two_weeks = d.getAfterTwoWeek(); // 현재 날짜 + 2주
	borrower = p;
	borrowDate = now;
	returnDate = after_two_weeks;
}
void Book::returnBook() {
	state = (state == 0) ? 1 : 0;
	borrower = NULL;
	borrowDate = null_tm;
	returnDate = null_tm;
}

void Book::printBook() {
	cout << "도서명: " << name << " / 저자: " << writer << " / ISBN: " << isbn << endl;
	if (!state) {
		cout << "대출 가능 여부: O" << endl;
	}
	else {
		cout << "대출 가능 여부: X" << endl;
		cout << "대출일: " << put_time(getborrowDate(), "%Y-%m-%d") << " / 반납예정일: " << put_time(&returnDate, "%Y-%m-%d") << '\n';
	}
}