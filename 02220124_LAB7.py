class Node:
    def __init__(self, value):
        self.value = value      
        self.left = None        
        self.right = None      

class BinaryTree:
    def __init__(self):
        self.root = None        
        print("Created new Binary Tree")
        print("Root: None")
        
    def height(self, node):
        if node is None:
            return 0
        else:
            left_height = self.height(node.left)
            right_height = self.height(node.right)
            return 1 + max(left_height, right_height)

    def size(self, node):
        if node is None:
            return 0
        else:
            return 1 + self.size(node.left) + self.size(node.right)

    def count_leaves(self, node):
        if node is None:
            return 0
        if node.left is None and node.right is None:
            return 1
        else:
            return self.count_leaves(node.left) + self.count_leaves(node.right)

    def is_full_binary_tree(self, node):
        if node is None:
            return True

        if node.left is None and node.right is None:
            return True

        if node.left is not None and node.right is not None:
            return self.is_full_binary_tree(node.left) and self.is_full_binary_tree(node.right)

        return False

    def is_complete_binary_tree(self):
        if self.root is None:
            return True

        queue = []
        queue.append(self.root)
        found_null = False

        while queue:
            current = queue.pop(0)

            if current.left:
                if found_null:
                    return False
                queue.append(current.left)
            else:
                found_null = True

            if current.right:
                if found_null:
                    return False
                queue.append(current.right)
            else:
                found_null = True

        return True

if __name__ == "__main__":
    tree = BinaryTree()

    tree.root = Node(1)
    tree.root.left = Node(2)
    tree.root.right = Node(3)
    tree.root.left.left = Node(4)
    tree.root.left.right = Node(5)
    tree.root.right.left = Node(6)
    tree.root.right.right = Node(7)
    tree.root.left.left.left = Node(8)
    tree.root.left.left.right = Node(9)

    print("Tree Height:", tree.height(tree.root))
    print("Total Nodes:", tree.size(tree.root))
    print("Leaf Nodes Count:", tree.count_leaves(tree.root))
    print("Is Full Binary Tree:", tree.is_full_binary_tree(tree.root))
    print("Is Complete Binary Tree:", tree.is_complete_binary_tree())
