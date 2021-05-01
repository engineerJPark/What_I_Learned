#include <iostream>

using namespace std;

int main(void)
{
	char s[15];

	scanf("%[^\n]\n", s); // 줄 바꿈 문자를 제거한 문자만 입력받음
	cout << s;
	string str;

	getline(cin, str);  // getline(cin, str, '\n')과 같음 
	cout << str;
}