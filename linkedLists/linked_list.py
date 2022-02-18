class Node():
	def __init__(self, value):
		self.value = value
		self.next = None


class LinkedList():
	def __init__(self, head):
		self.head = head

	def addNode(self, node):
		current = self.head
		while(current.next != None):
			current = current.next
		current.next = node

	def printList(self):
		current = self.head
		while(current != None):
			print(current.value)
			current = current.next

if __name__ == '__main__':
	n = int(input("Enter N: "))
	head = None
	for i in range(0,n):
		val = input()
		if(head == None):
			head = Node(val)
			ll= LinkedList(head)
		ll.addNode(Node(val))
	ll.printList()