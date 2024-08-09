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

class rentReturnWidget:public QWidget
{
private:
    QListWidget* bookList;
    QListWidget* userList;
public:
    rentReturnWidget();
};

#endif // RENTRETURNWIDGET_H
