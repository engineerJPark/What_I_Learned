## Server Certificate
서버가 공개키를 포함한 인증서를 클라이언트에게 보낸다.
그 이후
Certification Request, Server Hello Done을 return한다.

# Client Certificate
Client Certificate에서 인증서 없으면 인증서 없다고 보낸다.
사용할 암호 스펙을 교환한다. Client Key Exchange, Certificate Verity

-----

윈도우 개발환경에서 OpenSSL은 이미 빌드가 완료된 OpenSSL을 설치해 VS에 바로 적용하면 된다.
http://slproweb.com/products/Win32OpenSSL.html
32bit OpenSSL MSI 파일로 설치한다.
설치경로 반드시 복사해서 이용한다.
속성 - 포함디렉터리 - openSSL include 폴더 - 라이브러리디렉터리 - openSSL lib/VC 폴더 - 추가 종속성
ws2_32.lib
libssl32MDd.lib
libcrypto32MDd.lib

-----

ssl.conf는 잘라서 OpenSSl bin 폴더로 이동 bin은 실행파일이 담겨있는 폴더.
명령어로
openssl.exe req -new -x509 -nodes -config ssl.conf -out cert.pem -keyout key.pem -days 365
인증서는 cert.pem
서버에서 관리할 개인키는 key.pem
이 두 파일을 openssl의 debug 폴더에 붙여넣기

-----


