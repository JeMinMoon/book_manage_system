#include <iostream>
using namespace std;
#include "book.h"

int Book::getState() { return state; }
string Book::getName() { return name; }
string Book::getWriter() { return writer; }
string Book::getIsbn() { return isbn; }
Person* Book::getBorrower() { return borrower; }		
int Book::getborrowData() { return borrowDate; }
int Book::getreturnDate() { return returnDate; }
void Book::stateToggle() { 
	state = (state == 0) ? 1 : 0;
}