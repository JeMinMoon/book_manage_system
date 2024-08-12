#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include "book.h"
#include <vector>
class bookwidget: public QWidget {
private:
    QLineEdit* bLineEdit[3];
    QWidget* button;
    vector<Book> books_searched;
public:
    QPushButton* add;
    QPushButton* del;
    QPushButton* search;
    QTableWidget* bookList;
    bookwidget();
    QString getText(int);
    void clear();
    void printBookList(vector<Book>& books);
    void printAddedBook(vector<Book>& books);
    void deleteBook(int idx);
    int searchByName(const char* name, vector<Book>& books);
    int searchByIsbn(const char* isbn, vector<Book>& books);
    void deleteBook(int index, vector<Book>& books);
};


#endif // BOOKWIDGET_H
