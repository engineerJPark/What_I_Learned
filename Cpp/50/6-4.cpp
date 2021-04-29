

#include <iostream>
#include <string>


using namespace std;


class Person {
private:
	const int id;
	string name;
public:
	static int count;
	//객체가 하나 생길떄마다,(생성자가 사용될때마다.) count가 1 올라간다.
	Person(int id, string name) : id(id), name(name) { count++; }
	void setID(int id){ this->id = id; //오류 발생 }
};

//여기에 count를 선언하면 모든 객체에서 참조가 가능해진다.
int Person::count = 0;

int main(void) {
	Person p1(1, "나동빈");
	Person p2(2, "홍길동");
	Person p3(3, "이순신");
	cout << "사람의 수: " << Person::count << '\n';
	system("pause");
}