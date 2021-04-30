/*
key와 value로 데이터를 쌍으로 저장하는 컨테이너이다.
set, map이 핵심이다.
python의 set과 dictionary와 비슷
 
set은 data를 key로 사용한다. 정렬된 위치에 데이터를 삽입하여 검색 속도가 빠르다.
키의 중복 ㄴㄴ


*/

// #include<iostream>
// #include<set>

// using namespace std;

// int main(){
// 	int array[5] = {2, 4, 6, 8, 10};
// 	set<int> s(array, array + 5); // array를 set으로 바꿀 때에는 s(배열시작주소, 배열끝주소)
// 	// set<int> s{2,4,6,8,10}; 도 가능
// 	set<int>::iterator iter = s.begin();
	
// 	for(; iter != s.end(); iter++){ //2 4 6 8 10
// 		cout << *iter << ' '; // iterator는 pointer의 속성을 가지는 객체이다.
// 		// https://eehoeskrap.tistory.com/263
// 	}
// 	cout << '\n';
	
// 	s.insert(1);
// 	s.insert(3);
// 	s.insert(5);
// 	iter = s.begin();
// 	for(; iter != s.end(); iter++){ //1 2 3 4 5 6 8 10
// 		cout << *iter << ' ';
// 	}
// 	cout << '\n';
	
// 	return 0;
// }

/*
map은 저장하는 key를 value와 한 쌍으로 사용한다.
정렬된 위치에 데이터를 삽입하여 검색 속도가 빠르다.
key는 중복되지 않는다.

hash 자료구조를 대신하는데 많이 쓰인다.
*/

#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
	map<string, int> m; // string이 key, int가 value
	m["홍길동"] = 1; m["alex"] = 2; m["bob"] = 3; //m[key] = value;
	map<string, int>::iterator iter = m.begin();
	
	for(; iter !=m.end(); iter++){
		cout << iter->first << ':' << iter->second << '\n';
	}
	m["hmm"] = 4;
	cout << m["nobody"] << '\n'; // nobody도 접근을 시도했기에, 0의 value로 새로 생긴다.
	
	iter = m.begin();
	for(; iter != m.end(); iter++){
		cout << iter->first << ':' << iter->second << '\n';
	}
	
	return 0;
}