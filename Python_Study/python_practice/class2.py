class GeneralMethod:
	def set(self,v):
		self.value = v
	def get(self):
		return self.value
	
	
classinstance = GeneralMethod()
print(GeneralMethod.set)

GeneralMethod.set(classinstance, "Unbound Method Call")
print(GeneralMethod.get(classinstance))
