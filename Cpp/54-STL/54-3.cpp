/*
1. priority queue
push, pop, front, back, empty, size 로 구성됨
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void){
	int n, x;
	cin >> n;
	
	priority_queue<int> pq; // 선언. 최대식 구조를 이용한 우선순위 큐
	
	for(int i = 0; i < n; i++){ cin >> x; pq.push(x); }
	while(!pq.empty()){
		cout << pq.top() << ' ';
		pq.pop();
	}
	
	return 0;
}