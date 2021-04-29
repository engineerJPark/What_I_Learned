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
	
	//Person operator + (const Person &other){return Person(name + "&" + other.name);}	//operator는 함수이다. 그리고 안에 있는 건 새로운 클래스를 정의하는 것이라고 생각하면 될 것이다. 즉 그 클래스를 반환하는 것.
	
	Person operator + (const Person &other){Person(name + "&" + other.name);}	//alex라 뜬다. 왜??? 1. 여기는 클래스를 반환하는 것이 아니다. 2. 근데 왜 bob이 아닌 alex라고 나오나?
	void showName(){ cout << "이름 : " << name << endl;}							//3. 이러려면 return은 안됐지만, 두번째 Person이 작동해서 name이 alex로 바뀐 것밖에 안된다.
																				//4. 원래 쓰레기값이 나와야하는 것 아닌가?????
};


int main(void){
	Person person1;
	person1.showName();
	Person person2("Alex");
	person2.showName();
	Person result = person1 + person2; //연산자 오버로딩에서 사용한 연산자를 이용해서 정의한다. nb1 + nb2 = nb1.operator+(nb2)
	result.showName();
	// Person result2 = person1.operator+(person2); //연산자 오버로딩에서 사용한 연산자를 이용해서 정의한다. nb1 + nb2 = nb1.operator+(nb2)
	// result2.showName();
	return 0;
}