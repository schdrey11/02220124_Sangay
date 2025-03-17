class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0
        print("Created new LinkedList")
        print(f"Current size: {self.count}")
        print("Head: None")

    def append(self, element):
        new_node = Node(element)
        if not self.head:  # If list is empty
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.count += 1
        print(f"Appended {element} to the list")

    def prepend(self, element):
        new_node = Node(element)
        if not self.head:  # If list is empty
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.count += 1
        print(f"Prepended {element} to the list")

    def get(self, index):
        if index < 0 or index >= self.count:
            print("Index out of bounds")
            return None
        current = self.head
        for _ in range(index):
            current = current.next
        print(f"Element at index {index}: {current.data}")
        return current.data

    def set(self, index, element):
        if index < 0 or index >= self.count:
            print("Index out of bounds")
            return
        current = self.head
        for _ in range(index):
            current = current.next
        current.data = element
        print(f"Set element at index {index} to {element}")

    def size(self):
        print(f"Current size: {self.count}")
        return self.count

    def print_list(self):
        current = self.head
        elements = []
        while current:
            elements.append(str(current.data))
            current = current.next
        print("Print Linked list: [" + " ".join(elements) + "]")

linked_list = LinkedList()

linked_list.append(1)
linked_list.append(2)
linked_list.append(3)

linked_list.get(0)
linked_list.get(2)

linked_list.set(0, 4)

linked_list.get(0)

linked_list.size()

linked_list.prepend(2)

linked_list.print_list()