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
    bookList = new QListWidget(frame2);
    userList = new QListWidget(frame2);
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
