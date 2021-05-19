# Ngrok 이용해보기

AWS EC2를 대신해서 사용할 수 있는 테스트용 서버

Ngrok으로 외부 접속용 개발 서버를 구동한다.
터널링 기술을 통해 사설 IP대신에 공인 IP를 부여받게 된다.

1. Node.js 설치
	LTS로 설치하는 것이 안정적이다.
	설치 후 npm 눌러서 상태확인.
	'npm install ngrok -g'으로 설치.
	
2. Ngrok 공식사이트 접속하고 로그인
	자신의 인증토큰 복사
	'ngrok authtoken [token]' 실행
	'ngrok tcp 13'하면 13번 포트가 열린다.
	Forwarding을 보면, 'tcp://0.tcp.ngrok.io:16273'으로 적혀있는데, 이 주소와 포트로 접속하면 localhost 13번 포트에 접속이 가능하다는 뜻이다.
	
3. Boost.Asio 예제 확인
	클라이언트 프로그램에서
	tcp::resolver::query query("0.tcp.ngrok.io", "16273");
	이걸로 바꿔주자.
	그리고 클라이언트 프로그램만 실행해주자.
	(13번 포트로 접속하면 자동으로 daytime이 작동하는 듯.)
	