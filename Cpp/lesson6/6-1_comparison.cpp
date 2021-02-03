#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	int studentId;
	string name;
public:
	Student(int studentId, string name): studentId(studentId), name(name) { }
	Student operator +(const Student &other) {
		return Student(studentId, name + " & " + other.name);
	}
	void showName() { cout << "이름: " << name << '\n'; }
};

int main(void) {
	Student student(1, "나동빈");
	Student result = student + student;
	result.showName();
}