#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QHash>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QVector>

class QAction;
class QMdiArea;
class QTextEdit;
class QMdiSubWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMdiArea* mdiArea;
    QVector<QWidget*> windowVector;
    QHash<QAction*, QWidget*> windowHash;
    //QWidget* bookSubWin = new QWidget;
    QMdiSubWindow* bookSubWin = new QMdiSubWindow;
    QWidget* userSubWin = new QWidget;
    QWidget* rentSubWin = new QWidget;

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
