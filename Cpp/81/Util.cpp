#include "Util.h"

vector<string> Util::getTokens(string input, char delimeter){
	vector<string> tokens;
	istringstream f(input); // 객체화
	string s;
	// f라는 입력을 받고 그것을 s에 delimeter를 기준으로 나눠 담는 것으로 처리한다.
	while(getline(f, s, delimeter)){ 
		tokens.push_back(s); 
	}
	return tokens;
}