# 일반화 : generic programming

template를 이용해서 generic programming을 할 수 있다.
template는 parameter의 별도의 함수/클래스를 만들지 않고 단 하나의 객체로 사용가능하게 해준다. 이는 곧 재사용성 극대화로 이어진다.

```
#include<iostream>
#include<string>

using namespace std;

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
```

template <class T>라고 선언해도 무방하다.
다만 [구분해야하는 경우](https://hashcode.co.kr/questions/554/%ED%85%9C%ED%94%8C%EB%A6%BF%EC%97%90%EC%84%9C-typename%ED%82%A4%EC%9B%8C%EB%93%9C%EC%99%80-class%ED%82%A4%EC%9B%8C%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4)도 있다.

----

function template는 처음으로 호출될때 instance를 생성한다.
이후 생성된 instance는 해당 타입에 따라 특수화가 이루어지고, 프로그램이 완전히 종료될 때까지 계속 재사용된다.

template는 특정 type에 대해 explicit specialization(명시적 특수화)을 제공한다.
특정 타입에 대해 코드를 다르게 작성해서, 특수기능을 정의해줄 수 있다.
컴파일러는 특수화된 정의 발견 후에는 해당 정의만을 이용한다.

명시적 특수화는 template <>라고 써줌으로써 사용 가능하다.

```
#include<iostream>
#include<string>

using namespace std;

template <typename T>
void change(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

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
```


함수 뿐만이 아니라 클래스에 대해서도 탬플릿을 사용할 수 있다.
마찬가지로 `template<typename T>`형식으로 작성하면 된다.

```
#include<iostream>
#include<string>

using namespace std;

template <typename T>
class Data{
private:
	T data;
public:
	Data(T data) : data(data) {	}
	void setData(T data){ this->data = data; }
	T getData() { return data; }
};

int main(){
	Data<int> data1(1);
	Data<string> data2("공대창고");
	cout << data1.getData() << ":" << data2.getData() << "\n";
	
	return 0;
}
```


----

참고

[명시적 특수화](https://blockdmask.tistory.com/45)

[class와 typename을 구분해서 사용하는 경우](https://hashcode.co.kr/questions/554/%ED%85%9C%ED%94%8C%EB%A6%BF%EC%97%90%EC%84%9C-typename%ED%82%A4%EC%9B%8C%EB%93%9C%EC%99%80-class%ED%82%A4%EC%9B%8C%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4)