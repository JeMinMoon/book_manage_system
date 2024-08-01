#ifndef _BOOK_H
#define _BOOK_H
#include "person.h"

class Book {
	int state;					// 0: , 1: already borrowed
	string name;				// bookname
	string writer;
	long isbn;					// isbn
	Person* borrower;			// å ������ ���
	int	borrowDate;				// å ������, 4�ڸ� ���� �������� ǥ��, ������ 0���� ǥ�� 
	int returnDate;				// å �ݳ���, 4�ڸ� ���� �������� ǥ��, ������ 0���� ǥ�� 

public :
	int getState();
	string getName();
	string getWriter();
	long getIsbn();
	Person* getBorrower();		// ������ ��� ���� �������� 
	int getborrowData();
	int getreturnDate();
	void stateToggle();			// ���� ���� ��� 
};

#endif