#include <iostream>
#include <string>

int main(void){
    std::string input;  //using namespace std; 를 안하면 표준라이브러리 사용할 때 std::string 해줘야함.
    std::cin >> input;  //문자열 입력. >>는 공백문자(스페이스, 엔터, 탭)을 기준으로 입력을 받는다. 한줄을 전체로 입력받고 싶으면 getline을 이용해야한다.
    std::cout << input << std::endl;    //문자열 출력
    
    return 0;
}

// namespace는 특정 영역에 이름을 설정해준다. 개발자끼리 공동 개발한 모듈을 병합한다.
// std namespace안에 cout, cin, string 등이 존재하는 것이다.