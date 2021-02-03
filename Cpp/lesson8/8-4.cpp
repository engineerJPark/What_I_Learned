//class default template

#include <iostream>
#include <string>

using namespace std;

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
	//Data data1(1);	//오류 발생. why?
	Data<string> data2("Alex");
	cout << data1.getData() << ":" << data2.getData() << "\n";
}