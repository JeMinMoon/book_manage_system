#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QLabel>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
class bookwidget: public QWidget {
private:
    QLineEdit* bLineEdit[2];
    QWidget* button;
    QPushButton* add;
    QPushButton* del;
    QPushButton* search;
public:
    bookwidget();
public slots:
    QString getText(int);
    void addB();
    void delB();
    void searchB();
};


#endif // BOOKWIDGET_H
