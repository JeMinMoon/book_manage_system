#include "rentreturnwidget.h"

rentreturnwidget::rentreturnwidget() {
    QVBoxLayout* vBoxLayout = QVBoxLayout(this);
    QFrame* frame1 = new QFrame(this);//입력부분
    QFrame* frame2 = new QFrame(this);//검색된 도서,회원 list 출력되는 부분
    QHBoxLayout* hBoxLayout = QHBoxLayout(frame1);
    QFrame* frame1_1 = new QFrame(frame1);//도서명, 회원명 입력받는 부분
    QFrame* frame1_2 = new QFrame(frame1);//대출/반납 선택, 확인 버튼
    QFormLayout* formLayout = new QFormLayout(frame1_1);
    QLineEdit* bookEdit = new QLineEdit(frame1_1);
    QLineEdit* userEdit = new QLineEdit(frame1_1);


    formLayout->addRow("도서명",bookEdit);
    formLayout->addRow("회원명",userEdit);
    frame1_1->setLayout(formLayout);
    hBoxLayout->addWidget(frame1_1);
    hBoxLayout->addWidget(frame1_2);
    frame1->setLayout(hBoxLayout);
    vBoxLayout->addWidget(frame1);
    vBoxLayout->addWidget(frame2);
    setLayout(layout);
}
