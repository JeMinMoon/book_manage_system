#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
#include <vector>
#include <fstream>
#define NAME_SIZE 30
using namespace std;

class BookManage {
	
	vector<Book*> books_searched;
	vector<Person*> user_list;
public:
	vector<Book> books; //����� ������ �ű�
	BookManage();
	~BookManage();
	bool canBorrow(Book* b);
	void addBook(const char* n, const char* w, const char* i);
	void deleteBook(int index);
	int searchByName(const char* name); // books ������ �ε����� �����ϵ��� ����
	int searchByWriter(const char* writer);
	int searchByIsbn(const char* isbn);
	void Borrow(int idx_b, int idx_u);
	int findUserIdx(const char* s);
	void saveBookFile(const char* file_directory);
	void loadBookFile(const char* file_directory);
	void printAllBooks();
};
#endif