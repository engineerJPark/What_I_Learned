#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	unique_ptr<int> p1(new int(10));
	unique_ptr<int> p2;
	
	cout << "smart pointer 1: " << p1.get() << '\n';
	cout << "smart pointer 2: " << p2.get() << '\n';
	cout << "smart pointer 2: " << *p1 << '\n';
	cout << "smart pointer 2: " << *p2 << '\n'; // NULL POITNER ERROR
}