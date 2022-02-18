



class Node():
	def __init__(self, value):
		self.value = value
		self.next = None


class LinkedList():
	def __init__(self, head):
		self.head = head

	def printList(self):
		current = self.head
		while(current.next != None):
			print(current.value)
			current = current.next





n = Node(3)
n.next = Node(5)
ll = LinkedList(n)
ll.printList()