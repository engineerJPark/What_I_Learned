#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;


int main(){
	try{
		// IO service 객체 생성
		boost::asio::io_service io_service;
		// 서버 주소 파악하는 resolver 객체. 도메인 이름을 tcp 종단점으로 바꾼다.
		tcp::resolver resolver(io_service);
		/*여기에 이제 공인 IP를 넣자*/
		tcp::resolver::query query("0.tcp.ngrok.io", "16273");
		// DNS 통해서 IP, port 번호 가져온다.
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		// 소켓 객체 초기화, 서버에 연결
		tcp::socket socket(io_service);
		boost::asio::connect(socket, endpoint_iterator);
		
		while(1){
			// 버퍼 및 오류 처리 변수
			boost::array<char, 128> buf;
			boost::system::error_code error;
			
			// 서버로부터 데이터 수령
			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			
			if(error == boost::asio::error::eof){
				break;
			}
			elseif(error) throw boost::system::system_error(error);
			
			// 버퍼에 담긴 데이터를 화면에 출력
			cout.write(buf.data(), len);
		}

	return 0;
}