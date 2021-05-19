//https://blockdmask.tistory.com/43

/*
function template는 처음으로 호출될때 instance를 생성한다.
이후 생성된 instance는 해당 타입에 따라 특수화가 이루어지고 계속 재사용된다.

template는 특정 type에 대해 explicit specialization을 제공한다.
특정 타입에 대해 특수기능을 정의 가능하다.
컴파일러는 특수화된 정의 발견 후에는 해당 정의만을 이용한다.
*/

/*
overloading을 이용해 다음과 같이 만들 수 있다.

int sum(int a, int b){
	return a+b;
}
double sum(double a, double b){
	return a+ b;
}

이걸 아래와 같이 표현 가능
template<typename T>
T sum(T a, T b){
	return a + b;
}
*/

/*
& 연산자는 주소 연산자가 아닌 타입을 식별하기 위해 사용하는 식별자로 사용된 것
int&는 int형 변수에 대한 참조. 이렇게 선언된 참조자는 대상 변수와 같은 메모리 위치를 참조하게 됩니다.

1. 참조자의 타입은 대상이 되는 변수의 타입과 일치해야 합니다.
2. 참조자는 선언과 동시에 초기화되어야 합니다.
3. 참조자는 한 번 초기화되면, 참조하는 대상을 변경할 수 없습니다.
크기가 큰 구조체나 클래스를 다룰 때에만 사용하는 것이 좋습니다.

int x = 10; // 변수의 선언
int& y = x; // 참조자 선언

cout << "x : " << x << ", y : " << y << endl;
y++;        // 참조자를 이용한 증가 연산
cout << "x : " << x << ", y : " << y << endl;
cout << "x의 주소값 : " << &x << ", y의 주소값 : " << &y;
*/

#include<iostream>
#include<string>

using namespace std;

// template <typename T>이 핵심이다.
template <typename T>
void change(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

// 명시적 특수화 : 특수한 자료형에 대해선 다른 처리를 하고 싶을 때 사용한다.
// template <>
// https://blockdmask.tistory.com/45
template <>
void change<int>(int& a, int& b){
	cout << "정수형 데이터의 교체\n";
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 7;
	int b = 5;
	change(a,b);
	cout << a << ":" << b << endl;
	
	return 0;
}