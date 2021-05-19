#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	int* arr = new int[10];
	arr[7] = 100;
	
	shared_ptr<int> p1(arr);
	cout << p1.use_count() << '\n';

	shared_ptr<int> p2(p1);
	cout << p1.use_count() << '\n';
	cout << p2.use_count() << '\n';

	shared_ptr<int> p3 = p2;
	cout << p1.use_count() << '\n';
	cout << p2.use_count() << '\n';
	cout << p3.use_count() << '\n';
	cout << "arr[7] : " << arr[7] << endl;
		
	p1.reset();
	cout << p1.use_count() << '\n';
	cout << p2.use_count() << '\n';
	cout << p3.use_count() << '\n';
	cout << "arr[7] : " << arr[7] << endl;
	
	p2.reset();
	cout << p1.use_count() << '\n';
	cout << p2.use_count() << '\n';
	cout << p3.use_count() << '\n';
	cout << "arr[7] : " << arr[7] << endl;
	
	p3.reset();
	cout << p1.use_count() << '\n';
	cout << p2.use_count() << '\n';
	cout << p3.use_count() << '\n';
	cout << "arr[7] : " << arr[7] << endl;
}