#include "bookManage.h"
#include "bookwidget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QButtonGroup>
#include <QTableWidgetItem>
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
        item->setText("testaaaaaaaaaaaaa");
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
        item = new QTableWidgetItem(Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d"));
        bookList->setItem(i,4,item); // 대출일
        item = new QTableWidgetItem(Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d"));
        bookList->setItem(i,5,item); // 반납예정일

    }
}
void bookwidget::printAddedBook(vector<Book>& books){
    QTableWidgetItem* item;
    int i = books.size()-1;
    bookList->insertRow(i);
    item = new QTableWidgetItem(tr(books[i].getName()));
    bookList->setItem(i,0,item);
    item->setText("testaaaaaaaaaaaaa");
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
    item = new QTableWidgetItem(Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d"));
    bookList->setItem(i,4,item); // 대출일
    item = new QTableWidgetItem(Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d"));
    bookList->setItem(i,5,item); // 반납예정일
}
