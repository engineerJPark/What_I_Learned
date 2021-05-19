#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

// return server computer's date and time
string make_daytime_string(){
	time_t now = time(0);
	return ctime(&now);
}

// 보통 80번 포트는 HTTP, 13번 포트는 DAYETIME 프로토콜로 자주 사용된다.
int main(){
	try{
		// IO service 객체 생성
		boost::asio::io_service io_service;
		// TCP protocol 13 por로 연결받는 passive socket 생성
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));
		
		while(1){
			// 소켓 객체 생성 및 연결 대기
			tcp::socket socket(io_service);
			acceptor.accept(socket);
			// 연결 시 클라이언드에게 보낼 메시지 생성
			string message = make_daytime_string();
			// 메시지 전송. 오류처리는 error_code로 한다.
			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
	}
	catch(exception & e){
		cerr << e.what()<< '\n';
	}
	return 0;
}