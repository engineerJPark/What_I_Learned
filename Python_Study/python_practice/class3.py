class GeneralMethod:
	def set(self,v):
		self.value = v
	def get(self):
		return self.value
	
classinstance = GeneralMethod()
print(classinstance.set)

classinstance.set("Bound Method Call")
print(GeneralMethod.get(classinstance))
