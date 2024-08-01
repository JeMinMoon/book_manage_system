#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class BookManage {
<<<<<<< HEAD
	vector<Book> books;
=======
	vector<Book*> books;
>>>>>>> 18bae7f26500659c6e667a0d66e48d03ba560d74
	vector<Book*> books_searched;
public:
	BookManage();
	~BookManage();
	bool canBorrow(Book* b);
	void addBook(string n, string w, string i);
	void deleteBook(int index);
	int searchByName(string name); // books 벡터의 인덱스를 리턴하도록 구현
	int searchByWriter(string writer);
	int searchByIsbn(string isbn);
<<<<<<< HEAD
	void makeBackupFile(const char* file_directory);
	void loadBackupFile(const char* file_directory);
	void printAll();
=======
>>>>>>> 18bae7f26500659c6e667a0d66e48d03ba560d74
	void Borrow(int index);
};
#endif