#ifndef _BOOKMANAGE_H
#define _BOOKMANAGE_H
#include "book.h"
#include <iostream>
#include <vector>
#include <fstream>
#define NAME_SIZE 30
using namespace std;

class BookManage {
	vector<Book> books;
	vector<Book*> books_searched;
	vector<Person*> user_list;
public:
	BookManage();
	~BookManage();
	bool canBorrow(Book* b);
	void addBook(const char* n, const char* w, const char* i);
	void deleteBook(int index);
	int searchByName(const char* name); // books 벡터의 인덱스를 리턴하도록 구현
	int searchByWriter(const char* writer);
	int searchByIsbn(const char* isbn);

	// 대출 및 반납 
	void Borrow(int idx_b, int idx_u);
	void returnBook(int idx_b, int idx_u);

	void saveBookFile(const char* file_directory);
	void loadBookFile(const char* file_directory);
	void printAllBooks();
	void printOne(int idx);

	// user 관련 내용 
	int findUserIdx(const char* s);
	void addUser(const char* s);
	void deleteUser(const char* s);
};
#endif