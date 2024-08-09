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
    QLineEdit* bLineEdit[3];
    QWidget* button;
public:
    QPushButton* add;
    QPushButton* del;
    QPushButton* search;
    bookwidget();
    QString getText(int);
};


#endif // BOOKWIDGET_H
