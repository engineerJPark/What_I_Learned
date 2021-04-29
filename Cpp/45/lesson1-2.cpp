#include <iostream>

namespace A {
	void function(){
		std::cout << "A Namespace" << std::endl;
	}
}

namespace B {
	void function(){
		std::cout << "B Namespace" << std::endl;
	}
}

int main(){
	A::function();	//::는 범위지정 연산자. A namespace 안의 function함수를 사용하겠다는 뜻이다.
	B::function();
	system("pause");
	return 0;
}