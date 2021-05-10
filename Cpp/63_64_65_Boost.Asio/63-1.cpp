#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(){
	boost::asio::io_service io; // io_service 객체
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5)); // 잠깐 멈출때
	t.wait(); // 5초간 정지
	
	std::cout << "Hello, World" << std::endl;
	
	return 0;
}