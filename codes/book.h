#ifndef _BOOK_H
#define _BOOK_H

#include "person.h"

class Person;
class Book {
	int state;					// 0: not borrowed yet, 1: already borrowed
	char name[30];				// bookname
	char writer[30];
	char isbn[20];					// isbn
	Person* borrower;			// info of borrower
	int	borrowDate;				// 책 대출일, 4자리 월일 형식으로 표기, 없을시 0으로 표기 
	int returnDate;				// 책 반납일, 4자리 월일 형식으로 표기, 없을시 0으로 표기 
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
	void borrow(Person* p);
	void returnBook();
	void printBook();
};

#endif