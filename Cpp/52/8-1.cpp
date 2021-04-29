/*function template*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>	//꼭 여기 써야하는 건가? 아니면 함수인건가?
void change(T& a, T& b)
{
	T temp;
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
	change<string>(a,b);		//template 함수는 호출시 무슨 자료형을 쓸것인지 <>안에 명시해줄수 있다.
	cout << a << ":" << b << endl;
}