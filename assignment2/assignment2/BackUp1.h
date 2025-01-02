#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std ���



//- ������ ������ ������ ���� ���α׷� �ڵ带 �м�
//-������ �ڵ带 Ȱ���ؼ� ������ �˻� ����� �߰��Ѵ�(������ �ݺ��� ���� ���� ����)
//- �뿩 ���(���� ���)�� �߰��Ѵ�.(�ƿ� ���ο� ����� �����ϴ� ����)



//å Ŭ����
//Ÿ��Ʋ ,���� ����
//������ 

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};



// å ���� �ϴ� ������
// å ��� (����)
// å �߰� �� ��� �޼���
//void �Լ� const ���? 



class BookManager {


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

    void searchByTitle(string title) {

        string answer = "";

        //������ ������ ���� �� ������ ���� ������ ã�ƺ���
        for (size_t i = 0; i < books.size(); i++)
        {
            //å�� �Ȱ��� Ÿ��Ʋ�ϰ��
            if (books[i].title == title) {
                answer += "- " + books[i].title + " by " + books[i].author + "\n";
            }
        }

        if (answer == "")
        {
            answer = "�ش� å�� �����ϴ�.\n";
        }

        cout << answer;

        //Book it = find(books.begin(), books.end(), title);

    }



    void searchByAuthor(string author)
    {
        string answer = "";

        //������ ������ ���� �� ������ ���� ������ ã�ƺ���
        for (size_t i = 0; i < books.size(); i++)
        {
            //å�� �Ȱ��� �����ϰ��
            if (books[i].author == author) {
                answer += "- " + books[i].title + " by " + books[i].author + "\n";
            }
        }

        if (answer == "")
        {
            answer = "�ش� å�� �����ϴ�.\n";
        }

        cout << answer;
    }

};



//�ѹ� ���� �������� ��� �߰��ϱ�
//���� ��ɿ��� 


class BookManagerDecorator : public BookManager {
protected:
    BookManager* book;

public:

};
