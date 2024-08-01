#include "bookManage.h"

BookManage::BookManage() {}
BookManage::~BookManage() {
	
}

bool BookManage::canBorrow(Book* b) {
	return !b->getState(); // can borrow = 1 / c
}

void BookManage::addBook(const char* name, const char* writer, const char* isbn) {
	books.push_back(*(new Book(name, writer, isbn)));
}

void BookManage::deleteBook(int index) {
	books.erase(books.begin() + index);
}

int BookManage::searchByName(const char* name) {
	cout << "start searching... " << endl;
	cout << endl;
	books_searched.clear();
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getName(), name)) {
			cout << books_searched.size() << ". bookname: " << books[i].getName() << endl;
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

int BookManage::searchByWriter(const char* writer) {
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getWriter(), writer)) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}
int BookManage::searchByIsbn(const char* isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getIsbn(), isbn)) {
			return i;
		}
	}
	return -1; // 못 찾은 경우
}

void BookManage::saveBookFile(const char* file_directory) {
	try {
		ofstream ofs(file_directory, ios::binary);
		if (!ofs) {
			throw "파일 오픈 실패\n";
		}

		for (auto& i : books) {
			ofs.write(reinterpret_cast<const char*>(&i), sizeof(Book));
		}


		ofs.close();
	}
	catch (const char* s) {
		cout << s;
	}
	cout << "저장 완료\n";
}

void BookManage::loadBookFile(const char* file_directory) {
	books.clear();
	try {
		ifstream ifs(file_directory, ios::binary);
		if (!ifs) {
			throw "파일 오픈 실패\n";
		}
		Book temp;
		while (ifs.read(reinterpret_cast<char*>(&temp), sizeof(Book))) {
			books.push_back(temp);
		}

		ifs.close();
	}
	catch (const char* s) {
		cout << s;
	}
	cout << "로드 완료\n";
}

void BookManage::printAllBooks() {
	for (auto& i : books) {
		cout << "도서명:" << i.getName() << " 저자:" << i.getWriter() << " ISBN:" << i.getIsbn();
		if (i.getState()) {
			cout << " 대출 가능 여부:O";
		}
		else {
			cout << " 대출 가능 여부:X";
		}
		cout << " 대출일:" << i.getborrowData() << " 반납예정일:" << i.getreturnDate() << '\n';
	}
}

void BookManage::Borrow(int idx_b, int idx_u) {
	if (books[idx_b].getState() == 0) { // 책은 있어 
		// 사람도 있어?
		if (user_list[idx_u]->checkCanBorrow() == 1) { // ㅇㅇ 있어 
			cout << "today date: 08/01" << endl;
			cout << "return due date: 08/15" << endl;
			// 대출 상태 변경 
			books[idx_b].stateToggle();
			// 대출일, 반납일, 빌린사람 추가해야하는데 함수가 없음
			books[idx_b].borrow(user_list[idx_u]);
			// 사용자의 빌린 책 권수랑 빌린 책 목록 변경
			user_list[idx_u]->Borrow(&books[idx_b]);
		}
	}
	else { // 책이 없어
		cout << "cannot borrow" << endl;
	}
}

int BookManage::findUserIdx(const char* s) {
	for (int i = 0; i < user_list.size(); i++) {
		if (!strcmp(user_list[i]->getName(),s)) {
			return i;
		}
	}
	cout << "cannot find user" << endl;
	return -1;
}

void BookManage::addUser(const char* s) {
	user_list.push_back(new Person(s));
}

void BookManage::deleteUser(const char* s) {
	int idx = findUserIdx(s);
	if (idx != -1) {
		user_list.erase(user_list.begin() + idx);
		cout << "delete success" << endl;
	}
}

void BookManage::printOne(int idx) {
	cout << "도서명: " << books[idx].getName() << " / 저자: " << books[idx].getWriter() << " / ISBN: " << books[idx].getIsbn() << endl;
	if (books[idx].getState()) {
		cout << "대출 가능 여부: O" << endl;
	}
	else {
		cout << "대출 가능 여부: X" << endl;
	}
	cout << "대출일: " << books[idx].getborrowData() << " / 반납예정일: " << books[idx].getreturnDate() << '\n';
}

void BookManage::returnBook(int idx_b, int idx_u) {
	// 대출 상태 변경 
	books[idx_b].stateToggle();
	// 대출일, 반납일, 빌린사람 내용 삭제 
	books[idx_b].returnBook();
	// 사용자의 빌린 책 권수랑 빌린 책 목록 변경 
	user_list[idx_u]->returnBook();
}