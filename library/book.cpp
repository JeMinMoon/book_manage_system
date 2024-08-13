#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"
#include <QDebug>
using namespace std;
tm null_tm = { 0, 0, 0, 1, 0, 0, 0, 0, 0 };
Book::Book() { state = 0; borrowDate = null_tm; returnDate = null_tm; }
Book::Book(const char* name, const char* writer, const char* isbn) {
    state = 0;
    borrowDate = null_tm;
    returnDate = null_tm;
    strcpy(this->name, name);
    strcpy(this->writer, writer);
    strcpy(this->isbn, isbn);
}
int Book::getState() { return state; }
char* Book::getName() { return name; }
char* Book::getWriter() { return writer; }
char* Book::getIsbn() { return isbn; }

tm* Book::getborrowDate() { return &borrowDate; }
tm* Book::getreturnDate() { return &returnDate; }
void Book::stateToggle() {
    state = (state == 0) ? 1 : 0;
}
void Book::borrow() {
    state = (state == 0) ? 1 : 0;
    Date d;
    tm now = d.getNow_time_t(); // 현재 날짜 저장
    tm after_two_weeks = d.getAfterTwoWeek(); // 현재 날짜 + 2주

    borrowDate = now;
    returnDate = after_two_weeks;
}
void Book::returnBook() {
    state = (state == 0) ? 1 : 0;

    borrowDate = null_tm;
    returnDate = null_tm;
}

void Book::printBook() {
    qDebug() << "도서명: " << name << " / 저자: " << writer << " / ISBN: " << isbn;
    if (!state) {
        qDebug() << "대출 가능 여부: O";
    }
    else {
        qDebug() << "대출 가능 여부: X";
        qDebug() << "대출일: " << Date::tmToQString(getborrowDate(), "%Y-%m-%d") << " / 반납예정일: " << Date::tmToQString(&returnDate, "%Y-%m-%d") << '\n';
    }
}
