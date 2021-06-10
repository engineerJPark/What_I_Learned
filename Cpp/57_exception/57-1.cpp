/*
exception은 예상치 못한 오류를 의미. c++은 발생 가능성이 높은 오류들을 예외처리할 수 있도록 해준다.

try : 예외 발생가능 인지. 
catch : 특정 내용 처리
throw : 발생 오류 전달. 예외 발생시 가장 가까운 catch문으로 이동한다.

예외 발생 예시

int main(){
	int a = 7, b = 0;
	cout << a/b << '\n';
	
	return 0;
}
*/



#include<iostream>

using namespace std;

int main(){
	int a = 7, b = 0;
	
	try{
		if(b == 0){
			// if절 만족시 throw를 통해 바로 catch 구분으로 이동. parameter로 throw 뒤를 준다.
			throw "can't divide by 0"; 
		}
		cout << a / b << '\n';
	}
	catch(const char* str){ // throw를 받는다.
		cout << str << '\n';	
	}
	
	return 0;
}


/*
// class에서의 예외처리

#include<iostream>

using namespace std;

template <typename T>
class Data{
private:
	T data;
public:
	Data(T data) : data(data){ }
	T getData() { return data; }
	Data<T> operator /(const Data<T> &other){ // 연산자 오버로딩
		if(other.data == 0){
			throw 0;
		}
		return Data(data / other.data);
	}
};

int main(void){
	try{
		Data<int> a(7);
		Data<int> b(0);
		Data<int> result = a/b;
		cout << result.getData() << '\n';
	}
	catch(int e){
		if(e == 0){
			cout << "can't divide by 0\n";
		}
	}
}
*/

/*
참고자료
https://tcpschool.com/cpp/cpp_io_streamBuffer
https://newmkka.tistory.com/78
https://modoocode.com/230
*/
