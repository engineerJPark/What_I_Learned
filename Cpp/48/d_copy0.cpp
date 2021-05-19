#include<iostream>
#include<string>

using namespace std;


class Person{
private:
	string name;
public:
	// Person(){ cout << "nothing" << endl;}
	Person(string name): name(name){}	//member initialization으로, 생성자의 몸체보다 먼저 실행된다.
	string getName(){
		return name;
	}
	void showName(){
		cout << "이름 : " << getName() << endl;
	}
};

int main(){
	Person person1;
	person1.showName();
	return 0;
}

// error: no matching function for call to ‘Person::Person()’
// 이렇게 생성자가 파라미터를 못받으면 기본 생성자가 생기는 게 아니라, 그냥 작동을 안한다.




// https://hwan-shell.tistory.com/31