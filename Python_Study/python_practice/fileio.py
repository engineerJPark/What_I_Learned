'''
파일 입출력

텍스트 파일 쓰기 읽기
파일 읽기 메서드
파일 처리모드 - 일반, 이진 파일
파일 객체 메서드
파일 객체의 속성

open() 파일 연다
read, write
close()로 객체 사용 종료
*finally에는 반드시 close()를 써야한다.
'''

#예제1
text = '''testing
writing text
in the files
'''

files = open('t.txt','w')
print(files)

files.write(text)
files.close()