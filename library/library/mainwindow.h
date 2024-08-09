#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QHash>
#include <QMdiArea>
#include <QMdiSubWindow>

class QAction;
class QMdiArea;
class QTextEdit;
class QMdiSubWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMdiArea* mdiArea;
    QHash<QAction*, QWidget*> windowHash;
    QMdiSubWindow* bookSubWin = new QMdiSubWindow;
    QMdiSubWindow* userSubWin = new QMdiSubWindow;
    QMdiSubWindow* rentSubWin = new QMdiSubWindow;

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
    void rentBook();
    void returnBook();

    void addUser();
    void deleteUser();
    void searchUser();
    //void printOverdueUser();

};
#endif // MAINWINDOW_H
