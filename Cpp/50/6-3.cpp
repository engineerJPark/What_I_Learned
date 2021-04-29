/*정적멤버
정적 멤버(Static Member)란 클래스에는 포함 되어 있는 멤버이지만 모든 객체가 공유하는 멤버입니다. 정적
으로 선언된 멤버는 메모리 상에 오직 하나만 할당되어 관리됩니다.

정적 멤버를 public으로 선언하면 외부의 어떠한 클래스에서 접근이 가능하며, 오직 하나만 관리됩니다. 정적
멤버는 일반적으로 싱글톤 패턴(Singleton Pattern) 등의 다양한 기능을 위해 사용됩니다.
*/


#include <iostream>
#include <string>


using namespace std;


class Person {
private:
	string name;
public:
	static int count;
	//객체가 하나 생길떄마다,(생성자가 사용될때마다.) count가 1 올라간다.
	Person(string name) : name(name) {
		count++;
	}
	

};

//여기에 Person class의 count를 선언하면 Person class의 모든 객체에서 참조가 가능해진다.
int Person::count = 0;

int main(void) {
	Person p1("나동빈");
	Person p2("홍길동");
	Person p3("이순신");
	cout << "사람의 수: " << Person::count << '\n';
	system("pause");
}
