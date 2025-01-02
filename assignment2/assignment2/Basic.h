#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>

using namespace std; // namespace std ���



//- ������ ������ ������ ���� ���α׷� �ڵ带 �м�
//-������ �ڵ带 Ȱ���ؼ� ������ �˻� ����� �߰��Ѵ�(������ �ݺ��� ���� ���� ����)
//- �뿩 ���(���� ���)�� �߰��Ѵ�.(�ƿ� ���ο� ����� �����ϴ� ����)



// å�� �����ִ� ��ü


//å Ŭ����
//Ÿ��Ʋ ,���� ����
//������ 

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}

    ////��������� ����
     Book(const Book& other) : title(other.title), author(other.author) {};

};

// å ���� �ϴ� ������
// å ��� (����)
// å �߰� �� ��� �޼���
//void �Լ� const ���? 
 


class BookManager {

private:


    
 protected:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    
    bool searchByTitle(string title) {

        string answer = "";

        //������ ������ ���� �� ������ ���� ������ ã�ƺ���
        for (size_t i = 0; i < books.size(); i++)
        {
            //å�� �Ȱ��� Ÿ��Ʋ�ϰ��
            if (books[i].title == title) {
                cout << "- " + books[i].title + " by " + books[i].author + "\n";
                return true;
            }
        }

        cout << "�ش� å�� �����ϴ�.\n";
        return false;

    }
    
    //�Ҹ��� ������ ����
    bool searchByAuthor(string author)
    {
        string answer = "";

        //������ ������ ���� �� ������ ���� ������ ã�ƺ���
        for (size_t i = 0; i < books.size(); i++)
        {
            //å�� �Ȱ��� �����ϰ��
            if (books[i].author == author) {
                cout << "- " + books[i].title + " by " + books[i].author + "\n";
                return true;

            }
        }


        cout << "�ش� å�� �����ϴ�.\n";
        return false;


    }

    //å �����ֱ�

    std::optional<Book> findBookByTitle(string title)
    {
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            //å�� �Ȱ��� Ÿ��Ʋ�ϰ��
            if (books[i].title == title) {

                cout << "�ش� å ������ - " + books[i].title + " by " + books[i].author + "\n";

                //���� �ڵ�
                //Book* tempbook = &books[i]; //�����ͷ� �ָ� ���� �ȶ� ���߿� �׷����� Ȯ���ϴ°� ��������
                //books.erase(books.begin() + i);//������������ �ε������ƴ϶� begin���� i�� �����ִ°ɷ� ���� ����
                ////���⼭ �и� 1�� å�����Ǵµ� 2�� å�� �ش�..?
                //cout << "�ش� å ������ - " + books[i].title + " by " + books[i].author + "\n";
                //���� �ش� �ε�����ȣ�� �ּҸ� 
                

                Book tempbook = books[i];
                books.erase(books.begin() + i); // å ����

                return tempbook;

            }
        }

        cout << "�ش� å�� �����ϴ�.\n";




        return nullopt;
    }

    std::optional<Book> findBookByAuthor(string author)
    {
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            //å�� �Ȱ��� Ÿ��Ʋ�ϰ��
            if (books[i].author == author) {
                cout << "�ش� å ������ - " + books[i].title + " by " + books[i].author + "\n";

                Book tempbook = books[i];                
                books.erase(books.begin() + i);//������������ �ε������ƴ϶� begin���� i�� �����ִ°ɷ� ���� ����

                return tempbook;

            }
        }

        cout << "�ش� å�� �����ϴ�.\n";




        return nullopt;

    }


    

};






//�ѹ� ���� �������� ��� �߰��ϱ�
//���� ��ɿ��� 


//class BookManagerDecorator  : public BookManager{
//protected:
//    BookManager* book ;
//
//public:
//
//};