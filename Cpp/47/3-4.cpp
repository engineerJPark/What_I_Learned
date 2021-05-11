// C++의 소멸자

// C++의 소멸자(Destructor)는 객체의 수명이 끝났을 때 객체를 제거하기 위한 목적으로 사용됩니다. 객체의 수명이
// 끝났을 때 자동으로 컴파일러가 소멸자 함수를 호출합니다.

// C++의 소멸자 또한 생성자처럼 클래스의 이름과 동일하며 물결 기호(~)를 이용해 정의할 수 있습니다.

#include <iostream>
#include <string>

using namespace std;

class Character{
private:
	string name;
	int ragepoint;
	int hp;
	int damage;
public:
	Character(string name, int hp, int damage): name(name), ragepoint(0), hp(hp), damage(damage) {}
	~Character() { cout << "[객체 소멸]\n" ; }
	void pointUp() {ragepoint++;}
	void show(){
		cout << name << "[" << ragepoint << "]" << hp << " " << damage << '\n' ;
	}
};

int main(void){
	Character* character1 = new Character("monster1", 10, 20);	//객체의 주소를 담은 변수 character1. 
	character1->pointUp();
	Character character2(*character1);	//객체의 주소를 역참조해서 넣는다. 
	character2.pointUp();
	character1->show();
	character2.show();
	
	delete character1;
	delete &character2;
	
	system("pause");
	return 0;
}