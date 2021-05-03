/*
TCP echo networking program in Windows

client가 보내는 패킷을 그대로 server가 반사해주는 프로그램

구성속성 - 링커 - 입력 - 라이브러리 - ws2_32.lib 입력
*/

// 서버측 프로그램


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
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN serverAddress, clientAddress;
	
	int serverPort = 9876;
	char received[256];
	
	//Winsock initialize
	if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) ShowErrorMessage("WSAStartup()");
	// MAKEWORD는 2.2 버전이라고 입력하기 위해 존재한다.
	
	// TCP socket 생성. PF_INET = AF_INET이다.
	serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	
	if(serverSocket == INVALID_SOCKET) ShowErrorMessage("socket()");
	
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // 4바이트 정수를 네트워크 바이트로
	serverAddress.sin_port = htons(serverPort); // 2바이트 정수를 네트워크 바이트로
	
	if(bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) ShowErrorMessage("bind()");
	cout << "[현재상태] bind()\n";
	
	// 동시 연결 요청 클라이언트가 5개까지
	if(listen(serverSocket, 5) == SOCKET_ERROR) ShowErrorMessage("listen()");
	cout << "[현재상태] listen()\n";
	
	// 특이하게도 accept의 마지막 parameter가 포인터이다.
	int sizeClientAddress = sizeof(clientAddress);
	clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &sizeClientAddress));
	cout << "[현재상태] accept()\n";
	if(clientSocket == INVALID_SOCKET) ShowErrorMessage("accept()");
	
	while(1){ // 클라이언트의 메시지를 받아서 그대로 다시 전달한다.
		int length = recv(clinetSocket, received, sizeof(received), 0);
		received[length] = NULL; // 마지막 문자를 NULL로 바꾸어서 에외를 처리할 것이다.
		cout << "[클라이언트 메시지] : " << received << '\n';
		cout << "[메시지 전송] : " << received << '\n';
		if(strcmp(received, "[exit]") == 0){
			// 클라이언트가 보내는 메시지는 마지막에 엔터가 포함되기에 제거한다.
			// 클라이언트도 종료할 수 있게 [exit]을 전송한다.
			send(clientSocket, received, sizeof(received) - 1, 0);
			cout << "[서버종료]\n";
			break;
		}
		send(clientSocket, received, sizeof(received)-1, 0);
	}
	
	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();
	
	return 0;
}