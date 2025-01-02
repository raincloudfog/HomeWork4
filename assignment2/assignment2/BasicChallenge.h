#pragma once
#include "Basic.h"
#include <iostream>
#include <optional>
#include <utility>

using namespace std;

//책을 빌려오는 객체
// Book객체를 그대로 가져오려함
// 이유 : 곂치는 책제목 혹은 곂치는 작가가 있을 수도 있어서 map을 사용안하려함

//함수종류 
//책 초기화
// 빌려오기
// 반납하기



class BorrowManager
{
private:
	//문제 1. 책에 생성자가 있어야됨. // 그러면 포인터배열을 만드는게 어떤가
	//이러면 주소값을 받기때문에 생성자가 필요없을것이다.
	int count = 3;
	int currentsize = 0;
	Book** Stockbooks = new Book*[count];

public :

	


	BorrowManager()
	{
		//책전부 nullptr로 
		for (size_t i = 0; i < count; i++)
		{
			Stockbooks[i] = nullptr;
		}
	}

	//책을 찾기 - 타이틀
	void FindTitle(string title) {

		
	}

	//책을받아옴
	// 빈공간이 있을경우 추가
	// 주소값을 받아서 저장해줌.
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
		cout << "더 이상 공간이 없습니다." << endl;
	}


	
	////책을 반환함
	//// 주소값에 있는 값을 전달해줘야함.
	////책 이름으로반환 필요시 저자로 반환하기 추가 가능
	//void returnBook(string title)
	//{
	//	for (size_t i = 0; i < count; i++)
	//	{
	//		//타이틀 확인 후 있으면 전달
	//		if (title == Stockbooks[i]->title)
	//		{
	//			return *Stockbooks[i];
	//		}
	//	}

	//	//비상 아무것도 없으면 뭘반환하지
	//	// 편안하게 
	//	return std::nullopt;
	//}
	
	//optional 빨간줄 해결 못함.
	//기본버전을높이는방법으로해결 오래걸림젠장
	//optional 반환값을 안 줄수 있는방식!! 어떤 조건에만 값을 주고 싶을때 사용!!
	std::optional<Book> returnbook(string title)
	{
		for (size_t i = 0; i < currentsize; i++)
		{
			//타이틀 확인 후 있으면 전달
			if (title == Stockbooks[i]->title)
			{
				cout << title <<" 책 반환 \n";
				Book* tempBook = Stockbooks[i];
				currentsize--;
				return *tempBook;
			}
		}

		//비상 아무것도 없으면 뭘반환하지
		// 편안하게 ㅇ
		cout << "없는 책입니다.";
		return std::nullopt;
	}


	void displayStock() 
	{
		for (size_t i = 0; i < currentsize; i++)
		{
			//흐으으음 이게 값이 전달이 안된거같다?
			//클래스는옮겼는데 //혹시 복사 생성자를 사용해야하는건가!?
			cout << "빌린 책  - " + Stockbooks[i]->title + " by " + Stockbooks[i]->author + "\n";
			
			
		}
	}
	

};
