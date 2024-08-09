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

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {

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
    //QAction* addBook = bookWin->add
    connect(add, SIGNAL(clicked(bool)), this, SLOT(addBook()));
    connect(del, SIGNAL(clicked(bool)), this, SLOT(delBook()));
    connect(search, SIGNAL(clicked(bool)), this, SLOT(searchBook()));
    bookSubWin->setWidget(bookWin);

    // userSubWin 생성
    QWidget* userWin = new userwidget();
    userSubWin->setWidget(userWin);

    // rentSubWin 생성
    QWidget* rentWin = new rentReturnWidget();
    rentSubWin->setWidget(rentWin);

    // menubar 생성
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // file menu 생성 후 menubar 에 추가
    QMenu* fileMenu = menuBar->addMenu("&File");
    // file menu 내에 action 생성
    QAction* openAct = makeAction(":/images/open.png", "&open", "ctrl+O", "open existing file", this, SLOT(openFile()));
    QAction* saveAct = makeAction(":/images/save.png", "&save", "ctrl+S", "save file", this, SLOT(saveFile()));
    QAction* quitAct = makeAction(":/images/exit.png", "&quit", "ctrl+Q", "quit program", qApp, SLOT(quit()));
    // file menu 내에 action 추가
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
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

void MainWindow::openFile(){

}

void MainWindow::saveFile(){

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

MainWindow::~MainWindow() {}
