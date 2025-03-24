class CustomList:
    def __init__(self, capacity=20):
       
        self._capacity = capacity  
        self._size = 0 
        self._elements = [None] * capacity  

        print(f"Created new CustomList with capacity: {self._capacity}")
        print(f"Current size: {self._size}")

    def append(self, element):
        if self._size >= self._capacity:
            self._resize()

        self._elements[self._size] = element
        self._size += 1
        print(f"Appended {element} to the list")

    def get(self, index):
        if 0 <= index < self._size:
            element = self._elements[index]
            print(f"Element at index {index}: {element}")
            return element
        else:
            raise IndexError("Index out of bounds")

    def set(self, index, element):
        if 0 <= index < self._size:
            self._elements[index] = element
            print(f"Set element at index {index} to {element}")
        else:
            raise IndexError("Index out of bounds")

    def size(self):
        print(f"Current size: {self._size}")
        return self._size
        
Task = CustomList()
Task.append(7)
Task.get(0)
Task.set(0, 10)
Task.get(0)
Task.size()