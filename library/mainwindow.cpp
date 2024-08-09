#include "mainwindow.h"

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

    // bookSubWin
    QWidget* bookWidget = new QWidget(); // mdiArea 에 바로 layout 추가 안된다
    bookSubWin->setWidget(bookWidget);
    QHBoxLayout* bookWin = new QHBoxLayout();
    bookWin->setContentsMargins(0,0,0,0);

    QTableWidget* bookList = new QTableWidget();
    bookWin->addWidget(bookList);
    QWidget* bookMenuWidget = new QWidget();

    QVBoxLayout* bookMenuLayout = new QVBoxLayout();
    // bookMenuLayout
    // QPushButton* test1 = new QPushButton();
    // QPushButton* test2 = new QPushButton();
    // QPushButton* test3 = new QPushButton();
    // bookMenuLayout->addWidget(test1);
    // bookMenuLayout->addWidget(test2);
    // bookMenuLayout->addWidget(test3);
    // bookWin->addWidget(bookLabelMenu);

    bookWidget->setLayout(bookWin);

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

void MainWindow::addBook() {}
void MainWindow::deleteBook(){}
void MainWindow::searchBook(){}
void MainWindow::rentBook(){}
void MainWindow::returnBook(){}

void MainWindow::addUser(){}
void MainWindow::deleteUser(){}
void MainWindow::searchUser(){}

MainWindow::~MainWindow() {}
