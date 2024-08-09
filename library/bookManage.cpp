#define _CRT_SECURE_NO_WARNINGS
#include "bookManage.h"
#include <QDebug>

BookManage::BookManage() {}
BookManage::~BookManage() {
	
}

bool BookManage::canBorrow(Book* b) {
	return !b->getState(); // can borrow = 1 
}

void BookManage::addBook(const char* name, const char* writer, const char* isbn) {
	books.push_back(*(new Book(name, writer, isbn)));
}

void BookManage::deleteBook(int index) {
	books.erase(books.begin() + index);
	cout << "Delete Success" << endl;
}

int BookManage::searchByName(const char* name) {
	cout << "start searching... " << endl;
	cout << endl;
	books_searched.clear();
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getName(), name)) {
			cout << books_searched.size() << ". bookname: " << books[i].getName() << endl;
			cout << "writer: " << books[i].getWriter() << endl << endl;
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
void BookManage::savePersonFile(const char* file_directory) {
	try {
		ofstream ofs(file_directory, ios::binary);
		if (!ofs) {
			throw "파일 오픈 실패\n";
		}

		for (auto i : user_list) {
			ofs.write(reinterpret_cast<const char*>(&i), sizeof(Person));
		}


		ofs.close();
	}
	catch (const char* s) {
		cout << s;
	}
	cout << "저장 완료\n";
}
void BookManage::loadPersonFile(const char* file_directory) {
	user_list.clear();
	try {
		ifstream ifs(file_directory, ios::binary);
		if (!ifs) {
			throw "파일 오픈 실패\n";
		}
		Person temp;
		while (ifs.read(reinterpret_cast<char*>(&temp), sizeof(Person))) {
			user_list.push_back(temp);
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
        qDebug() << "도서명:" << i.getName() << " 저자:" << i.getWriter() << " ISBN:" << i.getIsbn();
        if (!i.getState()) {
            qDebug() << " 대출 가능 여부:O";
        }
        else {
            qDebug() << " 대출 가능 여부:X";
        }
        //cout << " 대출일:" << put_time(i.getborrowDate(), "%Y-%m-%d") << " 반납예정일:" << put_time(i.getreturnDate(), "%Y-%m-%d") << '\n';
        qDebug() << " 대출일:" << Date::tmToQString(i.getborrowDate(), "%Y-%m-%d") << " 반납예정일:" << Date::tmToQString(i.getreturnDate(), "%Y-%m-%d") << '\n';
    }
}

void BookManage::PrintAllUsers() {
	for (auto& i : user_list) {
		cout << "회원명:" << i.getName() << " Id:" << i.getId() << endl;
		cout << "빌린 책 총 " << i.getborrowCount() << "권" << endl;
		if (i.getborrowCount() != 0) {
			cout << "빌린 책 목록" << endl;
			Book** blist = i.getborrowBooks();
			for (int j = 0; j < i.getborrowCount(); j++) {
				cout << j << ">>" << endl;
				blist[j]->printBook();
			}
		}
		cout << endl;
	}
}

void BookManage::Borrow(int idx_b, int idx_u) {
	if (books[idx_b].getState() == 0) { // 책은 있어 
		// 사람도 있어?
		if (user_list[idx_u].checkCanBorrow(1) == 1) { // ㅇㅇ 있어 
			cout << "today date: 08/01" << endl;
			cout << "return due date: 08/15" << endl;
			// 대출 상태 토글 및 대출일, 반납일, 빌린사람 추가
			books[idx_b].borrow(&user_list[idx_u]);
			// 사용자의 빌린 책 권수랑 빌린 책 목록 변경
			user_list[idx_u].Borrow(&books[idx_b]);
		}
	}
	else { // 책이 없어
		cout << "cannot borrow" << endl;
	}
}

void BookManage::returnBook(int idx_b, int idx_u) {
	Book** blist = user_list[idx_u].getborrowBooks();
	for (int i = 0; i < user_list[idx_u].getborrowCount(); i++) {
		if (books[idx_b].getIsbn() == blist[i]->getIsbn()) {
			// 대출 상태 토글 및 대출일, 반납일, 빌린사람 내용 삭제 
			books[idx_b].returnBook();
			// 사용자의 빌린 책 권수랑 빌린 책 목록 변경 
			user_list[idx_u].returnBook();
			cout << "Return Success" << endl;
			return;
		}
	}
	cout << "Return failed. Try again. " << endl;
	return;
}

int BookManage::findUserIdx(const char* s, int id) {
	for (int i = 0; i < user_list.size(); i++) {
		if ((!strcmp(user_list[i].getName(), s)) && (id == user_list[i].getId())) {
			return i;
		}
	}
	cout << "cannot find user" << endl;
	return -1;
}


void BookManage::addUser(const char* s) {
	user_list.push_back(Person(s, user_list.size()));
	cout << "회원가입이 완료되었습니다. " << endl;
	cout << "당신의 id는 " << user_list[user_list.size() - 1].getId() << endl;
}

void BookManage::deleteUser(const char* s, int id) {
	int idx = findUserIdx(s, id);
	if (idx != -1) {
		user_list.erase(user_list.begin() + idx);
		cout << "delete success" << endl;
	}
}

void BookManage::printOne(int idx) {
	books[idx].printBook();
}

// 연체자 리스트 출력 
void BookManage::printUserOverdue() {
	bool check = false;
	for (auto& i : user_list) {
		if (!i.checkCanBorrow(0)) {
			Book** blist = i.getborrowBooks();
			auto now = chrono::system_clock::now();
			time_t now_time_t = chrono::system_clock::to_time_t(now);
			tm now_tm = *localtime(&now_time_t);
			for (int j = 0; j < i.getborrowCount(); j++) {
				if (Date::timeOver(*(blist[j]->getreturnDate()), now_tm)) {
					cout << endl;
					cout << j << ">>" << endl;
					blist[j]->printBook();
					check = true;
				}
			}
			if (check == true) cout << "회원명:" << i.getName() << " Id:" << i.getId() << endl;
		}
	}
}
