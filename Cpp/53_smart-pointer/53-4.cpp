#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	unique_ptr<int> p1(new int(10)); // new로 10이 든 메모리를 할당받아서 스마트 포인터에 넣는다.
	unique_ptr<int> p2;
	
	cout << "smart pointer 1: " << p1.get() << '\n';
	cout << "smart pointer 2: " << p2.get() << '\n';
	cout << "move to p2\n";
	
	p2 = move(p1);
	
	cout << "smart pointer 1: " << p1.get() << '\n';
	cout << "smart pointer 2: " << p2.get() << '\n';
	cout << "free memory\n";
	
	p2.reset();
	
	cout << "smart pointer 1: " << p1.get() << '\n';
	cout << "smart pointer 2: " << p2.get() << '\n';
}