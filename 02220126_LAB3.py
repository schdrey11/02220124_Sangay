#Part 1: Stack Implementation using Array

class ArrayStack:
    def __init__(self, capacity=10):
        self._stack = [None] * capacity 
        self._top = -1  # Variable to track the top of the stack
        self._capacity = capacity
        print(f"Created new ArrayStack with capacity: {capacity}")
        print("Stack is empty:", self.is_empty())

    def push(self, element):
        if self._top >= self._capacity - 1:
            print("Stack overflow! Cannot push", element)
        self._top += 1
        self._stack[self._top] = element
        print(f"Pushed {element} to the stack")
        self.display()

    def pop(self):
        if self.is_empty():
            print("Stack underflow! Cannot pop")
        element = self._stack[self._top]
        self._stack[self._top] = None  # Clear the reference
        self._top -= 1
        print(f"Popped element: {element}")
        self.display()
        return element

    def peek(self):
        if self.is_empty():
            print("Stack is empty! No top element")
        print(f"Top element: {self._stack[self._top]}")
        return self._stack[self._top]

    def is_empty(self):
        return self._top == -1

    def size(self):
        print(f"Stack size: {self._top + 1}")
        return self._top + 1

    def display(self):
        if self.is_empty():
            print("Stack is empty!")
        else:
            print("Display stack:", self._stack[:self._top + 1])


stack = ArrayStack()  
stack.push(5)
stack.push(6)
stack.push(7)
stack.push(8)
stack.peek()
stack.pop()
stack.size()
stack.display()