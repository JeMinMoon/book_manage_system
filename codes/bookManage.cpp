#include "bookManage.h"

BookManage::BookManage() {}
BookManage::~BookManage() {
	delete[] & books;
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
			books_searched.push_back(&books[i]);		// 찾은 책들을 books_searched 벡터에 넣음 
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
		return searchByIsbn(books_searched[n]->getIsbn()); // 여기 뭔가 안 이쁨...
	}
}

int BookManage::searchByWriter(string writer) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getWriter() == writer) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}
int BookManage::searchByIsbn(string isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getIsbn() == isbn) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}

void BookManage::makeBackupFile(const char* file_directory) {
	try {
		FILE* fp = NULL;
		fopen_s(&fp, file_directory, "w");
		if (fp == NULL) {
			throw "파일 오픈 실패\n";
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
			throw "파일 오픈 실패\n";
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
		cout << "도서명: " << i.getName() << "저자: " << i.getWriter() << "ISBN: " << i.getIsbn();
		if (i.getState()) {
			cout << "대출 가능 여부: O";
		}
		else {
			cout << "대출 가능 여부: X";
		}
		cout << "대출일: " << i.getborrowData() << "반납예정일: " << i.getreturnDate() << '\n';
	}
}

void BookManage::Borrow(int idx_b, int idx_u) {
	if (canBorrow(&books[idx_b]) == 0) { // 책은 있어 
		// 사람도 있어?
		if (user_list[idx_u]->checkCanBorrow() == 1) { // ㅇㅇ 있어 
			cout << "today date: 08/01" << endl;
			cout << "return due date: 08/15" << endl;
			// 대출 상태 변경 
			books[idx_b].stateToggle();
			// 대출일, 반납일, 빌린사람 추가해야하는데 함수가 없음 (수정중)
			// 사용자의 빌린 책 권수랑 빌린 책 목록 변경
			user_list[idx_u]->Borrow(&books[idx_b]);
		}
	}
	else { // 책이 없어
		cout << "cannot borrow" << endl;
	}
}

int BookManage::findUserIdx(string s) {
	for (int i = 0; i < user_list.size(); i++) {
		if (user_list[i]->getName() == s) {
			return i;
		}
	}
	cout << "cannot find user" << endl;
	return -1;
}