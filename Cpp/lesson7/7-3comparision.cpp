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
	//virtual void show(){ cout << "B클래스" << endl;}	//show()를 재정의하지 않으면 25줄에서 b 선언이 안된다. B클래스의 객체를 사용할 수 없다.
};


int main()
{
	A* p;
	B b;

	p = &b;
	p -> show();
}