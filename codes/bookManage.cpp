#include "bookManage.h"

BookManage::BookManage() {}
BookManage::~BookManage() {
	
}

bool BookManage::canBorrow(Book* b) {
	return !b->getState();
}

void BookManage::addBook(const char* name, const char* writer, const char* isbn) {
	books.push_back(*(new Book(name, writer, isbn)));
}

void BookManage::deleteBook(int index) {
	books.erase(books.begin() + index);
}

int BookManage::searchByName(const char* name) {
	cout << "start searching... " << endl;
	books_searched.clear();
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getName(), name)) {
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

int BookManage::searchByWriter(const char* writer) {
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getWriter(), writer)) {
			return i;
		}
	}
	return -1; // �� ã�� ���
}
int BookManage::searchByIsbn(const char* isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (!strcmp(books[i].getIsbn(), isbn)) {
			return i;
		}
	}
	return -1; // �� ã�� ���
}

void BookManage::saveBookFile(const char* file_directory) {
	try {
		ofstream ofs(file_directory, ios::binary);
		if (!ofs) {
			throw "���� ���� ����\n";
		}
	
		for (auto& i : books) {
			ofs.write(reinterpret_cast<const char*>(&i), sizeof(Book));
		}
		

		ofs.close();
	}
	catch (const char* s) {
		cout << s;
	}
	cout << "���� �Ϸ�\n";
}

void BookManage::loadBookFile(const char* file_directory) {
	books.clear();
	try {
		ifstream ifs(file_directory, ios::binary);
		if (!ifs) {
			throw "���� ���� ����\n";
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
	cout << "�ε� �Ϸ�\n";
}

void BookManage::printAllBooks() {
	for (auto& i : books) {
		cout << "������:" << i.getName() << " ����:" << i.getWriter() << " ISBN:" << i.getIsbn();
		if (i.getState()) {
			cout << " ���� ���� ����:O";
		}
		else {
			cout << " ���� ���� ����:X";
		}
		cout << " ������:" << i.getborrowData() << " �ݳ�������:" << i.getreturnDate() << '\n';
	}
}

void BookManage::Borrow(int idx_b, int idx_u) {
	if (canBorrow(&books[idx_b]) == 0) { // å�� �־� 
		// ����� �־�?
		if (user_list[idx_u]->checkCanBorrow() == 1) { // ���� �־� 
			cout << "today date: 08/01" << endl;
			cout << "return due date: 08/15" << endl;
			// ���� ���� ���� 
			books[idx_b].stateToggle();
			// ������, �ݳ���, ������� �߰��ؾ��ϴµ� �Լ��� ���� (������)
			// ������� ���� å �Ǽ��� ���� å ��� ����
			user_list[idx_u]->Borrow(&books[idx_b]);
		}
	}
	else { // å�� ����
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