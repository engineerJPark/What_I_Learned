/*
입력값을 구분자(delimeter)를 기준으로 나눠주는 getTokens()
*/

#ifndef GOMOKU_UTIL_H
#define GOMOKU_UTIL_H
#include <Winsock.h>
using namespace std;
#include <vector>
#include <sstream>
class Util{
public:
	vector<string> getTokens(string input, char delimeter);
};
#endif
