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
    connect(add, SIGNAL(clicked(bool)), this, SLOT(add()));
    connect(del, SIGNAL(clicked(bool)), this, SLOT(del()));
    connect(search, SIGNAL(clicked(bool)), this, SLOT(search()));
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

void bookwidget::addB(){
    /*
    QString bname = bookWin->getText(0);
    QString bwriter = bookWin->getText(1);
    QString bISBN = bookWin->getText(2);
    qDebug() << bname;
    qDebug()<< bwriter;
    qDebug() << bISBN;
*/
    //bm->addBook(bname.toUtf8().constData(), bwriter.toUtf8().constData(), bISBN.toUtf8().constData());
}

void bookwidget::delB(){
   // bm->deleteBook();
}

void bookwidget::searchB(){

}
