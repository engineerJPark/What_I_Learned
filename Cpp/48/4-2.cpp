#include<iostream>
#include<string>

using namespace std;

class Person{
private:
	string name;
public:
	Person(string name): name(name){}
	string getName(){
		return name;
	}
	void showName(){
		cout << "이름 : " << getName() << endl;
	}
};

class Student : Person {
private:
	int studentID;
	//name 변수는 부모class name에서 가져온다.
public:
	Student(int studentID, string name) : Person(name){	
		this->studentID = studentID;					
	}
	void show(){
		cout << "학생번호 : " << studentID << endl;
		cout << "학생이름 : " << getName() << endl;
		
	}
	void showName(){ // 오버라이딩에 의해 Person 클래스의 showName은 무시된다.
		cout << "학생이름 : " << getName() << endl;
	}
};

int main(){
	Student student = Student(1, "Alex");
	student.show();
	student.showName();
	return 0;
}