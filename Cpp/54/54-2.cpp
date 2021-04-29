/*
1. queue
push, pop, front, back, empty, size 로 구성됨
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void){
	queue<int> q;
	q.push(7); q.push(5); q.push(4); q.pop(); q.push(6); q.pop();
	
	while (!q.empty()){ // stack 원소가 하나라도 남아있는 경우
		cout << q.top() << ' ';
		q.pop();
	}
	
	return 0;
}