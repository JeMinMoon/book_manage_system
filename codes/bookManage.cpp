#include "bookManage.h"

BookManage::BookManage(){}
BookManage::~BookManage() {
	for (auto& i : books) {
		delete i;
	}
}

bool BookManage::canBorrow(Book* b) {
	return !b->getState();
}

void BookManage::addBook(string name, string writer, string isbn) {
	books.push_back(new Book(name, writer, isbn));
}

void BookManage::deleteBook(int index) {
	delete books[index]; 
	books.erase(books.begin() + index);
}

int BookManage::searchByName(string name) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i]->getName() == name) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}
int BookManage::searchByWriter(string writer) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i]->getWriter() == writer) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}
int BookManage::searchByIsbn(string isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i]->getIsbn() == isbn) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}