#ifndef RENTRETURNWIDGET_H
#define RENTRETURNWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include "book.h"
#include "person.h"
#include <vector>

class rentReturnWidget:public QWidget
{
private:
    QTableWidget* bookList;
    QTableWidget* userList;
public:
    rentReturnWidget();
public slots:
    void printBookList(vector<Book>& books);
    void printUserList(vector<Person>& users);
    void printAddedBook(vector<Book>& books);
    void printAddedUser(vector<Person>& users);
};

#endif // RENTRETURNWIDGET_H
