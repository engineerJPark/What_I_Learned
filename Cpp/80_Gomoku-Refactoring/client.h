/*
특정한 클래스의 원형에 대해서 정의
*/
// 클라이언트 헤더 파일이 한 번만 선언되게 한다.
#ifndef GOMOKU_CLIENT_H
#define GOMOKU_CLIENT_H
#include <Winsock.h>
class Client{
private:
	int clientID;
	int roomID;
	SOCKET clientSocket;
public:
	Client(int clientID, SOCKET clientSocket);
	int getClientID();
	int getRoomID();
	void setRoomID(int roomID);
	SOCKET getClientSocket();
};
#endif

