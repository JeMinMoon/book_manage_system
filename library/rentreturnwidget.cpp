#include "rentreturnwidget.h"

rentReturnWidget::rentReturnWidget() {
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
    QFrame* frame1 = new QFrame(this);//입력부분
    QFrame* frame2 = new QFrame(this);//검색된 도서,회원 list 출력되는 부분
    QHBoxLayout* frame1_Layout = new QHBoxLayout(frame1);
    QFrame* frame1_1 = new QFrame(frame1);//도서명, 회원명 입력받는 부분
    QFrame* frame1_2 = new QFrame(frame1);//대출/반납 선택, 확인 버튼
    QFormLayout* formLayout = new QFormLayout(frame1_1);
    QLineEdit* bookEdit = new QLineEdit(frame1_1); //도서명 입력
    QLineEdit* userEdit = new QLineEdit(frame1_1); //회원명 입력
    QHBoxLayout* frame1_2_Layout = new QHBoxLayout(frame1_2);
    QComboBox* rentReturnBox = new QComboBox(frame1_2);
    rentReturnBox->addItem("대출");
    rentReturnBox->addItem("반납");
    QPushButton* submitButton = new QPushButton("확인",frame1_2);
    bookList = new QTableWidget(0, 6);
    QStringList book_labels;
    book_labels << tr("제목") << tr("저자") << tr("ISBN") << tr("대출가능여부") << tr("대출일") << tr("반납일");
    bookList->setHorizontalHeaderLabels(book_labels);
    bookList->verticalHeader()->hide();
    bookList->setShowGrid(false);
    userList = new QTableWidget(0, 9);
    QStringList user_labels;
    user_labels << tr("이름") << tr("ID") << tr("대출여부") << tr("대출한 책 제목1") << tr("대출일") << tr("반납일") << tr("대출한 책 제목2") << tr("대출일") << tr("반납일");
    userList->setHorizontalHeaderLabels(user_labels);
    userList->verticalHeader()->hide();
    userList->setShowGrid(false);
    QHBoxLayout* frame2_Layout = new QHBoxLayout(frame2);

    frame2_Layout->addWidget(bookList);
    frame2_Layout->addWidget(userList);
    frame2->setLayout(frame2_Layout);
    frame1_2_Layout->addWidget(rentReturnBox);
    frame1_2_Layout->addWidget(submitButton);
    frame1_2->setLayout(frame1_2_Layout);
    formLayout->addRow("도서명",bookEdit);
    formLayout->addRow("회원명",userEdit);
    frame1_1->setLayout(formLayout);
    frame1_Layout->addWidget(frame1_1);
    frame1_Layout->addWidget(frame1_2);
    frame1->setLayout(frame1_Layout);
    vBoxLayout->addWidget(frame1);
    vBoxLayout->addWidget(frame2);
    setLayout(vBoxLayout);
}

void rentReturnWidget::printBookList(vector<Book>& books){
    QTableWidgetItem* item;
    for (int i=0; i<books.size();i++) {
        bookList->insertRow(i);
        item = new QTableWidgetItem(tr(books[i].getName()));
        bookList->setItem(i,0,item);
        item = new QTableWidgetItem(tr(books[i].getWriter()));
        bookList->setItem(i,1,item);
        item = new QTableWidgetItem(tr(books[i].getIsbn()));
        bookList->setItem(i,2,item);
        if (!books[i].getState()) { // 대출가능여부
            item = new QTableWidgetItem(tr("O"));
        }
        else {
            item = new QTableWidgetItem(tr("X"));
        }
        bookList->setItem(i,3,item);
        item = new QTableWidgetItem(Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d"));
        bookList->setItem(i,4,item); // 대출일
        item = new QTableWidgetItem(Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d"));
        bookList->setItem(i,5,item); // 반납예정일

    }
}

void rentReturnWidget::printUserList(vector<Person>& users){
    QTableWidgetItem* item;
    for(int i=0; i<users.size(); i++){
        userList->insertRow(i);
        item = new QTableWidgetItem(tr(users[i].getName()));
        userList->setItem(i,0,item);
        item = new QTableWidgetItem(users[i].getId());
        userList->setItem(i,1,item);
        if(users[i].getborrowCount()){ // 빌린 책이 있으면 O, 없으면 X
            Book* borrowBooks = users[i].getborrowBooks();
            item = new QTableWidgetItem(tr("O"));
            userList->setItem(i,2,item);
            item = new QTableWidgetItem(borrowBooks[0].getName());
            userList->setItem(i,3,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getborrowDate(),"%Y-%m-%d"));
            userList->setItem(i,4,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getreturnDate(),"%Y-%m-%d"));
            userList->setItem(i,5,item);
            item = new QTableWidgetItem(borrowBooks[1].getName());
            userList->setItem(i,6,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getborrowDate(),"%Y-%m-%d"));
            userList->setItem(i,7,item);
            item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getreturnDate(),"%Y-%m-%d"));
            userList->setItem(i,8,item);
        }
        else{
            item = new QTableWidgetItem(tr("X"));
            userList->setItem(i,2,item);
        }
    }
}

void rentReturnWidget::printAddedBook(vector<Book>& books){
    QTableWidgetItem* item;
    int i = books.size()-1;
    bookList->insertRow(i);
    item = new QTableWidgetItem(tr(books[i].getName()));
    bookList->setItem(i,0,item);
    item = new QTableWidgetItem(tr(books[i].getWriter()));
    bookList->setItem(i,1,item);
    item = new QTableWidgetItem(tr(books[i].getIsbn()));
    bookList->setItem(i,2,item);
    if (!books[i].getState()) { // 대출가능여부
        item = new QTableWidgetItem(tr("O"));
    }
    else {
        item = new QTableWidgetItem(tr("X"));
    }
    bookList->setItem(i,3,item);
    item = new QTableWidgetItem(Date::tmToQString(books[i].getborrowDate(),"%Y-%m-%d"));
    bookList->setItem(i,4,item); // 대출일
    item = new QTableWidgetItem(Date::tmToQString(books[i].getreturnDate(),"%Y-%m-%d"));
    bookList->setItem(i,5,item); // 반납예정일
}

void rentReturnWidget::printAddedUser(vector<Person>& users){
    QTableWidgetItem* item;
    int i = users.size()-1;
    userList->insertRow(i);
    item = new QTableWidgetItem(tr(users[i].getName()));
    userList->setItem(i,0,item);
    item = new QTableWidgetItem(users[i].getId());
    userList->setItem(i,1,item);
    if(users[i].getborrowCount()){ // 빌린 책이 있으면 O, 없으면 X
        Book* borrowBooks = users[i].getborrowBooks();
        item = new QTableWidgetItem(tr("O"));
        userList->setItem(i,2,item);
        item = new QTableWidgetItem(borrowBooks[0].getName());
        userList->setItem(i,3,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getborrowDate(),"%Y-%m-%d"));
        userList->setItem(i,4,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[0].getreturnDate(),"%Y-%m-%d"));
        userList->setItem(i,5,item);
        item = new QTableWidgetItem(borrowBooks[1].getName());
        userList->setItem(i,6,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getborrowDate(),"%Y-%m-%d"));
        userList->setItem(i,7,item);
        item = new QTableWidgetItem(Date::tmToQString(borrowBooks[1].getreturnDate(),"%Y-%m-%d"));
        userList->setItem(i,8,item);
    }
    else{
        item = new QTableWidgetItem(tr("X"));
        userList->setItem(i,2,item);
    }
}
