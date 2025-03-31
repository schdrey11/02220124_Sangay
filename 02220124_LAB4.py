class ArrayQueue:
    def __init__(self, capacity=10):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front = -1
        self.rear = -1
        print(f"Created new Queue with capacity: {capacity}")

    def is_empty(self):
        return self.front == -1
    
    def is_full(self):
        return (self.rear + 1) % self.capacity == self.front
    
    def enqueue(self, element):
        if self.is_full():
            print("Queue is full!")
            return
        if self.is_empty():
            self.front = 0
        self.rear = (self.rear + 1) % self.capacity
        self.queue[self.rear] = element
        print(f"Enqueued {element} to the queue")
    
    def dequeue(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        removed_element = self.queue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
        print(f"Dequeued element: {removed_element}")
        return removed_element
    
    def peek(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        print(f"Front element: {self.queue[self.front]}")
        return self.queue[self.front]
    
    def size(self):
        if self.is_empty():
            return 0
        return (self.rear - self.front + self.capacity) % self.capacity + 1
    
    def display(self):
        if self.is_empty():
            print("Queue is empty!")
            return []
        result = []
        i = self.front
        while True:
            result.append(self.queue[i])
            if i == self.rear:
                break
            i = (i + 1) % self.capacity
        print(f"Display queue: {result}")
        return result

queue = ArrayQueue()
print("Queue is empty:", queue.is_empty())
queue.enqueue(0)
queue.display()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
queue.display()
print("Queue size:", queue.size())
queue.enqueue(5)
queue.display()
queue.peek()
queue.dequeue()
queue.display()
queue.dequeue()
queue.display()
print("Queue size:", queue.size())
