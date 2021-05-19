//연산자 오버로딩는 operator로 하면 된다.

#include<iostream>
#include<string>

using namespace std;

class Person{
private:
	string name;
public:
	Person(){ name = "Bob";}
	Person(string name) : name(name){ }
	
	Person operator + (const Person &other){return Person(name + "&" + other.name);}

	void showName(){ cout << "이름 : " << name << endl;}

};


int main(void){
	Person person1;
	person1.showName();
	Person person2("Alex");
	person2.showName();
	
	// 연산자 오버로딩에서 사용한 연산자를 이용해서 객체를 정의한다.
	// nb1 + nb2 = nb1.operator+(nb2)
	Person result = person1 + person2; 
	result.showName();
	// 이 방법도 가능하다.
	// Person result2 = person1.operator+(person2);
	// result2.showName();
	return 0;
}