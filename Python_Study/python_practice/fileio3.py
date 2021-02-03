#예제3. 파일 읽기
files = open('t.txt')
print(files)

texts = files.read()
print(texts)
files.close()

with open ('t.txt') as files:
	print(files.read())
