#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std 사용



//- 제공된 간단한 도서관 관리 프로그램 코드를 분석
//-제공된 코드를 활용해서 간단한 검색 기능을 추가한다(간단한 반복문 정도 구현 수준)
//- 대여 기능(도전 기능)을 추가한다.(아예 새로운 기능을 구현하는 수준)



//책 클레스
//타이틀 ,저서 변수
//생성자 

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};



// 책 관리 하는 도서관
// 책 목록 (벡터)
// 책 추가 및 출력 메서드
//void 함수 const 상수? 



class BookManager {


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

    void searchByTitle(string title) {

        string answer = "";

        //더좋은 정렬이 있을 수 있으니 과제 끝나고 찾아볼것
        for (size_t i = 0; i < books.size(); i++)
        {
            //책과 똑같은 타이틀일경우
            if (books[i].title == title) {
                answer += "- " + books[i].title + " by " + books[i].author + "\n";
            }
        }

        if (answer == "")
        {
            answer = "해당 책이 없습니다.\n";
        }

        cout << answer;

        //Book it = find(books.begin(), books.end(), title);

    }



    void searchByAuthor(string author)
    {
        string answer = "";

        //더좋은 정렬이 있을 수 있으니 과제 끝나고 찾아볼것
        for (size_t i = 0; i < books.size(); i++)
        {
            //책과 똑같은 저자일경우
            if (books[i].author == author) {
                answer += "- " + books[i].title + " by " + books[i].author + "\n";
            }
        }

        if (answer == "")
        {
            answer = "해당 책이 없습니다.\n";
        }

        cout << answer;
    }

};



//한번 구조 패턴으로 기능 추가하기
//기존 기능에서 


class BookManagerDecorator : public BookManager {
protected:
    BookManager* book;

public:

};
