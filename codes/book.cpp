#include <iostream>
using namespace std;
#include "book.h"

Book::Book(string name, string writer, string isbn) {
	this->name = name;
	this->writer = writer;
	this->isbn = isbn;
}

Book::Book() { 
	borrowDate = 0; returnDate = 0; 
};

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