#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
#include <vector>
using namespace std;
class BookManage {
	vector<Book*> books;
public:
	BookManage();
	~BookManage();
	bool canBorrow(Book* b);
	void addBook(string n, string w, string i);
	void deleteBook(int index);
	int searchByName(string name); // books ������ �ε����� �����ϵ��� ����
	int searchByWriter(string writer);
	int searchByIsbn(string isbn);
};
#endif