#include <iostream>
using namespace std;
#include "book.h"

Book::Book(const char* name, const char* writer, const char* isbn) {
	strcpy(this->name, name);
	strcpy(this->writer, writer);
	strcpy(this->isbn, isbn);
}

Book::Book() { 
	borrowDate = 0; returnDate = 0; 
};

int Book::getState() { return state; }
char* Book::getName() { return name; }
char* Book::getWriter() { return writer; }
char* Book::getIsbn() { return isbn; }
Person* Book::getBorrower() { return borrower; }		
int Book::getborrowData() { return borrowDate; }
int Book::getreturnDate() { return returnDate; }
void Book::stateToggle() { 
	state = (state == 0) ? 1 : 0;
}