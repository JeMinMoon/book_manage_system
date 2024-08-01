#ifndef _PERSON_H
#define _PERSON_H
#include <string>
using namespace std;
#include "book.h"

class Book;
class Person {
	string name;
	int	id;
	int borrowCount;	 // max = 2
	Book* borrowBooks[2];
public:
	Person();
	Person(string s);
	string getName();
	int getId();
	bool checkCanBorrow();
	void Borrow(Book* b);
};

#endif