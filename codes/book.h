#ifndef _BOOK_H
#define _BOOK_H
#include "person.h"

class Person;
class Book {
	int state;					// 0: not borrowed yet, 1: already borrowed
	string name;				// bookname
	string writer;
	string isbn;					// isbn
	Person* borrower;			// info of borrower
	int	borrowDate;				// 책 대출일, 4자리 월일 형식으로 표기, 없을시 0으로 표기 
	int returnDate;				// 책 반납일, 4자리 월일 형식으로 표기, 없을시 0으로 표기 
public :
	Book() {};
	Book(string name, string writer, string isbn);
	int getState();
	string getName();
	string getWriter();
	string getIsbn();
	Person* getBorrower();		// get info about borrower
	int getborrowData();
	int getreturnDate();
	void stateToggle();			// toggle state
};

#endif