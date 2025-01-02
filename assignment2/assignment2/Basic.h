#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>

using namespace std; // namespace std 사용



//- 제공된 간단한 도서관 관리 프로그램 코드를 분석
//-제공된 코드를 활용해서 간단한 검색 기능을 추가한다(간단한 반복문 정도 구현 수준)
//- 대여 기능(도전 기능)을 추가한다.(아예 새로운 기능을 구현하는 수준)



// 책을 빌려주는 객체


//책 클레스
//타이틀 ,저서 변수
//생성자 

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}

    ////복사생성자 연습
     Book(const Book& other) : title(other.title), author(other.author) {};

};

// 책 관리 하는 도서관
// 책 목록 (벡터)
// 책 추가 및 출력 메서드
//void 함수 const 상수? 
 


class BookManager {

private:


    
 protected:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    
    bool searchByTitle(string title) {

        string answer = "";

        //더좋은 정렬이 있을 수 있으니 과제 끝나고 찾아볼것
        for (size_t i = 0; i < books.size(); i++)
        {
            //책과 똑같은 타이틀일경우
            if (books[i].title == title) {
                cout << "- " + books[i].title + " by " + books[i].author + "\n";
                return true;
            }
        }

        cout << "해당 책이 없습니다.\n";
        return false;

    }
    
    //불리언 값으로 변경
    bool searchByAuthor(string author)
    {
        string answer = "";

        //더좋은 정렬이 있을 수 있으니 과제 끝나고 찾아볼것
        for (size_t i = 0; i < books.size(); i++)
        {
            //책과 똑같은 저자일경우
            if (books[i].author == author) {
                cout << "- " + books[i].title + " by " + books[i].author + "\n";
                return true;

            }
        }


        cout << "해당 책이 없습니다.\n";
        return false;


    }

    //책 빌려주기

    std::optional<Book> findBookByTitle(string title)
    {
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            //책과 똑같은 타이틀일경우
            if (books[i].title == title) {

                cout << "해당 책 빌려줌 - " + books[i].title + " by " + books[i].author + "\n";

                //과거 코드
                //Book* tempbook = &books[i]; //포인터로 주면 값이 안뜸 나중에 그려서라도 확인하는게 좋을듯함
                //books.erase(books.begin() + i);//귀찮긴하지만 인덱스가아니라 begin에서 i를 더해주는걸로 제거 가능
                ////여기서 분명 1번 책을빌렷는데 2번 책을 준다..?
                //cout << "해당 책 빌려줌 - " + books[i].title + " by " + books[i].author + "\n";
                //이유 해당 인덱스번호의 주소를 
                

                Book tempbook = books[i];
                books.erase(books.begin() + i); // 책 제거

                return tempbook;

            }
        }

        cout << "해당 책이 없습니다.\n";




        return nullopt;
    }

    std::optional<Book> findBookByAuthor(string author)
    {
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            //책과 똑같은 타이틀일경우
            if (books[i].author == author) {
                cout << "해당 책 빌려줌 - " + books[i].title + " by " + books[i].author + "\n";

                Book tempbook = books[i];                
                books.erase(books.begin() + i);//귀찮긴하지만 인덱스가아니라 begin에서 i를 더해주는걸로 제거 가능

                return tempbook;

            }
        }

        cout << "해당 책이 없습니다.\n";




        return nullopt;

    }


    

};






//한번 구조 패턴으로 기능 추가하기
//기존 기능에서 


//class BookManagerDecorator  : public BookManager{
//protected:
//    BookManager* book ;
//
//public:
//
//};