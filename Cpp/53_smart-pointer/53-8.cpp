#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	int* arr = new int(1);
	shared_ptr<int> sp1(arr);
	weak_ptr<int> wp = sp1; // wp는 참조 횟수 계산에서 제외합니다.
	
	cout << sp1.use_count() << '\n'; // 1로 동일합니다.
	cout << wp.use_count() << '\n';
		
	if (true) {
	shared_ptr<int> sp2 = wp.lock(); // shared_ptr 포인터 반환
	cout << sp1.use_count() << '\n';
	cout << wp.use_count() << '\n';
	}
	
	// 스코프(Scope)를 벗어나므로 sp2가 해제됩니다.
	cout << sp1.use_count() << '\n';
	cout << wp.use_count() << '\n';
}