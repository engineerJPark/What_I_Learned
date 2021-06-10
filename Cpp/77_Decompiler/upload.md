# 디컴파일러

프로그램(exe등)을 역으로 분석하는 도구
고급 프로그래밍 언어의 소스코드로 변형한다. 다만 완전한 복구는 어렵다.

C# 프로그램의 디컴파일러는 dotPeek
기본 설정으로 설치하자

# 난독화 도구

EazFuscator로 난독화 할 수 있다.
Release 모드로 배포했을 때 난독화 파일이 배포된다.
(Release모드는 Debug 모드보다 더욱 최적화가 이루어진다.)

# 다시 한번 디컴파일 해보기

아 안돼...!


### 결론

클라이언트와 서버의 보호를 위해 난독화는 필수다.

### 토큰 기반 인증

- JWT등의 토큰 기반 인증 시스템 적용(혹은 아이디 비밀번호 등) -> 클라이언트 사용자를 인증할 수 있다.
- 서버에서 사용자에게 토큰을 생성해준다.
- 이후 클라이언트는 해당 토큰을 이용해서 서버에 접근한다.

### SSL 인증서

- 패킷을 가로채도 토큰을 탈취할 수 없도록 SSL 인증서를 사용한다.