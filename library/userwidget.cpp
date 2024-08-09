#include "userwidget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QStringList>
userwidget::userwidget(){
    QHBoxLayout* userWinLayout = new QHBoxLayout();
    userWinLayout->setContentsMargins(0,0,0,0);

    // layout 좌측에 들어가는 표
    QTableWidget* userList = new QTableWidget();
    userList = new QTableWidget(0, 9);
    QStringList labels;
    labels << tr("이름") << tr("ID") << tr("대출여부") << tr("대출한 책 제목1") << tr("대출일") << tr("반납일") << tr("대출한 책 제목2") << tr("대출일") << tr("반납일");
    userList->setHorizontalHeaderLabels(labels);
    userList->verticalHeader()->hide();
    userList->setShowGrid(false);
    userWinLayout->addWidget(userList);

    // layout 우측에 들어가는 메뉴
    QGroupBox* userMenu = new QGroupBox("search book");
    QStringList userLabels;
    userLabels << "이름" << "ID";
    QFormLayout* uFormLayout = new QFormLayout;
    for (int i =0;i<2; i++) {
        uLineEdit[i] = new QLineEdit;
        uFormLayout->addRow(userLabels.at(i), uLineEdit[i]);
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
    uFormLayout->addRow(button);
    userMenu->setLayout(uFormLayout);
    userWinLayout->addWidget(userMenu);

    setLayout(userWinLayout);
}

QString userwidget::getText(int i){
    return uLineEdit[i]->text();
}

void userwidget::clear(){
    for (int i =0;i<2;i++){
        uLineEdit[i]->clear();
    }
}
