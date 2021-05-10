//클래스의 정보 은닉기능

#include <iostream>
#include <string>

using namespace std;

class Student{
private:
	string name;
	int engscore;
	int mathscore;
	int getSum(){
		return (engscore + mathscore);
	}
	//정보 은닉됨. 외부에서는 호출이 안되고 Student 내부의 private/public 메서드에 의해서만 호출이 가능함.
public:
	Student(string n, int e, int m){
		name = n;
		engscore = e;
		mathscore = m;
	}
	void Show(){
		cout << name << ": 점수 총합 : " << getSum() << endl;
	}
	//여기에서 호출해야 getSum이 정상 호출된다.
};
//클래스는 변수의 선언이기 때문에 반드시 ;를 붙여주어야한다.


int main(){
	Student a = Student("Park", 100, 90);
	a.Show();	//정상출력된다.
	//cout << a.getSum();	//주석을 풀고 실행시 오류가 뜬다. private 부분에 직접 접근했기 때문.

	return 0;
}