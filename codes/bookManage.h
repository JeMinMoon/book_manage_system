#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
#include <vector>
using namespace std;

class BookManage {
	vector<Book> books;
	vector<Book*> books_searched;
	vector<Person*> user_list;
public:
	BookManage();
	~BookManage();
	bool canBorrow(Book* b);
	void addBook(string n, string w, string i);
	void deleteBook(int index);
	int searchByName(string name); // books ������ �ε����� �����ϵ��� ����
	int searchByWriter(string writer);
	int searchByIsbn(string isbn);
	void Borrow(int idx_b, int idx_u);

	void makeBackupFile(const char* file_directory);
	void loadBackupFile(const char* file_directory);
	void printAll();

	// user ���� ���� 
	int findUserIdx(string s);
	void addUser(string s);
	void deleteUser(string s);
};
#endif