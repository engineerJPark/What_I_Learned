//C++에서는 기본적으로 멤버 변수에 접근하기 위해서 public 멤버 함수를 이용해야 합니다.
//다만 특정한 객체의 멤버함수가 아닌 경우에도 private 멤버에 접근해야 할 때가 있습니다.
//이 때 프렌드(friend) 키워드를 이용하면 특정한 객체의 모든 멤버에 접근할 수 있습니다.

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	int studentId;
	string name;
public:
	Student(int studentId, string name): studentId(studentId), name(name) { }
	
	// 자신의 클래스에 대한 매개변수를 두개 써야하는 경우에는
	// 반드시 friend 명령어로 캡슐화를 시켜주자.
	// friend 키워드를 이용해 다른 객체의 private 멤버인 name에 바로 접근 가능.
	// 원래는 안되서 stuent.operator+ 형식으로 들어가는건데
	friend Student operator +(const Student &student, const Student &other) {
		return Student(student.studentId, student.name + " & " + other.name);
	}
	
	// 아래와 같이 대체할 수 있다.
	// Student operator +(const Student &other) {
	// 	return Student(studentId, name + " & " + other.name);
	// }

	void showName() { cout << "Name: " << name << '\n'; }
};

int main(void) {
	Student student(1, "Alex");
	Student result = student + student;
	result.showName();
}