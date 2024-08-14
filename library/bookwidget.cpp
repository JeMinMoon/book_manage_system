#include "bookManage.h"
#include "bookwidget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QButtonGroup>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QInputDialog>
bookwidget::bookwidget() {
    QHBoxLayout* bookWinLayout = new QHBoxLayout();
    bookWinLayout->setContentsMargins(0,0,0,0);

    bookList = new QTableWidget(0, 6);
    QStringList labels;
    labels << tr("제목") << tr("저자") << tr("ISBN") << tr("대출가능여부") << tr("대출일") << tr("반납일");
    bookList->setHorizontalHeaderLabels(labels);
    bookList->verticalHeader()->hide();
    bookList->setShowGrid(false);
    bookWinLayout->addWidget(bookList);

    QGroupBox* searchMenu = new QGroupBox("search book");
    QStringList searchLabels;
    searchLabels << "제목" << "저자" << "ISBN";
    QFormLayout* bFormLayout = new QFormLayout;
    for (int i =0;i<3; i++) {
        bLineEdit[i] = new QLineEdit;
        bFormLayout->addRow(searchLabels.at(i), bLineEdit[i]);
    }
    button = new QWidget();
    QHBoxLayout* buttonlayout = new QHBoxLayout();
    add = new QPushButton("add");
    del = new QPushButton("delete");
    search = new QPushButton("search");
    buttonlayout->addWidget(add);
    buttonlayout->addWidget(del);
    buttonlayout->addWidget(search);
    button->setLayout(buttonlayout);
    bFormLayout->addRow(button);
    searchMenu->setLayout(bFormLayout);
    bookWinLayout->addWidget(searchMenu);

    setLayout(bookWinLayout);
}

QString bookwidget::getText(int i){
    return bLineEdit[i]->text();
}

void bookwidget::clear(){
    for (int i =0; i<3;i++){
        bLineEdit[i]->clear();
    }
}

void bookwidget::printBookList(vector<Book>& books){
    QTableWidgetItem* item;
    for (int i=0; i<books.size();i++) {
        bookList->insertRow(i);
        item = new QTableWidgetItem(tr(books[i].getName()));
        bookList->setItem(i,0,item);
        item = new QTableWidgetItem(tr(books[i].getWriter()));
        bookList->setItem(i,1,item);
        item = new QTableWidgetItem(tr(books[i].getIsbn()));
        bookList->setItem(i,2,item);
        if (!books[i].getState()) { // 대출가능여부
            item = new QTableWidgetItem(tr("O"));
        }
        else {
            item = new QTableWidgetItem(tr("X"));
        }
        bookList->setItem(i,3,item);

        QString nulldate = "1900-01-01";
        item = new QTableWidgetItem(Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d"));
        if (Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d") != nulldate) bookList->setItem(i,4,item); // 대출일
        item = new QTableWidgetItem(Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d"));
        if (Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d") != nulldate) bookList->setItem(i,5,item); // 반납예정일
    }
}
void bookwidget::printAddedBook(vector<Book>& books){
    QTableWidgetItem* item;
    int i = books.size()-1;
    bookList->insertRow(i);
    item = new QTableWidgetItem(tr(books[i].getName()));
    bookList->setItem(i,0,item);
    item = new QTableWidgetItem(tr(books[i].getWriter()));
    bookList->setItem(i,1,item);
    item = new QTableWidgetItem(tr(books[i].getIsbn()));
    bookList->setItem(i,2,item);
    if (!books[i].getState()) { // 대출가능여부
        item = new QTableWidgetItem(tr("O"));
    }
    else {
        item = new QTableWidgetItem(tr("X"));
    }
    bookList->setItem(i,3,item);

    QString nulldate = "1900-01-01";
    item = new QTableWidgetItem(Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d"));
    if (Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d") != nulldate) bookList->setItem(i,4,item); // 대출일
    item = new QTableWidgetItem(Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d"));
    if (Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d") != nulldate) bookList->setItem(i,5,item); // 반납예정일
}

int bookwidget::searchByName(const char* name, vector<Book>& books) {
    qDebug() << "start searching... ";
    books_searched.clear();
    for (int i = 0; i < books.size(); i++) {
        if (!strcmp(books[i].getName(), name)) {
            books_searched.push_back(books[i]);		// 찾은 책들을 books_searched 벡터에 넣음
        }
    }

    if (books_searched.size() == 0) {
        QMessageBox::question(this, "-", "요청한 책을 찾을 수 없습니다", QMessageBox::Ok);
        return -1;
    }

    else {
        bookList->clearContents();
        printBookList(books_searched);

        bool ok;
        QString n = QInputDialog::getText(this, "...", "원하는 책의 ISBN를 입력하세요", QLineEdit::Normal, NULL, &ok);
        int tmp = searchByIsbn(n.toUtf8().constData(), books);

        if (tmp == -1) {
            QMessageBox::question(this, "-", "요청한 책을 찾을 수 없습니다.", QMessageBox::Ok);
            return -1;
        }
        else  {
            //qDebug() << tmp;
            return tmp;
        }
    }
}

int bookwidget::searchByIsbn(const char* isbn, vector<Book>& books) {
    for (int i = 0; i < books.size(); i++) {
        if (!strcmp(books[i].getIsbn(), isbn)) {
            return i;
        }
    }
    return -1; // 못 찾은 경우
}

void bookwidget::deleteBook(int index, vector<Book>& books) {
    books.erase(books.begin() + index);
    qDebug() << "delete success";
    bookList->clearContents();
    QMessageBox::question(this, "-", "책 삭제가 완료되었습니다.", QMessageBox::Ok);
}
