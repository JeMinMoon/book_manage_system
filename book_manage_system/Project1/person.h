#ifndef _PERSON_H
#define _PERSON_H
#include <string>
using namespace std;
#include "book.h"

class Person {
	string name;
	int	id;
	int borrowCount;	 // √÷¥Î 2±«
	Book* borrowBooks[2];
};

#endif