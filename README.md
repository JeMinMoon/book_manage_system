# 도서관리 시스템
    도서의 정보(제목, 저자, ISBN 등)를 추가, 검색 기능
    도서 상태 관리(대여 여부)
    대여시 가능 여부 확인 (대여자의 기존책 반납 여부)

## 설계  

### 클래스 구성
```
class Book {
	state  
	name  
	writer  
	isbn  
	Person* borrower  
	borrowDate  
	returnDate  
public:  
	getsth() 			// get info about private 
	stateToggle()  
};

class Person {
	name  
	id  
	borrowCount			// how many books borrowed .. max = 2
	Book* borrowBooks[2]		// list of books that user borrowed
};

class Manage {
	Book* []  
	canBorrow()  
	add()  
	delete()  
	search()
};
```	

