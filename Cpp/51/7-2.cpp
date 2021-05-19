/*
이런 문제를 정적 바인딩이라고 한다
추상 클래스가 동적바인딩으로 바꿔줘서 이 문제를 해결한다.
virtual 키워드를 사용한다. 이말이야.
*/

/*가상함수 사용 예시*/

/*자식클래스에서 재정의 되는 메서드는 virtual 처리를 해서 포인터 사용시 문제가 없게 하는 것이 좋다.*/

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show(){cout << "A클래스" << endl;}
};

//B는 A를 상속
class B : public A
{
	virtual void show(){ cout << "B클래스" << endl;}
};


int main()
{
	A* p;ㄴㄴ
	A a;
	B b;
	
	p = &a;
	p -> show();
	p = &b;
	p -> show();
	a.show();
}