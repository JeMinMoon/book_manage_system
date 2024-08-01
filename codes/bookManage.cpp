#include "bookManage.h"

BookManage::BookManage() {}
BookManage::~BookManage() {
	delete[] &books;
}

bool BookManage::canBorrow(Book* b) {
	return !b->getState();
}

void BookManage::addBook(string name, string writer, string isbn) {
	books.push_back(*(new Book(name, writer, isbn)));
}

void BookManage::deleteBook(int index) {
	books.erase(books.begin() + index);
}

int BookManage::searchByName(string name) {
	cout << "start searching... " << endl;
	books_searched.clear();
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getName() == name) {
			cout << books_searched.size() << endl;
			cout << "bookname: " << books[i].getName() << endl;
			cout << "writer: " << books[i].getWriter() << endl;
			books_searched.push_back(&books[i]);		// ã�� å���� books_searched ���Ϳ� ���� 
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
		return searchByIsbn(books_searched[n]->getIsbn()); // ���� ���� �� �̻�...
	}
}

int BookManage::searchByWriter(string writer) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getWriter() == writer) {
			return i;
		}
	}
	return -1; // �� ã�� ���
}
int BookManage::searchByIsbn(string isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getIsbn() == isbn) {
			return i;
		}
	}
	return -1; // �� ã�� ���
}

void BookManage::makeBackupFile(const char* file_directory) {
	try {
		FILE* fp = NULL;
		fopen_s(&fp, file_directory, "w");
		if (fp == NULL) {
			throw "���� ���� ����\n";
			fclose(fp);
		}

		fwrite(&books, sizeof(Book), books.size(), fp);

		fclose(fp);
	}
	catch (const char* s) {
		cout << s;
	}
}

void BookManage::loadBackupFile(const char* file_directory) {
	try {
		FILE* fp = NULL;
		fopen_s(&fp, file_directory, "r");
		if (fp == NULL) {
			throw "���� ���� ����\n";
			fclose(fp);
		}

		fread(&books, sizeof(Book), books.size(), fp);

		fclose(fp);
	}
	catch (const char* s) {
		cout << s;
	}
}

void BookManage::printAll() {
	for (auto& i : books) {
		cout << "������: " << i.getName() << "����: " << i.getWriter() << "ISBN: " << i.getIsbn();
		if (i.getState()) {
			cout << "���� ���� ����: O";
		}
		else {
			cout << "���� ���� ����: X";
		}
		cout << "������: " << i.getborrowData() << "�ݳ�������: " << i.getreturnDate() << '\n';
	}
}

void BookManage::Borrow(int index) {
	if (canBorrow(books[index]) == 1) { // ���� �� �ִ� ��Ȳ
		cout << "today date: 08/01" << endl;
		cout << "return due date: 08/15" << endl; 
	}
	else {
		cout << "cannot borrow" << endl;
	}
