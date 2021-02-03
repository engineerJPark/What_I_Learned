'''
다형성 : 객체의 유형에 상관없이 하나의 메소드 이름으로 동일 작업을 하는 것.
프로그램의 작성과 코드의 이해가 목적이다.

animal class를 만들고 사람, 고래, 원숭이가 상속받고 우는 메소드를 만든다.
'''

class Animal:
	def cry(self):
		print("/././.")
		
class Human(Animal):
	def cry(self):
		print("엉엉")
		
class Whale(Animal):
	def cry(self):
		print("고래")
		
class Monkey(Animal):
	def cry(self):
		print("원숭이")
		
for i in (Animal(),Human(), Whale(), Monkey()):
	i.cry()