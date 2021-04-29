/*프렌드는 멤버 함수 이외에도 프렌드 클래스(Friend Class) 형태로 사용할 수 있습니다. 두 클래스가 서로 밀접한 연
관성이 있으며 상대방의 private 멤버에 접근해야 한다면 클래스 자체를 프렌드로 선언할 수 있습니다.
프렌드 클래스에서는 모든 멤버 함수가 특정 클래스의 프렌드입니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>


using namespace std;


class Time {
friend class Date; // Date 클래스에서 Time 클래스를 이용할 수 있음.
private:
	int hour, min, sec;
public:
	void setCurrentTime() {
		time_t currentTime = time(NULL);
		struct tm *p = localtime(&currentTime);
		hour = p->tm_hour;
		min = p->tm_min;
		sec = p->tm_sec;
	}
};


class Date {
private:
	int year, month, day;
public:
	Date(int year, int month, int day): year(year), month(month), day(day) { }
	void show(const Time &t) {
		cout << "지정된 날짜: " << year << "년 " << month << "월 " << day << "일" << '\n';
		cout << "현재 시간: " << t.hour << ":" << t.min << ":" << t.sec << '\n';
	}
};

/*friend가 안되어있으면 t.hourget()등의 함수로 Time클래스의 public영역에 들어가야하지만,
friend class 로 지정해주면서 직접 private 속성에 들어가게 해준다.*/


int main(void) {
	Time time;
	time.setCurrentTime();
	Date date = Date(2019, 12, 22);
	date.show(time);
	system("pause");
}