### 탬플릿 Template

탬플릿 template란, 함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀.

function template을 이용해서 이렇게 다양한 자료형에 대응할 수 있다. 다만 배열이나 구조체는 에러가 잘 발생한다. [구조체 연산 `.` `->`을 연산자오버로딩을 통해 다시 정의해야한다고](https://hombody.tistory.com/307)는 하는데 뭐 명확히 알려주진 않는다...


이렇게 함수에 대해서 탬플릿을 사용하면 **함수 탬플릿**이라고 부른다.

```cpp
template <typename T>
T sum(T a, T b){
    return a + b;
}
```

여러개의 자료형에 대응하려 한다면 이렇게,

```cpp
template <class T1, class T2>
void printAll(T1 a, T2 b){
    cout << "T1 : " << a << endl;
    cout << "T2 : " << b << endl;
    cout << "T1 + T2 : " << a + b << endl;
}
```

함수 탬플릿을 사용함으로써 각 자료형에 대해 함수가 동적 바인딩 될 것이고, 뭐 `<int>, <double>`이 들어가는 함수를 각각 사용하면 각 자료형에 맞게 함수가 재정의되서 따로 바인딩 될 것이다.

그리고 탬플릿 함수도 오버로딩 된다.

----

사용할 function template에 앞서 <>에 자료형을 적어줌으로써 어떤 자료형이 들어갈 지 명시해줄 수 있다.
```
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


int main()
{
	string a = "Alex";
	string b = "Bob";
	change(a,b);
	cout << a << ":" << b << endl;
	// 호출시 무슨 자료형을 쓸것인지 <>안에 명시해줄수 있다. 가능하면 해주는 것이 보기에 편하다.
	change<string>(a,b); 
	cout << a << ":" << b << endl;
}

// output:
Bob:Alex
Alex:Bob
```

----
### 명시적 특수화 : Explicit Specialization

특정한 타입의 매개변수는 별도처리하고 싶을 때, 명시적 특수화를 통해 오버로딩한다.
T를 없애고 넣고싶은 데이터 타입을 넣어서 재정의하는 것이다.

함수의 경우 다른 특수화는 불가능. 명시적 특수화만 가능하다.
[호출 순위](https://hombody.tistory.com/307) : 일반 함수 > 명시적 특수화 탬플릿 함수 > 탬플릿 함수


```cpp
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

/*명시적 특수화 부분*/
// template<>
// void change(int& a, int& b)
// 이렇게 적어도 좋다.
template <>
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
	change(a,b); // 이렇게 특정한 데이터 타입에 해당하는 함수를 요구하는 것을 '암시적 구체화'라고한다
	cout << a << ":" << b << endl;
}

// output:
Bob:Alex
```

명시적 구체화의 경우 아래와 같이 따로 함수를 정의하면 된다.
`template void change<int>(int& a, int& b)`
`<int>`에 맞는 함수를 미리 구체화해놓는다는 것이다.(탬플릿 함수로 정의하면 미리 구체화는 안해놓는다.)

----
### class template

클래스 템플릿은 객체를 생성할때 타입을 정해준다.

```cpp
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Data
{
private:
	T data;
public:
	Data(T data) : data(data) {}
	void setData(T data){this -> data = data;}
	T getData(){ return data; }
};

int main()
{
	Data<int> data1(1);
	Data<string> data2("Alex");	
	cout << data1.getData() << ":" << data2.getData() << "\n";
	
	// Data<> data3(1);
	// class template은 <>안에 아무것도 안쓰면 컴파일 에러가 난다.
	// error: wrong number of template arguments (0, should be 1)
}
```


다만 탬플릿의 자료형을 default하게 정해준 경우에는 <>를 써서 객체를 생성할 수 있다.

```cpp
//class default template

#include <iostream>
#include <string>

using namespace std;

// default 자료형을 지정해준다.
template <typename T = int>
class Data
{
private:
	T data;
public:
	Data(T data) : data(data) {}
	void setData(T data){this -> data = data;}
	T getData(){ return data; }
};

int main()
{
	Data<> data1(1);
	Data<string> data2("Alex");
	cout << data1.getData() << ":" << data2.getData() << "\n";
	
	// Data data2(1);	//error: missing template arguments before ‘data2’
}

// output:
1:Alex
```

----

### 참고

[template(템플릿)](https://blockdmask.tistory.com/43)

[명시적 특수화(어려움 주의)](https://wikidocs.net/488)

[암시적 구체화](https://hombody.tistory.com/307)


진짜 파도파도 끝이 없는 C++의 세계...