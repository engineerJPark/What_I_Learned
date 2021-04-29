/*명시적 특수화
사용 방법은 아래처럼 template 가 정의되어있을때, 같은 함수에 대해서, 재정의?하고싶은 데이터 타입을 이용해서 아래 주황 글씨처럼 재정의 하면됩니다.
T를 없애고 넣고싶은 데이터 타입을 넣습니다.

출처: https://blockdmask.tistory.com/45 [개발자 지망생]
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
void change(T& a, T& b)
{
	T temp;
	temp =a;
	a = b;
	b = temp;
}

template <>	//이건 뭐고
void change<int>(int& a, int& b)
{
	int temp;
	temp =a;
	a = b;
	b = temp;
}


int main()
{
	string a = "Alex";
	string b = "Bob";
	change(a,b);
	cout << a << ":" << b << endl;
}
