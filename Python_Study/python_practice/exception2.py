#문자열에 숫자 더하기

try:
	print("string"+100)
except TypeError:
	print("둘의 형이 맞지 않습니다.")

	
	
#참조범위 에러

try:
	string1 = "String"
	print(string1[100])
except IndexError:
	print("참조범위를 넘었습니다.")
	
#사전에 없는 키를 호출

try:
	dic = {"1":1, "2":2}
	print(dic[3])
except KeyError:
	print("일치하는 키가 없습니다.")