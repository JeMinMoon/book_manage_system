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
	Person(const char* s);
	char* getName();
	int getId();
	bool checkCanBorrow();
	void Borrow(Book* b);
	void returnBook();
};

#endif