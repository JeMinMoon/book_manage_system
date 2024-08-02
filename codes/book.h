#ifndef _BOOK_H
#define _BOOK_H

#include "person.h"
#include <chrono>
#include <iomanip>
#include "date.h"


class Person;
class Book {
	int state;					// 0: not borrowed yet, 1: already borrowed
	char name[30];				// bookname
	char writer[30];
	char isbn[20];					// isbn
	Person* borrower;			// info of borrower
	tm borrowDate;				// å ������, 4�ڸ� ���� �������� ǥ��, ������ 0���� ǥ�� 
	tm returnDate;				// å �ݳ���, 4�ڸ� ���� �������� ǥ��, ������ 0���� ǥ�� 
public :
	Book();
	Book(const char* name, const char* writer, const char* isbn);
	int getState();
	char* getName();
	char* getWriter();
	char* getIsbn();
	Person* getBorrower();		// get info about borrower
	tm* getborrowDate();
	tm* getreturnDate();
	void stateToggle();			// toggle state
	void borrow(Person* p);
	void returnBook();
	void printBook();
};

#endif