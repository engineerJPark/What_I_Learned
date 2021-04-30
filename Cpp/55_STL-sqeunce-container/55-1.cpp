/*
가장 많이 사용되는 것은 vector와 deque

deque 은 양 끝에서 데이터를 넣거나 뺄 수 있다.

push_front
pop_front
push_back
pop_back
insert
*/

// #include<iostream>
// #include<deque>


// using namespace std;

// int main(){
// 	deque<int> d;
	
// 	d.push_front(3); d.push_back(7); d.pop_front(); d.push_front(4);
// 	// 4 7
// 	for(int i = 0; i < d.size(); i++){ cout << d[i] << ' ';}
// 	cout << '\n';
	
// 	deque<int>::iterator iter; // 각 원소에 접근하게 해주는 iterator
// 	iter = d.begin(); // 시작 부분에 위치한다.
// 	d.insert(iter + 1, 3, 5); // 5를 3번 입력해서 4 5 5 5 7
// 	iter = d.begin();
// 	d.insert(iter + 1, 1, 9); // 9를 1번 입력해서 4 9 5 5 5 7
	
// 	for(int i = 0; i < d.size(); i++){ cout << d[i] << ' '; }
// 	cout << '\n';
// 	d.clear(); // 덱의 모든 원소 제거
// 	cout << d.empty() << '\n'; // 비어있으면 empty함수가 1을 반환
	
// 	return 0;
// }

/*
vector는 뒤쪽에서만 push pop이 가능하다. 배열처럼 사용 가능

push_back, pop_back, insert를 지원
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v;
	v.push_back(3); v.push_back(5); v.push_back(8); // 3 5 8
	
	vector<int>::iterator iter;
	iter = v.begin();
	v.insert(iter + 1, 3, 7); // 3 7 7 7 5 8
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << '\n';
	
	v.clear();
	cout << v.empty();
	
	return 0;
}