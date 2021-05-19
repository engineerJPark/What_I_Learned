# 스마트 포인터

C++의 스마트 포인터는 메모리 누수(Memory Leak)을 방어하기 위한 수단이고, 포인터처럼 동작하는 클래스 템플릿이다.

C#이나 파이썬은 가비지 콜렉터와 같은 기술들로 사용하지 않는 메모리를 자동으로 수거해간다...만 C++은 그딴 거 없고 스마트 포인터로 스스로 해결해야만한다.

동적할당은 new, 해제는 delete. 동적할당은 힙영역의 메모리에서 수행한다.
new로 할당 후 스마트 포인터에 넣어서 사용한다.
스마트 포인터는 다쓰고 소멸자에서 delete 키워드를 사용한다. 자동으로 해제하는 기능을 수행하게 된다.

----

- unique_ptr: 하나의 스마트 포인터가 특정한 객체를 처리할 수 있도록 한다.
- shared_ptr: 특정한 객체를 참조하는 스마트 포인터가 총 몇 개인지를 참조한다.
- weak_ptr: 하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을 제공한다. 부가적인 역할을 수행하게 된다.

----

### unique_ptr

g++ -std=c++11 -Wall -Wextra -pedantic /workspace/What_I_Learned/Cpp/53/53-4.cpp -o /tmp/a.out && /tmp/a.out

----
### shared_ptr

C++에서 shared_ptr은 하나의 객체를 참조하는 스마트 포인터의 개수가 몇 개인지를 저장한다.
하나의 객체를 여러개의 포인터에서 참조할 때 유용한 클래스다.

특정한 객체를 새로운 스마트 포인터가 참조할 때마다 참조 횟수(Reference Count)가 1씩 증가한다.
각 스마트 포인터의 수명이 다할 때마다 1씩 감소한다.
참조 횟수가 0이 되면 delete 키워드를 이용해 메모리에서 데이터를 자동으로 할당 해제한다.

shared_ptr은 자신이 생성된 scope({}를 기준)를 벗어나면 바로 해제된다.

----
### weak_ptr

C++에서 weak_ptr은 하나 이상의 shared_ptr 객체가 참조하고 있는 객체에 접근할 수 있다.
하지만 해당 객체의 소유자의 수에는 포함되지 않는다.

일반적으로 서로가 상대방을 가리키는 두 개의 shared_ptr이 있다면, 참조 횟수는 0이 될 수 없기 때문에 메모리에서 해제될 수 없다.
weak_ptr은 이러한 순환 참조(Circular Reference) 현상을 제거하기 위한 목적으로 사용한다.





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

### 소스코드 오류에 관한 질의응답

https://stackoverflow.com/questions/67599539/c-unique-ptr-why-this-sample-codes-get-compile-error-error-codes-are-so-lon


`cout << "smart pointer 1: " << p1.get() << '\n';`
이렇게 작성해야한다.