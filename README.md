# 도서관리 시스템
아래와 같은 기능을 구현하였습니다.  

> 도서 추가/삭제/검색
>
> 사용자 추가/삭제/검색
>
> 도서 내용 파일 입출력
>
> 사용자 내용 파일 입출력
>
> 도서 대출 및 반납
>
> 연체자 정보 출력
> 

## 파일 구성 
### code 폴더  
qt를 이용한 gui적용을 고려하지 않고 만들었던 도서관리 시스템으로 cmd 창을 통해 프로그램이 동작합니다.  

### library 폴더  
기존에 작성한 code 파일에 qt creator를 활용하여 ui를 추가한 최종 파일입니다.  
기존 cmd에서 동작하던 프로그램에서 연체자 출력 기능을 제외한 나머지 기능을 구현하였습니다.

### 테스트 파일  
book.txt 와 user.txt 파일을 통해 파일 입출력을 테스트해볼 수 있습니다.

## 설계  
1. 메뉴바
   메뉴바는 File - 파일 입출력 관련 / Book - 책 관련 / User - 사용자 관련으로 구성되어 있습니다.
   Book과 User 메뉴바의 경우, 행동을 시키면 관련 행동을 수행하는 탭으로 넘어가며 실질적인 기능 수행은 탭 내에서 이루어집니다.
2. Widget 구성
   총 3개의 탭으로 구성되어 있으며 각각 book, user, 대출 및 반납을 다룹니다.
   #### book
   내용을 입력하고 버튼을 누르면 기능이 수행이 됩니다. 각각 책 추가, 책 삭제, 책 검색의 기능을 가집니다.  
   기능 수행 후 변경 사항은 모두 좌측의 표(tablewidget)을 통해 확인할 수 있습니다.  
   검색 및 삭제는 책 이름만 입력해도 가능합니다.  
   또한, 이 경우 **책의 이름이 동일한 경우를 대비하여 한번 더 선택하도록 messagebox 를 통해 값을 입력 받습니다.**  
   이 때, 모든 책의 ISBN은 동일하지 않다고 가정합니다. 
   #### user
   user 탭은 book 탭과 동일하게 작동합니다.
   검색 및 삭제 또한 이름만 입력해도 작동합니다.  
   마찬가지로, **동명이인 상황에 대한 예외처리**가 되어 있으며 모든 사용자의 id는 동일하지 않다고 가정합니다.  
   #### rent/return
   대출 및 반납을 다루는 위젯입니다.  
   **동명이인 및 동일한 책 제목에 대한 내용은 처리되지 않습니다.**  
   좌측의 하단에는 책에 대한 표가, 우측 하단에는 사용자에 대한 표가 보입니다.
   본 탭에서 발생한 변경 사항 뿐만 아니라, book 이나 user 탭에서 생긴 변경사항 또한 확인할 수 있도록 구성되어 있습니다.


<!----
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
----->
