#에제4 줄단위로 쓰고 읽기

lines = ['line#1\n', 'line#2\n', 'line#3\n']
files = open('t1.txt', 'w')
files.writelines(lines)

files = open('t1.txt')
print(files.read())

files.close()