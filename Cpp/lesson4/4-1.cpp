#include<iostream>
#include<string>

//생성자 : 부모 먼저 자식 나중
//소멸자 : 자식 먼저 부모 나중

//오버라이딩 : 부모클래스의 함수 무시, 자식클래스에서 같은 이름의 함수 재정의. 오버라이딩을 적용한 함수의 원형은 기존 함수와 동일한 매개변수를 전달 받는다.

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
	Student(int studentID, string name) : Person(name){	//부모 class의 생성자에 입력받은 name을 집어넣는다.
		this->studentID = studentID;					//그런데 그럼 어느 name이 어느 name이고 어디서 시작해서 어디서 끝나는 거지?
	}
	void show(){
		cout << "학생번호 : " << studentID << endl;
		cout << "학생이름 : " << getName() << endl;
		
	}
};

int main(){
	Student student = Student(1, "박준성");
	student.show();
	return 0;
}