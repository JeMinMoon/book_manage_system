#ifndef _BOOK_H
#define _BOOK_H
#include "person.h"

class Book {
	int state;					// 0: , 1: already borrowed
	string name;				// bookname
	string writer;
	long isbn;					// isbn
	Person* borrower;			// 책 빌려간 사람
	int	borrowDate;				// 책 대출일, 4자리 월일 형식으로 표기, 없을시 0으로 표기 
	int returnDate;				// 책 반납일, 4자리 월일 형식으로 표기, 없을시 0으로 표기 

public :
	int getState();
	string getName();
	string getWriter();
	long getIsbn();
	Person* getBorrower();		// 빌려간 사람 정보 가져오기 
	int getborrowData();
	int getreturnDate();
	void stateToggle();			// 대출 상태 토글 
};

#endif