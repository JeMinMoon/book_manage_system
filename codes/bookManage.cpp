#include "bookManage.h"

BookManage::BookManage() {}
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
	cout << "start searching... " << endl;
	books_searched.clear();
	for (int i = 0; i < books.size(); i++) {
		if (books[i]->getName() == name) {
			cout << books_searched.size() << endl;
			cout << "bookname: " << books[i]->getName() << endl;
			cout << "writer: " << books[i]->getWriter() << endl;
			books_searched.push_back(books[i]);		// ã�� å���� books_searched ���Ϳ� ���� 
		}
	}

	if (books_searched.size() == 0) {
		cout << "cannot find book: " << endl;
		return -1;
	}
	else {
		int n;
		cout << "select number: ";
		cin >> n;
		return n;
	}
}

int BookManage::searchByWriter(string writer) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i]->getWriter() == writer) {
			return i;
		}
	}
	return -1; // �� ã�� ���
}
int BookManage::searchByIsbn(string isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i]->getIsbn() == isbn) {
			return i;
		}
	}
	return -1; // �� ã�� ���
}