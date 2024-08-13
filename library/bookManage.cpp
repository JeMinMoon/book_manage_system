#define _CRT_SECURE_NO_WARNINGS
#include "bookManage.h"
#include "bookwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QApplication>

BookManage::BookManage() { givID = 0; }
BookManage::~BookManage() {

}

bool BookManage::canBorrow(Book* b) {
    return !b->getState(); // can borrow = 1
}

void BookManage::addBook(const char* name, const char* writer, const char* isbn) {
    books.push_back(*(new Book(name, writer, isbn)));
}

/*
void BookManage::deleteBook(int index) {
    books.erase(books.begin() + index);
    qDebug() << "delete success";
    bookwidget::printBookList(books_searched);
}
*/

int BookManage::searchByWriter(const char* writer) {
    for (int i = 0; i < books.size(); i++) {
        if (!strcmp(books[i].getWriter(), writer)) {
            return i;
        }
    }
    return -1; // 못 찾은 경우
}
/*
int BookManage::searchByIsbn(const char* isbn) {
    for (int i = 0; i < books.size(); i++) {
        if (!strcmp(books[i].getIsbn(), isbn)) {
            return i;
        }
    }
    return -1; // 못 찾은 경우
}
*/

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
            qDebug() << temp.getName(); // test
            user_list.push_back(temp);
            qDebug() << user_list.back().getName(); //test
        }

        ifs.close();
    }
    catch (const char* s) {
        qDebug() << s;
    }
    qDebug() << "로드 완료\n";
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
        qDebug() << "회원명:" << i.getName() << " Id:" << i.getId();
        qDebug() << "빌린 책 총 " << i.getborrowCount() << "권";
        if (i.getborrowCount() != 0) {
            qDebug() << "빌린 책 목록";
            Book* blist = i.getborrowBooks();
            for (int j = 0; j < i.getborrowCount(); j++) {
                qDebug() << j << ">>";
                blist[j].printBook();
            }
        }
    }
}

void BookManage::Borrow(int idx_b, int idx_u) {
    if (books[idx_b].getState() == 0) { // 책은 있어
        // 사람도 있어?
        if (user_list[idx_u].checkCanBorrow(1) == 1) { // ㅇㅇ 있어
            //Date d;
            //tm now = d.getNow_time_t(); // 현재 날짜 저장
            //tm after_two_weeks = d.getAfterTwoWeek(); // 현재 날짜 + 2주
            //cout << "today date: " << put_time(&now, "%Y-%m-%d") << endl;
            //cout << "return due date: " << put_time(&after_two_weeks, "%Y-%m-%d") <<  endl;
            // 대출 상태 토글 및 대출일, 반납일, 빌린사람 추가
            books[idx_b].borrow();
            // 사용자의 빌린 책 권수랑 빌린 책 목록 변경
            user_list[idx_u].Borrow(&books[idx_b]);
        }
    }
    else { // 책이 없어
        cout << "cannot borrow" << endl;
    }
}

void BookManage::returnBook(int idx_b, int idx_u) {
    Book* blist = user_list[idx_u].getborrowBooks();
    for (int i = 0; i < user_list[idx_u].getborrowCount(); i++) {
        if (books[idx_b].getIsbn() == blist[i].getIsbn()) {
            // 대출 상태 토글 및 대출일, 반납일, 빌린사람 내용 삭제
            books[idx_b].returnBook();
            // 사용자의 빌린 책 권수fin랑 빌린 책 목록 변경
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
    qDebug() << "cannot find user";
    return -1;
}


int BookManage::addUser(const char* s) {
    user_list.push_back(Person(s, givID++));
    return user_list[user_list.size() - 1].getId();
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
            Book* blist = i.getborrowBooks();
            auto now = chrono::system_clock::now();
            time_t now_time_t = chrono::system_clock::to_time_t(now);
            tm now_tm = *localtime(&now_time_t);
            for (int j = 0; j < i.getborrowCount(); j++) {
                if (Date::timeOver(*(blist[j].getreturnDate()), now_tm)) {
                    cout << endl;
                    cout << j << ">>" << endl;
                    blist[j].printBook();
                    check = true;
                }
            }
            if (check == true) cout << "회원명:" << i.getName() << " Id:" << i.getId() << endl;
        }
    }
}
