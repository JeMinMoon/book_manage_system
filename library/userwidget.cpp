#include "userwidget.h"
#include <QFormLayout>
#include <QLineEdit>
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
    userLabels << "제목" << "저자";
    QLineEdit* uLineEdit[2];
    QFormLayout* uFormLayout = new QFormLayout;
    for (int i =0;i<2; i++) {
        uLineEdit[i] = new QLineEdit;
        uFormLayout->addRow(userLabels.at(i), uLineEdit[i]);
    }
    userMenu->setLayout(uFormLayout);
    userWinLayout->addWidget(userMenu);

    setLayout(userWinLayout);
}
