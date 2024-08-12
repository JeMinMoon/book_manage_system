#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QHash>
#include "rentreturnwidget.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QVector>
#include "bookManage.h"
#include "bookwidget.h"
#include "userwidget.h"
#include <QFileDialog>
#include <QByteArray>
#include <vector>
class QAction;
class QMdiArea;
class QTextEdit;
class QMdiSubWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMdiArea* mdiArea;
    QMdiSubWindow* bookSubWin = new QMdiSubWindow;
    QMdiSubWindow* userSubWin = new QMdiSubWindow;
    QMdiSubWindow* rentSubWin = new QMdiSubWindow;
    bookwidget* bookWin;
    userwidget* userWin;
    BookManage* bm = new BookManage();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QAction* makeAction(QString icon, QString text, QString shortcut, QString tooltip, QObject* receiver, const char* slot);
public slots:
    void openFile();
    void saveFile();
    void quit();

    void addBook();
    void deleteBook();
    void searchBook();

    void addUser();
    void deleteUser();
    void searchUser();
    //void printOverdueUser();

    void rentBook();
    void returnBook();

    void addB();
    void delB();
    void searchB();

    void addU();
    void delU();
    void searchU();

};
#endif // MAINWINDOW_H
