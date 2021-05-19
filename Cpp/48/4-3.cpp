//다중상속 : 여러개의 부모 클래스로부터 상속을 받을 수 있다. 보통은 잘 안쓴다.

#include<iostream>
#include<string>

using namespace std;

class Temp{
public:
	void Tempshow(){
		cout << "임시 부모 클래스" << endl;
	}
};

class Person{
private:
	string name;
public:
	Person(string name): name(name){}	//member initialization으로, 생성자의 몸체보다 먼저 실행된다.
	string getName(){
		return name;
	}
	void showName(){
		cout << "이름 : " << getName() << endl;
	}
};

class Student : Person, public Temp {	//왜 public이 들어가야하는 것이지? https://thrillfighter.tistory.com/531 참고
private:
	int studentID;
public:
	Student(int studentID, string name) : Person(name){	//member initialization으로 생성자를 불러올 수도 있다.
		this->studentID = studentID;																
	}
	// 그냥 Student생성자가 받은 name 파라미터를 그대로 Person 생성자의 파라미터로 넣는다.
	
	// Student(int studentID, string name){	//이거는 name 속성이 private이라서 안됨.
	// 	this->name = name;
	// 	this->studentID = studentID;
	// }
	// Student(int studentID, string name){	// 자식의 생성자가 작동하기 전에 부모의 생성자가 작동해야만한다. 그런데 이 코드는 자식의 생성자 바디까지 들어간 후 부모 생성자가 작동하길 바란다. 실제로는 부모 생성자는 자식 생성자 선언 전에 아무런 인자를 받지 못하고 작동하려고하고, 그 결과 그냥 작동 정지.
	// 	Person(name);
	// 	this->studentID = studentID;
	// }
	// Student(int studentID, string name){	// 그냥 person 기본생성자에 인자를 안주니깐
	// 	this->studentID = studentID;
	// }
	// Student(int studentID){ // 그냥 person 기본생성자에 인자를 안주니깐
	// 	this->studentID = studentID;
	// }
	
	void show(){
		cout << "학생번호 : " << studentID << endl;
		cout << "학생이름 : " << getName() << endl;
		
	}
	void showName(){
		cout << "상속이 성공된 학생이름 : " << getName() << endl;
	}
};

int main(){
	Student student = Student(1, "James");
	// Student student = Student(1);
	student.showName();
	student.Tempshow();
	return 0;
}


// https://hwan-shell.tistory.com/31