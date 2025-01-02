#include <iostream>
#include "Basic.h"
#include "BasicChallenge.h"








int main() {

    BookManager manager;
    BorrowManager user;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 제목으로 책 찾기" << endl; // 책 제목으로 책 찾기
        cout << "4. 저자이름으로 책 찾기" << endl; // 저자이름으로 책 찾기
        cout << "5. 책 제목으로 책 대여" << endl; // 책 제목으로 책 대여
        cout << "6. 책 저자으로 책 대여" << endl; // 책 저자으로 책 대여
        cout << "7. 책 제목으로 책 반환" << endl; // 책 제목으로 책 반환
        cout << "8. 대여한 책 목록" << endl; // 대여한 책 목록
        cout << "9. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            // 3번 선택 : 검색
            // 타이틀에 맞는 책 찾기
            string title;
            cout << "찾고 싶은 책 제목 : ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);


        }
        else if (choice == 4)
        {
            // 4번 선택 : 검색
            // 저자에 맞는 책 찾기
            string author;
            cout << "찾고 싶은 책의 저자 : ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);


        }
        else if (choice == 5)
        {
            // 5번 선택 : 책 대여 -책 제목
            // 제목에 맞는 책 찾기
            string title;
            cout << "찾고 싶은 책의 제목 : ";
            cin.ignore();
            getline(cin, title);
            if (manager.searchByTitle(title)) {
                //헐 ? &*는 양심
                //optional은 포인터처럼 값을전달하려면 *를 사용해야한다 ... 주의!!
                //user.borrowBook(&*manager.findBookByTitle(title));

                // & 연산자에 l-value(메모리에 저장된 값을 가리키는 변수나 객체)가 필요하다는 의미
                // 즉, & 연산자가 사용된 위치에서 주소를 가져올 수 없는 값이 있다는 뜻

                if (auto book = manager.findBookByTitle(title)) {
                    Book& bookRef = *book; // Book 객체의 참조를 얻음
                    cout << bookRef.title << bookRef.author << "빌려올 책 이름과 저서 ... \n";
                    //user.borrowBook(&bookRef); // 참조의 주소를 전달
                    user.borrowBook(new Book(bookRef)); // 참조의 주소를 전달
                   // delete& bookRef;
                }
            }
            else {
                cout << "해당 책은 없습니다.";
            }


        }
        else if (choice == 6)
        {
            // 5번 선택 : 책 대여 -책 저자
            // 저자에 맞는 책 찾기
            string author;
            cout << "찾고 싶은 책의 저자 : ";
            cin.ignore();
            getline(cin, author);


            //값을 받고 거기서 또 주소로 바꾼다 &*를 이렇게 풀어서 사용해야 오류없는 듯함.
            if (manager.searchByAuthor(author)) {                
                if (auto book = manager.findBookByAuthor(author)) {
                    Book& bookRef = *book; // Book 객체의 참조를 얻음
                    cout << bookRef.title << bookRef.author << "빌려올 책 이름과 저서 ... \n";
                    user.borrowBook(new Book(bookRef)); // 참조의 주소를 전달
                    //delete& bookRef;
                }
            }
            else {
                cout << "해당 책은 없습니다.";
            }

        }
        else if (choice == 7)
        {
            string title;
            cout << "반납할 책의 제목 : ";
            cin.ignore();
            getline(cin, title);
            if (auto book = user.returnbook(title))
            {
                Book& bookRef = *book;
                manager.addBook(bookRef.title, bookRef.author);
                //delete &bookRef;
            }
            
        }
        else if (choice == 8) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            user.displayStock();
        }
        else if (choice == 9) {
            // 5번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
	
}