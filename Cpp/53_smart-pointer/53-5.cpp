#include <iostream>
#include <memory>

using namespace std;
int main(void) {
	unique_ptr<int> p1(new int(10));
	cout << *p1 << '\n'; // 관리하고 있는 객체를 반환합니다.
}
// 접근 방법