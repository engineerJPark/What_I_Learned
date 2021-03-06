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