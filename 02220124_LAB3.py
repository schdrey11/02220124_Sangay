class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedStack:
    def __init__(self):
        self.top = None
        self.size = 0
        print("Created new LinkedStack")
        print("Stack is empty:", self.is_empty())

    def push(self, element):
        new_node = Node(element)
        new_node.next = self.top
        self.top = new_node
        self.size += 1
        print(f"Pushed {element} to the stack")
        self.display()
    
    def pop(self):
        if self.is_empty():
            print("Stack underflow! Cannot pop from an empty stack.")
            return None
        popped_data = self.top.data
        self.top = self.top.next
        self.size -= 1
        print(f"Popped element: {popped_data}")
        self.display()
        return popped_data
    
    def peek(self):
        if self.is_empty():
            print("Stack is empty! No top element.")
            return None
        print(f"Top element: {self.top.data}")
        return self.top.data
    
    def is_empty(self):
        return self.top is None
    
    def size(self):
        return self.size
    
    def display(self):
        if self.is_empty():
            print("Stack is empty!")
            return
        current = self.top
        stack_elements = []
        while current:
            stack_elements.append(str(current.data))
            current = current.next
        print("Display stack:", " -> ".join(stack_elements) + " -> null")

stack = LinkedStack()
stack.push(10)
stack.push(20)
stack.push(30)
print("Stack size:", stack.size)
stack.peek()
stack.pop()
stack.pop()
stack.peek()
print("Stack size:", stack.size)
