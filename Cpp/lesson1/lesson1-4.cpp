#include <iostream>
#include <string>

using namespace std;	//이제 더이상 범위 연산자 std:: 이런거 안해도 됨.

int main(void){
    string input;  //using namespace std; 를 안하면 표준라이브러리 사용할 때 std::string 해줘야함.
    cin >> input;  //문자열 입력. >>는 공백문자(스페이스, 엔터, 탭)을 기준으로 입력을 받는다. 따라서 >> 다음에는 한칸 띄어주어야한다.
    for(int i=0;i<input.size();i++){
			cout << input[i] << endl;    //문자열 출력
	}
    system("pause");
    return 0;
}

//string은 클래스로 정의되어 있어서 메서드가 존재한다.

// #include <iostream>
// #include <string>

// using namespace std;	//이제 더이상 범위 연산자 std:: 이런거 안해도 됨.

// int main(void){
//     string input;  //using namespace std; 를 안하면 표준라이브러리 사용할 때 std::string 해줘야함.
//     getline(cin, input);  //문자열 입력. >>는 공백문자(스페이스, 엔터, 탭)을 기준으로 입력을 받는다. 따라서 >> 다음에는 한칸 띄어주어야한다.
//     for(int i=0;i<input.size();i++){
// 			cout << input[i] << endl;    //문자열 출력
// 	}
//     system("pause");
//     return 0;
// }

// //string은 클래스로 정의되어 있어서 메서드가 존재한다.