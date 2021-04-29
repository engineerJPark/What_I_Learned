/*
일반화 : generic programming
template를 이용해서 generic programming을 한다.

template는 parameter의 타입에 따라 함수/클래스를 사용하도록 해준다.
별도의 함수/클래스를 만들지 않고 단 하나의 객체로 사용가능하게 해준다. 재사용성 극대화


*/

/*
using 선언문

using std::cout;을 사용하면 컴파일러에 std namespace에서 cout을 사용할 것이라고 알려준다.
따라서 cout을 사용할 때마다 std::cout을 의미한다고 가정할 것이다. 즉 using을 써서 앞으로 std::를 안쓸 수 있다는 것이다.
만약 std::cout과 cout의 다른 사용법 사이에 이름 충돌이 있으면 std::cout이 선호된다.


출처: https://boycoding.tistory.com/174 [소년코딩]
*/

/*
namespace 선언
이름 충돌 문제를 해결하기 위해 네임스페이스 (namespace) 개념이 도입
네임스페이스는 모든 식별자(변수, 함수, 형식 등의 이름)가 고유하도록 보장하는 코드 영역을 정의한다.

C++은 표준 라이브러리의 모든 기능을 std namespace라는 특별한 영역으로 옮겼다.

https://boycoding.tistory.com/171?category=1007833

*/

#include<iostream>
#include<string>

using namespace std;

// template <typename T>이 핵심이다.
// template <class T>라고 선언해도 무방하다.
// 구분해야하는 경우는 https://hashcode.co.kr/questions/554/%ED%85%9C%ED%94%8C%EB%A6%BF%EC%97%90%EC%84%9C-typename%ED%82%A4%EC%9B%8C%EB%93%9C%EC%99%80-class%ED%82%A4%EC%9B%8C%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4
template <typename T>
void change(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	string a = "공대창고";
	string b = "개발자";
	change(a,b);
	cout << a << ":" << b << endl;
	
	return 0;
}