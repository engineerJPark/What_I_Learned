# 스마트 포인터

C++의 스마트 포인터는 메모리 누수(Memory Leak)을 방어하기 위한 수단이고, 포인터처럼 동작하는 클래스 템플릿이다.

C#이나 파이썬은 가비지 콜렉터와 같은 기술들로 사용하지 않는 메모리를 자동으로 수거해간다...만 C++은 그딴 거 없고 스마트 포인터로 스스로 해결해야만한다.
다만 C에서는 반드시 free()를 써서 처리해야하는 번거로움이 있었지만, C++에서는 스마트 포인터로 더 간편하게 해결할 수 있는 장점이 있다.

동적할당은 new, 해제는 delete. 동적할당은 힙영역의 메모리에서 수행한다.
new로 할당 후 스마트 포인터에 넣어서 사용한다.
스마트 포인터는 다쓰고 소멸자에서 delete 키워드를 사용한다. 자동으로 해제하는 기능을 수행하게 된다.

----

- unique_ptr: 하나의 스마트 포인터가 특정한 객체를 처리할 수 있도록 한다.
- shared_ptr: 특정한 객체를 참조하는 스마트 포인터가 총 몇 개인지를 참조한다.
- weak_ptr: 하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을 제공한다. 부가적인 역할을 수행하게 된다.

----

### unique_ptr

unique_ptr을 사용하면, 단 하나의 스마트 포인터만이 해당 메모리를 사용할 수 있고, 다른 스마트 포인터와의 공유는 불가능하다.

unique_ptr은 소유권이전, 메모리 할당 해제 등의 기능이 있다.

```
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

// output:
smart pointer 1: 0x556cfb476e70
smart pointer 2: 0
move to p2
smart pointer 1: 0
smart pointer 2: 0x556cfb476e70
free memory
smart pointer 1: 0
smart pointer 2: 0
```

Nullpointer에 접근하면 에러가 난다.

```
#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	unique_ptr<int> p1(new int(10));
	unique_ptr<int> p2;
	
	cout << "smart pointer 1: " << p1.get() << '\n';
	cout << "smart pointer 2: " << p2.get() << '\n';
	cout << "smart pointer 2: " << *p1 << '\n'; // 담고 있는 객체에 접근한다.
	cout << "smart pointer 2: " << *p2 << '\n'; // NULL POITNER ERROR
}

// output:
smart pointer 1: 0x55e15c46ae70
smart pointer 2: 0
smart pointer 2: 10
세그멘테이션 오류 (core dumped)
```
딱 네번째 출력에서 세그멘테이션 오류가 발생한다.

reset()메서드를 통해서 메모리 할당을 해제할 수 있다.
아래 에제는 쓰레기 값이 나오는 것이 정상이다만 개발환경 때문인지 1 오프셋 부분만 다르게 나왔다.

```
#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	int* arr = new int[10];
	unique_ptr<int> p1(arr);
	
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	
	// 대입된 값 잘 출력된다.
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	
	// 메모리 할당 해제
	p1.reset();
	cout << '\n';
	
	// 메모리 해제 이후엔 쓰레기값 출력된다.
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
}

// output:
0 1 2 3 4 5 6 7 8 9
0 0 2 3 4 5 6 7 8 9
```

----
### shared_ptr

C++에서 shared_ptr은 하나의 객체를 참조하는 스마트 포인터의 개수가 몇 개인지를 저장한다.
하나의 객체를 여러개의 포인터에서 참조할 때 유용한 클래스다.

특정한 객체를 새로운 스마트 포인터가 참조할 때마다 참조 횟수(Reference Count)가 1씩 증가한다.
각 스마트 포인터의 수명이 다할 때마다 1씩 감소한다.
참조 횟수가 0이 되면 delete 키워드를 이용해 메모리에서 데이터를 자동으로 할당 해제한다.

use_count()함수를 통해서 몇개의 share_ptr이 참조 중인지 확인할 수 있다.
```
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

// output:
1
2
2
3
3
3
arr[7] : 100
0
2
2
0
0
1
arr[7] : 100
0
0
0
arr[7] : 100
```
개발환경 문제인제 할당해제 시점에서도 해당 메모리 값이 유지된다.
Visual Studio 환경에서는 쓰레기값 나오던데..

----
### weak_ptr

C++에서 weak_ptr은 하나 이상의 shared_ptr 객체가 참조하고 있는 객체에 접근할 수 있다.
하지만 해당 객체의 소유자의 수에는 포함되지 않는다.

일반적으로 서로가 상대방을 가리키는 두 개의 shared_ptr이 있다면, 참조 횟수는 0이 될 수 없기 때문에 메모리에서 해제될 수 없다.
weak_ptr은 이러한 순환 참조(Circular Reference) 현상을 제거하기 위한 목적으로 사용한다.

아래 예제에서 볼 수 있듯이 use_count()함수를 사용해서 weak_ptr로 선언한 스마트 포인터는 참조 개수에 포함되지 않는다.
```
#include <iostream>
#include <memory>

using namespace std;

int main(void) {
	int* arr = new int(1);
	shared_ptr<int> sp1(arr);
	weak_ptr<int> wp = sp1; // wp는 참조 횟수 계산에서 제외합니다.
	
	cout << sp1.use_count() << '\n'; // 1로 동일
	cout << wp.use_count() << '\n';
		
	if (true) {
	shared_ptr<int> sp2 = wp.lock(); // lock()함수는 shared_ptr 포인터 반환
	cout << sp1.use_count() << '\n';
	cout << wp.use_count() << '\n';
	}
	
	// 스코프(Scope)를 벗어나므로 sp2가 해제
	cout << sp1.use_count() << '\n';
	cout << wp.use_count() << '\n';
}

// output : 
1
1
2
2
1
1
```



----

### 참고

스마트포인터에 관한

https://en.cppreference.com/w/cpp/memory/unique_ptr

https://modoocode.com/229

https://modoocode.com/252



`new int()` `new int[]`의 차이

https://stackoverflow.com/questions/13797926/what-does-new-int100-do

https://stackoverflow.com/questions/2468367/is-new-int10-valid-c



스코프와 관련된 자료

https://dojang.io/mod/page/view.php?id=784

https://dojang.io/mod/page/view.php?id=683

http://tcpschool.com/c/c_function_variableScope


----

### 제공받은 소스코드 오류에 관한 질의응답

https://stackoverflow.com/questions/67599539/c-unique-ptr-why-this-sample-codes-get-compile-error-error-codes-are-so-lon

결론적으론 `cout << "smart pointer 1: " << p1.get() << '\n';` 이렇게 작성해야한다.