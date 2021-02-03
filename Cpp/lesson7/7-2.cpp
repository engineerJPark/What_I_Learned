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
	A* p;
	A a;
	B b;
	
	p = &a;
	p -> show();
	p = &b;
	p -> show();
	a.show();
}