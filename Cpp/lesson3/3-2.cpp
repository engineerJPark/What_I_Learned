//기본 생성자
//생성자를 정의하지 않은 경우 사용된다.
//parameter를 가지지 않으며 Atrribute가 0,NULL로 초기화된다.

#include <iostream>
#include <string>

using namespace std;

class Character{
private:
	string name;
	int ragepoint;
	int hp;
	int damage;
public:	//no initialization
	void show(){
		cout << name << "[" << ragepoint << "]" << hp << " " << damage << '\n' ;
	}
};

int main(void){
	Character character = Character();	//기본생성자를 사용하면 0,NULL값이 들어간다.
	Character character2;	//기본생성자를 사용하지 않으면,trash value가 들어간다.
	character.show();
	character2.show();
	system("pause");
	return 0;
}