#include "userwidget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QStringList>
#include <QString>
userwidget::userwidget(){
    QHBoxLayout* userWinLayout = new QHBoxLayout();
    userWinLayout->setContentsMargins(0,0,0,0);

    // layout 좌측에 들어가는 표
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

void userwidget::printUserList(vector<Person>& users){
    QTableWidgetItem* item;
    for(int i=0; i<users.size(); i++){
        userList->insertRow(i);
        item = new QTableWidgetItem(tr(users[i].getName()));
        userList->setItem(i,0,item);
        QString tmpid;
        tmpid.setNum(users[i].getId());
        item = new QTableWidgetItem(tmpid);
        userList->setItem(i,1,item);
        if(users[i].getborrowCount()){ // 빌린 책이 있으면 O, 없으면 X
            Book* borrowBooks = users[i].getborrowBooks();
            item = new QTableWidgetItem(tr("O"));
            userList->setItem(i,2,item);
            item = new QTableWidgetItem(borrowBooks[0].getName());
            userList->setItem(i,3,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getborrowDate(),"%Y-%m-%d"));
            userList->setItem(i,4,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getreturnDate(),"%Y-%m-%d"));
            userList->setItem(i,5,item);
            item = new QTableWidgetItem(borrowBooks[1].getName());
            userList->setItem(i,6,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getborrowDate(),"%Y-%m-%d"));
            userList->setItem(i,7,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getreturnDate(),"%Y-%m-%d"));
            userList->setItem(i,8,item);
        }
        else{
            item = new QTableWidgetItem(tr("X"));
            userList->setItem(i,2,item);
        }
    }
}

void userwidget::printAddedUser(vector<Person>& users){
    QTableWidgetItem* item;
    int i = users.size()-1;
    userList->insertRow(i);
    item = new QTableWidgetItem(tr(users[i].getName()));
    userList->setItem(i,0,item);
    QString tmpid;
    tmpid.setNum(users[i].getId());
    item = new QTableWidgetItem(tmpid); // item 생성시 int로 생성하는게 안되는듯 -> qstring으로 변환해줌
    userList->setItem(i,1,item);
    if(users[i].getborrowCount()){ // 빌린 책이 있으면 O, 없으면 X
        Book* borrowBooks = users[i].getborrowBooks();
        item = new QTableWidgetItem(tr("O"));
        userList->setItem(i,2,item);
        item = new QTableWidgetItem(borrowBooks[0].getName());
        userList->setItem(i,3,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getborrowDate(),"%Y-%m-%d"));
        userList->setItem(i,4,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getreturnDate(),"%Y-%m-%d"));
        userList->setItem(i,5,item);
        item = new QTableWidgetItem(borrowBooks[1].getName());
        userList->setItem(i,6,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getborrowDate(),"%Y-%m-%d"));
        userList->setItem(i,7,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getreturnDate(),"%Y-%m-%d"));
        userList->setItem(i,8,item);
    }
    else{
        item = new QTableWidgetItem(tr("X"));
        userList->setItem(i,2,item);
    }
}

