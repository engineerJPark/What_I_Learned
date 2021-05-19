/*
멤버함수 추가 공부
*/

#include <iostream>
#include <string>
using namespace std;
 
class Friend1 {
private :
    string name;
 
	//이렇게 자신의 private 멤버에 참조가 가능한 함수가 있다고 선언해주어야한다.
    friend void set_name(Friend1&, string);
};
 
// 클래스 밖에서 함수 정의
void set_name(Friend1& f, string s) {
    f.name = s;
    cout << f.name << "\n";
}
 
int main(void) {
    Friend1 f1;
 
    set_name(f1, "Alex");
 
    return 0;
}