#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
class Manage {
	Book* books[];
public:
	bool canBorrow();
	void add();
	void deleteBook();
	Book* search();
};
#endif