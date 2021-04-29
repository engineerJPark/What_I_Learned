//함수 오버로딩


#include<iostream>
#include<string>

using namespace std;

class Person{
private:
	string name;
public:
	Person(){ name = "훠훠훠";}
	Person(string name):name(name){}
	void showName(){ cout << "이름 : " << name << endl;}
};


int main(void){
	Person person1;
	person1.showName();
	Person person2("Alex");
	person2.showName();
	return 0;
}