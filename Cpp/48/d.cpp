#include<iostream>
#include<string>

using namespace std;


class Person{
private:
	string name;
public:
	Person(){ cout << "nothing" << endl;}
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
	Person person2("lee");
	person2.showName();

	return 0;
}


// https://hwan-shell.tistory.com/31