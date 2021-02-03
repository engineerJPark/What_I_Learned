#include <iostream>

using namespace std;

class NUMBOX
{
private:
	int num1, num2;
public:
	NUMBOX(int num1, int num2) : num1(num1), num2(num2) { }
	
	void ShowNumber(){
		cout << "num1: " << num1 << ", num2: " << num2 << endl;
	}
	
	NUMBOX operator+(NUMBOX &ref){
//		return NUMBOX(num1+ref.num1, num2+ref.num2);
		NUMBOX(num1+ref.num1, num2+ref.num2);		//이경우에는 쓰레기값을 받는다. 즉 반환받는 값이 정상적인 값이 없다.
	}
};


int main()
{
	NUMBOX nb1(10, 20);
	NUMBOX nb2(5, 2);
	NUMBOX result = nb1 + nb2;
	nb1.ShowNumber();
	nb2.ShowNumber();
	result.ShowNumber();
}