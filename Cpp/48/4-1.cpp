// 생성자 : 부모 먼저 자식 나중
// 소멸자 : 자식 먼저 부모 나중

// 오버라이딩 : 부모클래스의 함수 무시, 자식클래스에서 같은 이름의 함수 재정의. 오버라이딩을 적용한 함수의 원형은 기존 함수와 동일한 매개변수를 전달 받는다.

#include<iostream>
#include<string>

using namespace std;

class Person{
private:
	string name;
public:
	Person(string name): name(name){} // 멤버 이니셜라이저. 생성자보다 먼저 작동한다.
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
	Student(int studentID, string name) : Person(name){	// member initializer로 Person 객체 생성을 한다. 이렇게 Person 생성자를 불러온다
		this->studentID = studentID;
	}
	void show(){
		cout << "학생번호 : " << studentID << endl;
		cout << "학생이름 : " << getName() << endl;
		
	}
};

int main(){
	Student student = Student(1, "Alex");
	student.show();
	return 0;
}