# 도서관리 시스템
    도서의 정보(제목, 저자, ISBN 등)를 추가, 검색 기능
    도서 상태 관리(대여 여부)
    대여시 가능 여부 확인 (대여자의 기존책 반납 여부)

## 설계  
class Book  
	 state  
	 name  
	 writer  
	 isbn  
	 Person* borrower  
	 borrowDate  
	 returnDate  
  
pulbic:  
	 getter()  
	 stateToggle()  
	

class Person  
	 name  
	 id  
	 borrowCount	// 최대 2권  
	 Book* borrowBooks[2]  

class Manage  
	 Book* []  
	 canBorrow()  
	 add()  
	 delete()  
	 search()  
	

