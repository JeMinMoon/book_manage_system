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
	bool checkCanBorrow(int flag); // flag == 1 이면 출력문 출력, == 0 이면 출력문 없이 T/F 만 판단
	void Borrow(Book* b);
	void returnBook();
};

#endif