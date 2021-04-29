/*순수가상함수*/

/*왜 안되지?*/

/*추상 클래스(Abstract Class)란 하나 이상의 순수 가상 함수를 포함하는 클래스를 의미합니다. 추상 클래스를 활용
하면 다형성을 효과적으로 프로그램 상에서 구현할 수 있습니다.

따라서 자식 클래스는 추상 클래스를 상속 받은 이후에 반드시 순수 가상 함수를 모두 오버라이딩 해야 비로소 해당
객체를 사용할 수 있습니다.*/

/*
순수 가상 함수

C++의 가상 함수는 기본적으로 반드시 재정의할 필요는 없습니다. 하지만 순수 가상 함수(Pure Virtual Function)
는 자식 클래스에서 반드시 재정의를 해주어야 하는 함수입니다.

그러므로 일반적으로 순수 가상 함수는 부모 클래스에서 함수 동작의 본체를 정의하지 않습니다. 자식 클래스에서 반
드시 이를 정의해야 사용할 수 있습니다.

순수 가상 함수는 ‘=0’ 키워드를 붙여서 선언할 수 있습니다.
*/



#include <iostream>

using namespace std;

class A
{
public:
	//pure-specifier on function-definition : virtual void show()=0 { cout << "A클래스" << endl;}
	virtual void show()=0;	//definition에서는 순수 가상함수 선언 불가.
};

void A::show() { cout << "A클래스" << endl;}

//B는 A를 상속
class B : public A
{
public:
	virtual void show(){ cout << "B클래스" << endl;}	//show()를 재정의하지 않으면 B클래스의 객체를 사용할 수 없다.
};


int main()
{
	A* p;
	B b;

	p = &b;
	p -> show();
}