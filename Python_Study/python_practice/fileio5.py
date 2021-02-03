'''
파일 읽기 메서드

1. 파일 객체의 반복자 이용
2. readline(), readlines() 파일을 한 번에 한 줄씩 읽는다. 파일 전체를 줄 단위로 끊어서 리스트에 저장한다.

파일 처리 모드 - 일반, 이진 파일 처리시

일반 파일
r : 읽기 전용
w : 쓰기 전용
w+ : 읽고 쓰기(기존 파일 삭제)
a : 파일 끝에 추가
r+ : 읽고 쓰기
a+ : 파일 끝에 추가(읽기도 가능)

이진파일. 일반 파일과 똑같다.
rb
wb
ab
rb+
wb+
ab+

*파일 객체의 메서드
files.close() : 파일 닫음. 입출력 불가
files.read([size]) : 원하는 바이트 수만큼 파일에서 읽어온다
files.readline() : 줄하나를 읽어들인다.
files.readlines() : 전체 줄을 읽어들인다.
files.write(str) : 문자열을 파일에 쓴다.
fiels.writelines(list): 문자열 리스트를 파일에 쓴다. 단 줄바꾸기가 자동 삽입되지 아니한다.
files.seek(offset[,whence]) : 인수 offset만큼 떨어진 위치에 파일 포인터를 위치시킨다.
files.tell() : 파일의 현재 위치를 반환한다.
files.flush : 버퍼가 다 채워지지 않아도 내부 버퍼의 내용을 파일에 보낸다.
files.fileno() : 파일 객체의 파일 기술자(정수)를 반환
fiels.isatty() : 파일 객체의 tty와 같은 장치면 1 반환
fiels truncate([size]) : 파일 크기를 지정한 크기로 자른다. 인수를 지정하지 않으면 현재 위치에서 자른다.

*파일 객체의 속성
files.colsed : 파일 객체가 닫혔으면 1
files.mode : 파일이 열기 모드인가?
files.name : 파일을 열때 사용한 파일 이름
'''

