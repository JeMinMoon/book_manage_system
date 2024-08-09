#include "bookManage.h"
#include "bookwidget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QButtonGroup>
bookwidget::bookwidget() {
    QHBoxLayout* bookWinLayout = new QHBoxLayout();
    bookWinLayout->setContentsMargins(0,0,0,0);

    QTableWidget* bookList = new QTableWidget();
    bookList = new QTableWidget(0, 6);
    QStringList labels;
    labels << tr("제목") << tr("저자") << tr("ISBN") << tr("대출여부") << tr("대출일") << tr("반납일");
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

