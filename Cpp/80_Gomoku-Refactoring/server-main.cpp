#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <Winsock.h>
#include <iostream>
#include <vector>
#include <sstream>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

class Client {
private:
	int clientID;
	int roomID;
	SOCKET clientSocket;
public:
	Client(int clientID, SOCKET clientSocket) {
		this->clientID = clientID;
		this->roomID = -1;
		this->clientSocket = clientSocket;
	}
	int getClientID() {
		return clientID;
	}
	int getRoomID() {
		return roomID;
	}
	void setRoomID(int roomID) {
		this->roomID = roomID;
	}
	SOCKET getClientSocket() {
		return clientSocket;
	}
};

SOCKET serverSocket;
vector<Client> connections;
WSAData wsaData;
SOCKADDR_IN serverAddress;

int nextID;

vector<string> getTokens(string input, char delimiter) {
	vector<string> tokens;
	istringstream f(input);
	string s;
	while (getline(f, s, delimiter)) {
		tokens.push_back(s);
	}
	return tokens;
}

int clientCountInRoom(int roomID) {
	int count = 0;
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i].getRoomID() == roomID) {
			count++;
		}
	}
	return count;
}

void playClient(int roomID) {
	char *sent = new char[256];
	bool black = true;
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i].getRoomID() == roomID) {
			ZeroMemory(sent, 256);
			if (black) {
				sprintf(sent, "%s", "[Play]Black");
				black = false;
			}
			else {
				sprintf(sent, "%s", "[Play]White");
			}
			send(connections[i].getClientSocket(), sent, 256, 0);
		}
	}
}

void exitClient(int roomID) {
	char *sent = new char[256];
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i].getRoomID() == roomID) {
			ZeroMemory(sent, 256);
			sprintf(sent, "%s", "[Exit]");
			send(connections[i].getClientSocket(), sent, 256, 0);
		}
	}
}

void putClient(int roomID, int x, int y) {
	char *sent = new char[256];
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i].getRoomID() == roomID) {
			ZeroMemory(sent, 256);
			string data = "[Put]" + to_string(x) + "," + to_string(y);
			sprintf(sent, "%s", data.c_str());
			send(connections[i].getClientSocket(), sent, 256, 0);
		}
	}
}

// 클라이언트를 한 명씩 처리하는 스레드 함수
void ServerThread(Client *client) {
	char *sent = new char[256];
	char *received = new char[256];
	int size = 0;
	while (true) {
		ZeroMemory(received, 256);
		if ((size = recv(client->getClientSocket(), received, 256, NULL)) > 0) {
			string receivedString = string(received);
			vector<string> tokens = getTokens(receivedString, ']');
			if (receivedString.find("[Enter]") != -1) {
				/* 메시지를 보낸 클라이언트를 찾기 */
				for (int i = 0; i < connections.size(); i++) {
					string roomID = tokens[1];
					int roomInt = atoi(roomID.c_str());
					if (connections[i].getClientSocket() == client->getClientSocket()) {
						int clientCount = clientCountInRoom(roomInt);
						/* 2명 이상이 동일한 방에 들어가 있는 경우 가득 찼다고 전송 */
						if (clientCount >= 2) {
							ZeroMemory(sent, 256);
							sprintf(sent, "%s", "[Full]");
							send(connections[i].getClientSocket(), sent, 256, 0);
							break;
						}
						cout << "클라이언트 [" << client->getClientID() << "]: " << roomID << "번 방으로 접속" << endl;
						/* 해당 사용자의 방 접속 정보 갱신 */
						Client *newClient = new Client(*client);
						newClient->setRoomID(roomInt);
						connections[i] = *newClient;
						/* 방에 성공적으로 접속했다고 메시지 전송 */
						ZeroMemory(sent, 256);
						sprintf(sent, "%s", "[Enter]");
						send(connections[i].getClientSocket(), sent, 256, 0);
						/* 상대방이 이미 방에 들어가 있는 경우 게임 시작 */
						if (clientCount == 1) {
							playClient(roomInt);
						}
					}
				}
			}
			else if (receivedString.find("[Put]") != -1) {
				/* 메시지를 보낸 클라이언트 정보 받기 */
				string data = tokens[1];
				vector<string> dataTokens = getTokens(data, ',');
				int roomID = atoi(dataTokens[0].c_str());
				int x = atoi(dataTokens[1].c_str());
				int y = atoi(dataTokens[2].c_str());
				/* 사용자가 놓은 돌의 위치를 전송 */
				putClient(roomID, x, y);
			}
			else if (receivedString.find("[Play]") != -1) {
				/* 메시지를 보낸 클라이언트를 찾기 */
				string roomID = tokens[1];
				int roomInt = atoi(roomID.c_str());
				/* 사용자가 놓은 돌의 위치를 전송 */
				playClient(roomInt);
			}
		}
		else {
			ZeroMemory(sent, 256);
			sprintf(sent, "클라이언트 [%i]의 연결이 끊어졌습니다.", client->getClientID());
			cout << sent << endl;
			/* 게임에서 나간 플레이어를 찾기 */
			for (int i = 0; i < connections.size(); i++) {
				if (connections[i].getClientID() == client->getClientID()) {
					/* 다른 사용자와 게임 중이던 사람이 나간 경우 */
					if (connections[i].getRoomID() != -1 &&
						clientCountInRoom(connections[i].getRoomID()) == 2) {
						/* 남아있는 사람에게 메시지 전송 */
						exitClient(connections[i].getRoomID());
					}
					connections.erase(connections.begin() + i);
					break;
				}
			}
			delete client;
			break;
		}
	}
}

int main() {
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	serverSocket = socket(AF_INET, SOCK_STREAM, NULL);

	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddress.sin_port = htons(9876);
	serverAddress.sin_family = AF_INET;

	cout << "[ C++ 오목 게임 서버 가동 ]" << endl;
	bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));
	listen(serverSocket, 32);

	int addressLength = sizeof(serverAddress);
	while (true) {
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, NULL);
		// 사용자의 접속이 계속해서 유지되기 때문에 accept만하는 부분을 만들어줘야한다.
		if (clientSocket = accept(serverSocket, (SOCKADDR*)&serverAddress, &addressLength)) {
			Client *client = new Client(nextID, clientSocket);
			cout << "[ 새로운 사용자 접속 ]" << endl;
			// 한명한명에 대한 응답처리는 스레드를 통해서 한다.
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ServerThread, (LPVOID)client, NULL, NULL);
			connections.push_back(*client);
			nextID++;
		}
		Sleep(100);
	}
}