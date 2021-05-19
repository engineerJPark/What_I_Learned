#include <iostream>
#include <winsock.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
using namespace std;

/*send, receive 제외하면 거의 winsock과 같은 형태이다.*/

/*전역함수로 선언되었기에 이렇게 함수형태로 초기화가 가능하다.*/
void init()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SSL_load_error_strings();
	SSL_library_init();
	OpenSSL_add_all_algorithms();
}
void close()
{
	ERR_free_strings();
	EVP_cleanup();
	WSACleanup();
}