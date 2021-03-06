## 구성도

클라이언트 : C# 오목 클라이언트 + .Net Socket : C++보다 좀 더 편하게 소켓프로그래밍이 가능하다.
|
|(소켓 통신)
|
서버 : C++ 오목 서버 + Winsock

클라이언트와 서버가 같은 언어를 사용할 필요가 없다.
소켓통신에 사용되는 명령어 양식만 잘 맞춰주면 통신 잘된다.

----

클라이언트1 -- 쓰레드1 ---  |--------|
클라이언트2 -- 쓰레드2 ---  |		 |
클라이언트3 -- 쓰레드3 ---  | 오목서버 |
클라이언트4 -- 쓰레드4 ---  |		 |
클라이언트5 -- 쓰레드5 ---  |--------|

각 쓰레드 별로 무한 반복하게 한다.

----

### 서버프로그램 기능 분석

####클라이언트 객체 정의

접속한 모든 클라이언트를 Vector STL에 담아 관리한다.

- 클라이언트 고유 번호 : 클라이언트가 접속할 때마다 자동으로 1씩 증가
- 접속한 방 번호 : 클라이언트가 접속 요청한 방 번호
- 클라이언트 소켓 객체 : 연결된 소켓 객체

#### 접속 요청 처리 방법

명령어를 이용해서 처리한다.

- 요청 형태: [Enter]{방 번호}
- 예시: [Enter]123
- 해당 방 인원이 1명 이하인 경우 클라이언트에게 [Enter] 명령어를 전송합니다. (접속 성공)
- 해당 방 인원이 이미 2명인 경우 클라이언트에게 [Full] 명령어를 전송합니다. (가득 찬 방)
- 접속 이후에 방 인원이 2명이 되는 경우 [Play] 명령어를 전송합니다. 이 때 검은 돌 사용자에게는 [Play]Black을, 흰 돌 사용자에게는 [Play]White를 전송합니다. (게임 시작)


#### 나가기 요청

- 요청 형태: 소켓 연결 해제
- 특정 클라이언트 소켓 연결이 해제되는 경우 방에 남아있는 사람에게 [Exit] 명령어를 전송합니다. (상대방 나감)

#### 돌 놓기 요청

- 요청 형태: [Put]{방 번호},{X 좌표},{Y 좌표}
- 예시: [Put]123,7,8
- 오목판의 특정한 위치에 돌을 놓았다는 정보를 방에 있는 사용자들에게 브로드캐스트(Broadcast)(모든 사용자에게 통신)합니다. 사용자에게 보내는 명령어의 형태는 요청과 동일합니다.

#### 시작 요청

- 요청 형태: [Play]{방 번호}
- 예시: [Play]123
- 특정한 방에 위치한 사용자의 시작 요청을 받아 [Play] 명령어를 전송합니다. 이 때 검은 돌 사용자에게는 [Play]Black을, 흰 돌 사용자에게는 [Play]White를 전송합니다. (게임 시작)


----

강의에서의 설명과는 다르게, 백돌이 먼저 돌을 두므로 [Put] 7,7 명령은 클라이언트에서 서버로 전송된다.


----

개선점 고려하기

- 소스코드의 요청 및 응답의 형태가 너무 직관적이므로 분석하기 쉽습니다.
- 각 게임에 대한 승리 판정을 클라이언트가 대신하고 있습니다.
	클라이언트는 데이터만 전송하고 서버에서 계산과 판정을 하게해야한다.
- 사용자의 수가 많아지는 경우 Vector STL이 비효율적으로 동작할 수 있습니다.
	이 경우, 트리/해시맵등을 이용해서 동작하는 것이 조금 더 효율적일 수 있다.
	
----

게임 서버 운영상의 특징

- 보안성을 향상시키기 위해서는 서버의 부담이 가중됩니다.
- 반대로 서버의 부담을 줄이면 클라이언트의 부담이 커지며, 보안성이 악화될 수 있습니다.
- 일반적으로 패키지 기반의 게임에서 게임 핵이 자주 등장하는 이유에 해당합니다.
	패키지 기반 게임은 서버 역할을 줄이기 때문. 클라이언트끼리 네트워크 게임이 운영되면 데이터 변조가 쉽다.


----

# 패킷 변조와 게임서버 공격

### 와이어샤크

설치할 때 winPcap을 꼭 설치하자
Npcap Loopback Adapter

패킷 내용 확인은 우클릭, follow, TCP stream
Https를 적용하지 않아서 암호화 안됨

ip.src(근원지), ip.dst(목적지) 등을 이용해서 특정 ip의 패킷만 볼 수 있다.


### Packet Sender

진짜 가슴이 웅장해진다...
`[Put]100,3,4`
이런 패킷을 아스키 코드로 보내본다.


### 다양한 공격 벡터

서버에서 클라이언트의 인증을 수행하여야 공격 벡터를 줄일 수 있다.
Https를 이용한다.
