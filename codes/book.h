#ifndef _BOOK_H
#define _BOOK_H
#include "person.h"

class Person;
class Book {
	int state;					// 0: not borrowed yet, 1: already borrowed
	char name[30];				// bookname
	char writer[30];
	char isbn[20];						// isbn
	Person* borrower;			// info of borrower
	int	borrowDate;				// å ������, 4�ڸ� ���� �������� ǥ��, ������ 0���� ǥ�� 
	int returnDate;				// å �ݳ���, 4�ڸ� ���� �������� ǥ��, ������ 0���� ǥ�� 
public :
	Book();
	Book(const char* name, const char* writer, const char* isbn);
	int getState();
	char* getName();
	char* getWriter();
	char* getIsbn();
	Person* getBorrower();		// get info about borrower
	int getborrowData();
	int getreturnDate();
	void stateToggle();			// toggle state
};

#endif