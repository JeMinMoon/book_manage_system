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
class userwidget: public QWidget {
private:
    QWidget* button;
    QLineEdit* uLineEdit[2];
public:
    QPushButton* add;
    QPushButton* del;
    QPushButton* search;
    userwidget();
    QString getText(int);
    void clear();
};

#endif // USERWIDGET_H
