#ifndef _PERSON_H
#define _PERSON_H
#include <string>
using namespace std;
#include "book.h"

class Person {
	string name;
	int	id;
	int borrowCount;	 // max = 2
	Book* borrowBooks[2];
public:
	string getName();
	int getId();
};

#endif