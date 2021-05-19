#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	int* arr = new int[10];
	unique_ptr<int> p1(arr);
	
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	
	// 대입된 값 잘 출력된다.
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	
	// 메모리 할당 해제
	p1.reset();
	cout << '\n';
	
	// 메모리 해제 이후엔 쓰레기값 출력된다.
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
}