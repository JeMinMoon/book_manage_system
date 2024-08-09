#ifndef _PERSON_H
#define _PERSON_H
#include <string>
using namespace std;
#include "book.h"

class Book;
class Person {
	char name[30];
	int	id;
	int borrowCount;	 // max = 2
	Book* borrowBooks[2];
public:
	Person();
	Person(const char* s, int size);
	char* getName();
	int getId();
	int getborrowCount();
	Book** getborrowBooks();
	bool checkCanBorrow(int flag); // flag == 1 �̸� ��¹� ���, == 0 �̸� ��¹� ���� T/F �� �Ǵ�
	void Borrow(Book* b);
	void returnBook();
};

#endif