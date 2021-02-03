//생성자는 객체 생성과 동시에 attribute를 초기화할 수 있게 하는 기능이다.
//클래스의 이름과 동일한 이름의 method로 존재한다.
//생성자는 반환값이 없다.
//생성자는 여러번 정의 가능하여, 다양한 방법으로 객체 초기화를 시도할 수 있다.

#include <iostream>
#include <string>

using namespace std;

class Character {
	private:
		string name;
		int ragePoint;
		int hp;
		int damage;
	public:
		Character(string name, int hp, int damage) {	//initialization. 생성자는 자료형이 없다.
		this->name = name;								//class의 attribute와 parameter의 이름이 겹치므로 사용한다. this
		this->ragePoint = 0;
		this->hp = hp;
		this->damage = damage;
	}
	void show() {
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
	}
};

int main(){
	Character character = Character("슬라임", 50, 10);
	character.show();

	return 0;
}