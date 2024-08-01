#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class BookManage {
	vector<Book> books;
	vector<Book*> books_searched;
public:
	BookManage();
	~BookManage();
	bool canBorrow(Book* b);
	void addBook(string n, string w, string i);
	void deleteBook(int index);
	int searchByName(string name); // books ������ �ε����� �����ϵ��� ����
	int searchByWriter(string writer);
	int searchByIsbn(string isbn);
	void makeBackupFile(const char* file_directory);
	void loadBackupFile(const char* file_directory);
	void printAll();
	void Borrow(int index);
};
#endif