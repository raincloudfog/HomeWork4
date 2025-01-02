#include <iostream>
#include "Basic.h"
#include "BasicChallenge.h"








int main() {

    BookManager manager;
    BorrowManager user;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �������� å ã��" << endl; // å �������� å ã��
        cout << "4. �����̸����� å ã��" << endl; // �����̸����� å ã��
        cout << "5. å �������� å �뿩" << endl; // å �������� å �뿩
        cout << "6. å �������� å �뿩" << endl; // å �������� å �뿩
        cout << "7. å �������� å ��ȯ" << endl; // å �������� å ��ȯ
        cout << "8. �뿩�� å ���" << endl; // �뿩�� å ���
        cout << "9. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            // 3�� ���� : �˻�
            // Ÿ��Ʋ�� �´� å ã��
            string title;
            cout << "ã�� ���� å ���� : ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);


        }
        else if (choice == 4)
        {
            // 4�� ���� : �˻�
            // ���ڿ� �´� å ã��
            string author;
            cout << "ã�� ���� å�� ���� : ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);


        }
        else if (choice == 5)
        {
            // 5�� ���� : å �뿩 -å ����
            // ���� �´� å ã��
            string title;
            cout << "ã�� ���� å�� ���� : ";
            cin.ignore();
            getline(cin, title);
            if (manager.searchByTitle(title)) {
                //�� ? &*�� ���
                //optional�� ������ó�� ���������Ϸ��� *�� ����ؾ��Ѵ� ... ����!!
                //user.borrowBook(&*manager.findBookByTitle(title));

                // & �����ڿ� l-value(�޸𸮿� ����� ���� ����Ű�� ������ ��ü)�� �ʿ��ϴٴ� �ǹ�
                // ��, & �����ڰ� ���� ��ġ���� �ּҸ� ������ �� ���� ���� �ִٴ� ��

                if (auto book = manager.findBookByTitle(title)) {
                    Book& bookRef = *book; // Book ��ü�� ������ ����
                    cout << bookRef.title << bookRef.author << "������ å �̸��� ���� ... \n";
                    //user.borrowBook(&bookRef); // ������ �ּҸ� ����
                    user.borrowBook(new Book(bookRef)); // ������ �ּҸ� ����
                   // delete& bookRef;
                }
            }
            else {
                cout << "�ش� å�� �����ϴ�.";
            }


        }
        else if (choice == 6)
        {
            // 5�� ���� : å �뿩 -å ����
            // ���ڿ� �´� å ã��
            string author;
            cout << "ã�� ���� å�� ���� : ";
            cin.ignore();
            getline(cin, author);


            //���� �ް� �ű⼭ �� �ּҷ� �ٲ۴� &*�� �̷��� Ǯ� ����ؾ� �������� ����.
            if (manager.searchByAuthor(author)) {                
                if (auto book = manager.findBookByAuthor(author)) {
                    Book& bookRef = *book; // Book ��ü�� ������ ����
                    cout << bookRef.title << bookRef.author << "������ å �̸��� ���� ... \n";
                    user.borrowBook(new Book(bookRef)); // ������ �ּҸ� ����
                    //delete& bookRef;
                }
            }
            else {
                cout << "�ش� å�� �����ϴ�.";
            }

        }
        else if (choice == 7)
        {
            string title;
            cout << "�ݳ��� å�� ���� : ";
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
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            user.displayStock();
        }
        else if (choice == 9) {
            // 5�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
	
}