//두근두근 동적할당

#include<iostream>
#define SIZE 100

using namespace std;

int *arr;

int main(){
	arr = new int[SIZE];	//동적할당 방법 new, malloc 대신 쓴다.
	for(int i = 0;i < SIZE; i++){
		arr[i] = i;
	}
	
	for(int i = 0;i < SIZE; i++){
		cout << arr[i] << ' ';
	}
	delete arr;	//할당 해제
	system("pause");
	return 0;
}