#include<iostream>
#include<string>

//다중상속 : 여러개의 부모 클래스로부터 상속을 받을 수 있다. 보통은 잘 안쓴다.



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
	//name 변수는 부모class name에서 가져온다.
public:
	Student(int studentID, string name) : Person(name){	//부모 class의 생성자에 입력받은 name을 집어넣는다.
		this->studentID = studentID;					//그런데 그럼 어느 name이 어느 name이고 어디서 시작해서 어디서 끝나는 거지?
														//parameter인 name을 Person의 name으로 대입한다.
	}													//member initialization으로 생성자를 불러올 수도 있다.
														//https://blog.hexabrain.net/173 참고
														//https://mystyle1057.tistory.com/entry/C-%EC%83%9D%EC%84%B1%EC%9E%90-%EC%86%8C%EB%A9%B8%EC%9E%90-%ED%98%B8%EC%B6%9C-%EC%8B%9C%EC%A0%90-This-%ED%8F%AC%EC%9D%B8%ED%84%B0-%EC%83%81%EC%86%8D 참고
	//https://hwan-shell.tistory.com/31 참고
	//https://m.blog.naver.com/PostView.nhn?blogId=dd1587&logNo=221103760389&proxyReferer=https:%2F%2Fwww.google.com%2F 참고
	
	// Student(int studentID, string name){	//이거는 name 속성이 private이라서 안됨.
	// 	this->name = name;
	// 	this->studentID = studentID;
	// }
	// Student(int studentID, string name){	//왜 안되는지 잘 모르겠음 ㅠㅠ
	// 	Person(name);
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
	student.showName();
	student.Tempshow();
	return 0;
}


//의문점 : string 클래스는 무엇을 가지고 있는가
//멤버 이니셜라이제이션