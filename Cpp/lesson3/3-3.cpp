//C++는 복사 생성자(Copy Constructor)는 다른 인스턴스의 참조(Reference)를 인수로 받아서, 그 참조를 이용해 자신의 인스턴스를 초기화할 수 있도록 해줍니다.
//대표적인 복사 방법인 깊은 복사(Deep Copy)를 이용해 만들어진 인스턴스는 기존의 인스턴스와 다른 메모리 공간에 할당되어 독립적입니다.

//얕은 복사는 원래 객체와의 메모리 주소를 공유하게 되어, 동적할당 //얕은 복사는 원래 객체와의 메모리 주소를 공유하게 되어, 동적할당 //얕은 복사는 원래 객체와의 메모리 주소를 공유하게 되어, 동적할당 

//reference(참조) 변수형은 변수에 대해 별칭을 만든다고 생각하면된다.
// int num =1;
// int& ref = num;
// ref는 num과 동일하게 작동한다.

// References vs pointers
// 참조형과 포인터는 흥미로운 관계에 있다. 참조형은 접근할 때 암시적으로 역참조되는 포인터와 같은 역할을 한다. (참조형은 내부적으로 포인터를 사용하여 컴파일러서 구현된다.)

// int value = 5;
// int* const ptr = &value;
// int& ref = value;
// *ptr과 ref는 동일하게 평가된다. 그러므로 다음 두 명령문은 같은 효과를 낸다.

// *ptr = 5;
// ref = 5;
// 참조형은 선언과 동시에 유효한 객체로 초기화해야 하고, 일단 초기화되면 변경할 수 없으므로 포인터보다 사용하는 것이 훨씬 안전하다. (널 포인터를 역참조하면 위험하다.)
// 주어진 문제가 참조형과 포인터 둘 다로 해결할 수 있다면 참조형을 사용하는게 더 좋다.

// 출처: https://boycoding.tistory.com/207 [소년코딩]

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
	Character(string name, int hp, int damage): name(name), ragepoint(0), hp(hp), damage(damage) {} //아래 주석과 같은 의미의 구문이다.
	// Character(string name, int hp, int damage) {
	// 	this->name = name;
	// 	this->ragePoint = 0;
	// 	this->hp = hp;
	// 	this->damage = damage;
	// }
	Character(const Character & other){	//oooothththth
		name = other.name;
		ragepoint = other.ragepoint;
		hp = other.hp;
		damage = other.damage;
	}
	void pointUp() {ragepoint++;}
	void show(){
		cout << name << "[" << ragepoint << "]" << hp << " " << damage << '\n' ;
	}
};

int main(void){
	Character character1 = Character("슬라임", 10, 20);
	character1.pointUp();
	Character character2(character1);
	character2.pointUp();
	character1.show();
	character2.show();
	system("pause");
	return 0;
}