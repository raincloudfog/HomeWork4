#pragma once
#include "Basic.h"
#include <iostream>
#include <optional>
#include <utility>

using namespace std;

//å�� �������� ��ü
// Book��ü�� �״�� ����������
// ���� : ��ġ�� å���� Ȥ�� ��ġ�� �۰��� ���� ���� �־ map�� �����Ϸ���

//�Լ����� 
//å �ʱ�ȭ
// ��������
// �ݳ��ϱ�



class BorrowManager
{
private:
	//���� 1. å�� �����ڰ� �־�ߵ�. // �׷��� �����͹迭�� ����°� ���
	//�̷��� �ּҰ��� �ޱ⶧���� �����ڰ� �ʿ�������̴�.
	int count = 3;
	int currentsize = 0;
	Book** Stockbooks = new Book*[count];

public :

	


	BorrowManager()
	{
		//å���� nullptr�� 
		for (size_t i = 0; i < count; i++)
		{
			Stockbooks[i] = nullptr;
		}
	}

	//å�� ã�� - Ÿ��Ʋ
	void FindTitle(string title) {

		
	}

	//å���޾ƿ�
	// ������� ������� �߰�
	// �ּҰ��� �޾Ƽ� ��������.
	void borrowBook(Book* book) {


		for (size_t i = 0; i < count; i++)
		{
			if (Stockbooks[i] == nullptr)
			{
				Stockbooks[i] = book;
				currentsize++;
				return;
			}
		}
		cout << "�� �̻� ������ �����ϴ�." << endl;
	}


	
	////å�� ��ȯ��
	//// �ּҰ��� �ִ� ���� �����������.
	////å �̸����ι�ȯ �ʿ�� ���ڷ� ��ȯ�ϱ� �߰� ����
	//void returnBook(string title)
	//{
	//	for (size_t i = 0; i < count; i++)
	//	{
	//		//Ÿ��Ʋ Ȯ�� �� ������ ����
	//		if (title == Stockbooks[i]->title)
	//		{
	//			return *Stockbooks[i];
	//		}
	//	}

	//	//��� �ƹ��͵� ������ ����ȯ����
	//	// ����ϰ� 
	//	return std::nullopt;
	//}
	
	//optional ������ �ذ� ����.
	//�⺻���������̴¹�������ذ� �����ɸ�����
	//optional ��ȯ���� �� �ټ� �ִ¹��!! � ���ǿ��� ���� �ְ� ������ ���!!
	std::optional<Book> returnbook(string title)
	{
		for (size_t i = 0; i < currentsize; i++)
		{
			//Ÿ��Ʋ Ȯ�� �� ������ ����
			if (title == Stockbooks[i]->title)
			{
				cout << title <<" å ��ȯ \n";
				Book* tempBook = Stockbooks[i];
				currentsize--;
				return *tempBook;
			}
		}

		//��� �ƹ��͵� ������ ����ȯ����
		// ����ϰ� ��
		cout << "���� å�Դϴ�.";
		return std::nullopt;
	}


	void displayStock() 
	{
		for (size_t i = 0; i < currentsize; i++)
		{
			//�������� �̰� ���� ������ �ȵȰŰ���?
			//Ŭ�����¿Ű�µ� //Ȥ�� ���� �����ڸ� ����ؾ��ϴ°ǰ�!?
			cout << "���� å  - " + Stockbooks[i]->title + " by " + Stockbooks[i]->author + "\n";
			
			
		}
	}
	

};
