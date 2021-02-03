'''
상속과 다형성
'''

'''
상속 : 타 클래스의 기능을 사용가능하게 한다.
기존 기능 변경 가능하며, 추가로 필요한 기능만 정의할 수 있다.

기반, 부모, 상위 클래스
파생, 자식, 하위 클래스
로 위 아래로 구분해서 표현한다.

다중 상속 : 두개 이상의 클래스로부터 상속을 받는 것을 얘기함.
'''

'''
큐에 데이터를 추가하고 꺼내는 enqueue()와 dequeue() 메서드를 추가한다.
'''

class Queue(list):
	enqueue = list.append
	def dequeue(self):
		return self.pop(0)
	
queue = Queue()
queue.enqueue(10)	#데이터 추가
queue.enqueue(20)	#데이터 추가

print(queue)
print(queue.dequeue())
print(queue.dequeue())
print(queue)