//class template
//클래스 템플릿은 객체를 생성할때 타입을 정해준다.


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
	Data<int> data1(1);			//class template은 <>안에 아무것도 안쓰면 컴파일 에러가 난다.
	Data<string> data2("Alex");	
	cout << data1.getData() << ":" << data2.getData() << "\n";
}