#define _WINSOCK_DEPRECATED_NO_WARNINGS // inet_addr을 사용하기 위해서 정의해야한다.
#include<iostream>
#include<string>
#include<winsock2.h>

using namespace std;

void ShowErrorMessage(string message){
	cout << "[오류발생]" << message << '\n';
	exit(1);
}

int main(){
	WSADATA wsaData;
	SOCKET clientSocket;
	SOCKADDR_IN serverAddress;
	
	int serverPort = 9876; // 서버와 동일한 포트번호 사용해야한다.
	char received[256];
	string sent;
	
	//Winsock initialize
	if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) ShowErrorMessage("WSAStartup()");
	// MAKEWORD는 2.2 버전이라고 입력하기 위해 존재한다.
	
	// TCP socket 생성. PF_INET = AF_INET이다.
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(clientSocket == INVALID_SOCKET) ShowErrorMessage("socket()");
	
	// 127.0.0.1은 자기자신을 지칭하는 약속된 ip주소이다.
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // 4바이트 정수를 네트워크 바이트로
	serverAddress.sin_port = htons(serverPort); // 2바이트 정수를 네트워크 바이트로
	if(connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) ShowErrorMessage("connect()");
	cout << "[현재상태] connect()\n";
	
	while(1){ // 클라이언트의 메시지를 받아서 그대로 다시 전달한다.
		cout << "[메시지 전송] : ";
		getline(cin, sent);
		if(sent == "") continue; // 그냥 엔터만 친경우
		send(clientSocket, sent.c_str(), sent.length(), 0); // string을 C언어에서의 문자열로 바꾸려면 sent.c_str()을 해줘야한다.
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = NULL;
		if(strcmp(received, "[exit]") == 0){
			cout << "[서버 종료]\n";
			break;
		}
		cout << "[서버 메시지] : " << received << '\n';
	}
	
	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();
	
	return 0;
}