#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QLabel>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QPushButton>
#include "Person.h"
#include "book.h"
#include <vector>
class userwidget: public QWidget {
private:
    QWidget* button;
    QLineEdit* uLineEdit[2];
public:
    QPushButton* add;
    QPushButton* del;
    QPushButton* search;
    QTableWidget* userList;
    userwidget();
    QString getText(int);
    void clear();
    void printUserList(vector<Person>& users);
    void printAddedUser(vector<Person>& users);
};

#endif // USERWIDGET_H
