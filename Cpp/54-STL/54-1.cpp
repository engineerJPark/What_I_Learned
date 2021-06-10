/*
C++ STL container adapter
기본적인 자료구조 라이브러리이다.

stack, queue, priority queue

1. stack
push, pop, top(조회), empty, size 로 구성됨
*/

/*
endl은 출력버퍼를 비워주는 과정이 있어서 \n이 느리다는게 학계의 정설이다.
*/

#include <iostream>
#include <stack>

using namespace std;

int main(void){
	stack<int> s; // stack이 template로 구현되어있다. int형 데이터를 담는 stack이라 선언
	s.push(7); s.push(5); s.push(4); s.pop(); s.push(6); s.pop();
	
	while (!s.empty()){ // stack 원소가 하나라도 남아있는 경우
		cout << s.top() << ' ';
		s.pop();
	}
	
	return 0;
}