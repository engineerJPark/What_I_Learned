/*다형성(Polymorphism)이란 여러 개의 서로 다른 객체가 동일한 기능을 서로 다른 방법으로 처리할 수 있는 기능을
의미합니다. 예를 들어 게임 프로그램에서 칼, 대포, 총 등의 무기들은 공통적으로 ‘공격’이라는 동일한 기능을 수행할
수 있습니다.*/

/*자식 클래스에서 멤버 함수를 재정의하여 사용하는 것은 일반적으로 정상적으로 동작합니다. 하지만 포인터 변수로
객체에 접근할 때는 예상치 못한 결과가 발생할 수 있습니다.

C++ 컴파일러는 포인터 변수가 가리키고 있는 변수의 타입을 기준으로 함수를 호출하지 않고,포인터의 타입을 기준
으로 함수를 호출합니다.  따라서 A라는 객체를 가리키는 포인터 변수는 A 객체의 멤버 함수만을 호출할 수 있습니다.*/


#include <iostream>

using namespace std;

class A
{
public:
	void show(){cout << "A클래스" << endl;}
};

//B는 A를 상속
class B : public A
{
public:
	void show(){ cout << "B클래스" << endl;}
};


int main()
{
	A* p;
	A a;
	B b;
	
	p = &a;
	p -> show();
	p = &b;
	p -> show();	//b를 통해서 show()호출 되는 것이 아니라, A class를 통해서 show()가 호출된다.
	a.show();
	b.show();
}