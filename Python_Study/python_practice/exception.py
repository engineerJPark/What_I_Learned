'''
예외처리하기

예를들면
0으로 나누기
문자열에 숫자 더하기
참조범위 너머의 인덱스 참조
사전에 없는 키로 검색
등... 이런 경우에 대해 에러 없이 처리하는 방법을 서술한다.
'''

'''
try:
	sentence
except <예외종류>:
	sentence
else:
	sentence
	
	
여기서 예외 종류를 적지 않으면 모든 에러에 대해 except 부분에 들어간다.
'''

#0으로 나누기

try:
	print(100/0)
except ZeroDivisionError:
	print("0으로 나눈 경우다.")