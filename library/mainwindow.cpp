#include "mainwindow.h"
#include "userwidget.h"
#include "bookwidget.h"
#include <QApplication>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QTextEdit>
#include <QStatusBar>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QHash>
#include <QFile>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {

    bm = new BookManage();
    // mdiArea 생성
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);
    mdiArea->setViewMode(QMdiArea::TabbedView);     // 새창열기 모드 말고 탭으로 열기 모드 사용
    mdiArea->addSubWindow(bookSubWin);
    bookSubWin->setWindowTitle("Book");
    mdiArea->addSubWindow(userSubWin);
    userSubWin->setWindowTitle("User");
    mdiArea->addSubWindow(rentSubWin);
    rentSubWin->setWindowTitle("Rent/Return");

    // bookSubWin 생성
    bookWin = new bookwidget();
    connect(bookWin->add, SIGNAL(clicked(bool)), this, SLOT(addB()));
    connect(bookWin->del, SIGNAL(clicked(bool)), this, SLOT(delB()));
    connect(bookWin->search, SIGNAL(clicked(bool)), this, SLOT(searchB()));
    bookSubWin->setWidget(bookWin);

    // userSubWin 생성
    userWin = new userwidget();
    connect(userWin->add, SIGNAL(clicked(bool)), this, SLOT(addU()));
    connect(userWin->del, SIGNAL(clicked(bool)), this, SLOT(delU()));
    connect(userWin->search, SIGNAL(clicked(bool)), this, SLOT(searchU()));
    userSubWin->setWidget(userWin);

    // rentSubWin 생성
    rentWin = new rentReturnWidget();
    rentSubWin->setWidget(rentWin);

    // menubar 생성
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // file menu 생성 후 menubar 에 추가
    QMenu* fileMenu = menuBar->addMenu("&File");
    // file menu 내에 action 생성
    QAction* openBookAct = makeAction(":/images/open.png", "book open", "ctrl+O", "open existing file", this, SLOT(openBookFile()));
    QAction* saveBookAct = makeAction(":/images/save.png", "book save", "ctrl+S", "save book file", this, SLOT(saveBookFile()));
    QAction* openUserAct = makeAction(":/images/open.png", "user open", "", "open existing file", this, SLOT(openUserFile()));
    QAction* saveUserAct = makeAction(":/images/save.png", "user save", "", "save user file", this, SLOT(saveUserFile()));
    QAction* quitAct = makeAction(":/images/exit.png", "&quit", "ctrl+Q", "quit program", qApp, SLOT(quit()));
    // file menu 내에 action 추가
    fileMenu->addAction(openBookAct);
    fileMenu->addAction(saveBookAct);
    fileMenu->addAction(openUserAct);
    fileMenu->addAction(saveUserAct);
    fileMenu->addAction(quitAct);

    // book menu 내에 action 생성
    QMenu* bookMenu = menuBar->addMenu("&Book");
    QAction* addBook = makeAction(":/images/addBook.png", "&addBook", "ctrl+Z", "add book", this, SLOT(addBook()));
    QAction* deleteBook = makeAction(":/images/deleteBook.png", "&deleteBook", "ctrl+Z", "delete book", this, SLOT(deleteBook()));
    QAction* searchBook = makeAction(":/images/searchBook.png", "&searchBook", "ctrl+Z", "search book", this, SLOT(searchBook()));
    QAction* rentBook = makeAction(":/images/rent.png", "rentBook", "ctrl+R", "rent book", this, SLOT(rentBook()));
    QAction* returnBook = makeAction(":/images/return.png", "returnBook", "ctrl+shift+R", "return book", this, SLOT(returnBook()));
    // book menu 내에 action 추가
    bookMenu->addAction(addBook);
    bookMenu->addAction(deleteBook);
    bookMenu->addAction(searchBook);
    bookMenu->addAction(rentBook);
    bookMenu->addAction(returnBook);

    // user menu 내에 action 생성
    QMenu* userMenu = menuBar->addMenu("&User");
    QAction* addUser = makeAction(":/images/addUser.png", "addUser", "shift+alt+A", "add user", this, SLOT(addUser()));
    QAction* deleteUser = makeAction(":/images/deleteUser.png", "deleteUser", "shift+alt+D", "delete user", this, SLOT(deleteUser()));
    QAction* searchUser = makeAction(":/images/searchUser.png", "searchUser", "shift+alt+s", "search user", this, SLOT(searchUser()));
    // QAction* printOverdueUser = makeAction(":/images/print.png", "printOverdueUser", "shift+alt+P", "print overdue user", this, SLOT(printOverdueUser()));
    // user menu 내에 action 추가
    userMenu->addAction(addUser);
    userMenu->addAction(deleteUser);
    userMenu->addAction(searchUser);

    // statusbar 추가
    QStatusBar* statusbar = statusBar();
    QLabel* todayDate = new QLabel("Today: 2024/08/08", statusbar);
    QLabel* returnDate = new QLabel("Return: 2024/08/22", statusbar);
    statusbar->addPermanentWidget(todayDate);
    statusbar->addPermanentWidget(returnDate);

}

QAction* MainWindow::makeAction(QString icon, QString text, QString shortcut, QString tooltip, QObject* receiver, const char* slot){
    QAction* tmp = new QAction(QIcon(icon), text, this);
    tmp->setShortcut(shortcut);
    tmp->setStatusTip(tooltip);
    connect(tmp, SIGNAL(triggered(bool)), receiver, slot);
    return tmp;
}

