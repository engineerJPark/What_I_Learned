'''
try:
	sentence
except Errortype:
	sentence
else:
	sentence
finally:
	무조건실행하는 문장
'''


try:
	print("string"+100)
except TypeError:
	print("둘의 형이 맞지 않습니다.")
finally:
	print("무조건 실행되는 문장입니다.")