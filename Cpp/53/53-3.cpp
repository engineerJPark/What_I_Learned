/*
클래스 템플릿 class template
자료형에 따라 다르게 동작하는 클래스.
멤버 함수를 클래스 외부에서 선언할때, 반드시 template 선언을 다시 해야한다.

연결리스트를 타입 구애 없이 사용 가능하게 구현한다...?
*/

#include<iostream>
#include<string>

using namespace std;

// template <typename T>이 핵심이다.
template <typename T>
class Data{
private:
	T data;
public:
	Data(T data) : data(data) {	}
	void setData(T data){ this->data = data; }
	T getData() { return data; }
};

int main(){
	Data<int> data1(1); //<>안에 data를 넣어서 어떤 자료형이 들어가는 지 공지하기
	Data<string> data2("공대창고");
	cout << data1.getData() << ":" << data2.getData() << "\n";
	
	return 0;
}