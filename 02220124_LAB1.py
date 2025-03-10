class CustomList:
    def __init__(self, capacity=20):
        """Initialize the CustomList with a default capacity."""
        self._capacity = capacity  # Maximum capacity of the list
        self._size = 0  # Current number of elements in the list
        self._elements = [None] * capacity  # Array to store elements

        print(f"Created new CustomList with capacity: {self._capacity}")
        print(f"Current size: {self._size}")

    def append(self, element):
        """Add an element to the end of the list."""
        if self._size >= self._capacity:
            self._resize()

        self._elements[self._size] = element
        self._size += 1
        print(f"Appended {element} to the list")

    def get(self, index):
        """Retrieve an element at a specific index."""
        if 0 <= index < self._size:
            element = self._elements[index]
            print(f"Element at index {index}: {element}")
            return element
        else:
            raise IndexError("Index out of bounds")

    def set(self, index, element):
        """Replace an element at a specific index."""
        if 0 <= index < self._size:
            self._elements[index] = element
            print(f"Set element at index {index} to {element}")
        else:
            raise IndexError("Index out of bounds")

    def size(self):
        """Return the current number of elements in the list."""
        print(f"Current size: {self._size}")
        return self._size

    def _resize(self):
        """Resize the array when capacity is reached."""
        new_capacity = self._capacity * 2
        new_elements = [None] * new_capacity

        # Copy elements to the new array
        for i in range(self._size):
            new_elements[i] = self._elements[i]

        self._elements = new_elements
        self._capacity = new_capacity
        print(f"Resized array to new capacity: {self._capacity}")

# Example usage
Task = CustomList()
Task.append(7)
Task.get(0)
Task.set(0, 10)
Task.get(0)
Task.size()