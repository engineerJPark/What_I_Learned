//각 instance가 method를 공유하므로 method 내에서 각 instance를 구분할 필요가 생긴다.
//this pointer는 상수이다. 값을 변경할 수 없다.

#include <iostream>
#include <string>

using namespace std;

class Student{
	private:
		string name = "홀롤롤";
		int engscore = 0;
		int mathscore = 0;
		int getSum(){
			return (engscore + mathscore);
		}
	
	public:
		Student(string name, int engscore, int mathscore){
			this -> name = name;
			this -> engscore = engscore;
			this -> mathscore = mathscore;
		}
		//this -> 를 하게 되면, 다른 겹치는 매개변수명이 아닌, 새로 생성한 instance의 멤버변수에 값을 지칭하는 것이다.
		//변수끼리 이름이 겹칠 때 사용
		//this -> 안하면 홀롤롤, 0점으로 뜬다.
		void Show(){
			cout << name << ": 점수 총합 : " << getSum() << endl;
		}
	//이 경우 매개변수에 name이 없기 때문에, 객체의 멤버변수 name으로 인식하게 된다.
};

int main(){
	// Student a = Student("Park", 100, 90); //아래와 같이 작동한다.
	Student a("Park", 100, 90);
	a.Show();
		
	return 0;
}