void MainWindow::openBookFile(){
    QString filename = QFileDialog::getOpenFileName(this,"Select file to open",
                                                    QDir::home().dirName(),"Text File(*.txt *.html *.c *.cpp *.h)");
    if(!filename.length())return;

    QByteArray byteArray = filename.toUtf8();
    bm->loadBookFile(byteArray.constData());
    bm->printAllBooks();
    bookWin->printBookList(bm->books);
    rentWin->printBookList(bm->books);
}
void MainWindow::openUserFile(){
    QString filename = QFileDialog::getOpenFileName(this,"Select file to open",
                                                    QDir::home().dirName(),"Text File(*.txt *.html *.c *.cpp *.h)");
    if(!filename.length())return;

    QByteArray byteArray = filename.toUtf8();
    bm->loadPersonFile(byteArray.constData());
    bm->PrintAllUsers();
    userWin->printUserList(bm->user_list);
    rentWin->printUserList(bm->user_list);
}

void MainWindow::saveBookFile(){
    QString filename = QFileDialog::getSaveFileName(this, "Select file to save", QDir::home().dirName(),"Text File(*.txt *.html *.c *.cpp *.h)");

    if(!filename.length())return;

    QByteArray byteArray = filename.toUtf8();
    bm->saveBookFile(byteArray.constData());
}
void MainWindow::saveUserFile(){
    QString filename = QFileDialog::getSaveFileName(this, "Select file to save", QDir::home().dirName(),"Text File(*.txt *.html *.c *.cpp *.h)");

    if(!filename.length())return;

    QByteArray byteArray = filename.toUtf8();
    bm->savePersonFile(byteArray.constData());
}

void MainWindow::quit() {}

void MainWindow::addBook() {
    mdiArea->setActiveSubWindow(bookSubWin);
}

void MainWindow::deleteBook(){
    mdiArea->setActiveSubWindow(bookSubWin);
}

void MainWindow::searchBook(){
    mdiArea->setActiveSubWindow(bookSubWin);
}

void MainWindow::rentBook(){
    mdiArea->setActiveSubWindow(rentSubWin);
}

void MainWindow::returnBook(){
    mdiArea->setActiveSubWindow(rentSubWin);
}

void MainWindow::addUser(){
    mdiArea->setActiveSubWindow(userSubWin);
}

void MainWindow::deleteUser(){
    mdiArea->setActiveSubWindow(userSubWin);
}

void MainWindow::searchUser(){
    mdiArea->setActiveSubWindow(userSubWin);
}

void MainWindow::addB(){
    QString bname = bookWin->getText(0);
    QString bwriter = bookWin->getText(1);
    QString bISBN = bookWin->getText(2);
    qDebug() << bname;
    qDebug()<< bwriter;
    qDebug() << bISBN;
    bm->addBook(bname.toUtf8().constData(), bwriter.toUtf8().constData(), bISBN.toUtf8().constData());
    bookWin->printAddedBook(bm->books);
    rentWin->printAddedBook(bm->books);
    QMessageBox::question(this, "-", "책 추가가 완료되었습니다", QMessageBox::Ok);
    bookWin->clear();
}

void MainWindow::delB(){
    QString bname = bookWin->getText(0);
    int idx = bookWin->searchByName(bname.toUtf8().constData(), bm->books);
    if (idx != -1) {
        bookWin->deleteBook(idx, bm->books);
        rentWin->bookList->clearContents();
    }
    bookWin->printBookList(bm->books);
    rentWin->printBookList(bm->books);
}

void MainWindow::searchB(){
    QString bname = bookWin->getText(0);
    int idx = bookWin->searchByName(bname.toUtf8().constData(), bm->books);
    bookWin->printBookList(bm->books);
}

void MainWindow::addU(){ // Id 입력이 안 되고 있음!!!
    QString uname = userWin->getText(0);
    int i = bm->addUser(uname.toUtf8().constData());
    QString str = QString("회원가입이 완료되었습니다. 당신의 id는 %1입니다").arg(i);
    QMessageBox::question(this, "-", str, QMessageBox::Ok);
    userWin->printAddedUser(bm->user_list);
    rentWin->printAddedUser(bm->user_list);
    userWin->clear();
}

void MainWindow::delU(){
    QString uname = userWin->getText(0);
    QString uID = userWin->getText(1);
    bm->deleteUser(uname.toUtf8().constData(), uID.toInt());
    QString str = QString("회원 삭제가 완료되었습니다.");
    QMessageBox::question(this, "-", str, QMessageBox::Ok);
    userWin->userList->clearContents();
    userWin->printUserList(bm->user_list);
    rentWin->userList->clearContents();
    rentWin->printUserList(bm->user_list);
}

void MainWindow::searchU(){
    QString uname = userWin->getText(0);
    QString uID = userWin->getText(1);
    int ok = bm->findUserIdx(uname.toUtf8().constData(), uID.toInt());
    QString str = QString("회원 정보를 찾을 수 없습니다.");
    if (ok == -1) QMessageBox::question(this, "-", str, QMessageBox::Ok);
    else {
        userWin->userList->clearContents();
        vector<Person> user_searched;
        user_searched.push_back(bm->user_list[ok]);
        userWin->printUserList(user_searched);
    }
}


MainWindow::~MainWindow() {}
