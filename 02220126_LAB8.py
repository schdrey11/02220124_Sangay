class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 0

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        self.root = self._insert(self.root, value)

    def delete(self, value):
        self.root = self._delete(self.root, value)

    def is_balanced(self):
        return self._check_balance(self.root)

    def get_height(self):
        return self._height(self.root)

    def _insert(self, node, value):
        if not node:
            return Node(value)
        if value < node.value:
            node.left = self._insert(node.left, value)
        else:
            node.right = self._insert(node.right, value)

        node.height = 1 + max(self._height(node.left), self._height(node.right))
        return self._rebalance(node)

    def _delete(self, node, value):
        if not node:
            return node
        if value < node.value:
            node.left = self._delete(node.left, value)
        elif value > node.value:
            node.right = self._delete(node.right, value)
        else:
            if not node.left:
                return node.right
            elif not node.right:
                return node.left
            temp = self._min_value_node(node.right)
            node.value = temp.value
            node.right = self._delete(node.right, temp.value)

        node.height = 1 + max(self._height(node.left), self._height(node.right))
        return self._rebalance(node)

    def _rebalance(self, node):
        balance = self._get_balance(node)
        if balance > 1:
            if self._get_balance(node.left) >= 0:
                return self._right_rotate(node)
            else:
                node.left = self._left_rotate(node.left)
                return self._right_rotate(node)
        if balance < -1:
            if self._get_balance(node.right) <= 0:
                return self._left_rotate(node)
            else:
                node.right = self._right_rotate(node.right)
                return self._left_rotate(node)
        return node

    def _left_rotate(self, z):
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self._height(z.left), self._height(z.right))
        y.height = 1 + max(self._height(y.left), self._height(y.right))
        return y

    def _right_rotate(self, y):
        x = y.left
        T2 = x.right
        x.right = y
        y.left = T2
        y.height = 1 + max(self._height(y.left), self._height(y.right))
        x.height = 1 + max(self._height(x.left), self._height(x.right))
        return x

    def _height(self, node):
        return node.height if node else 0

    def _get_balance(self, node):
        return self._height(node.left) - self._height(node.right) if node else 0

    def _min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current

    def _check_balance(self, node):
        if not node:
            return True
        balance = self._get_balance(node)
        return abs(balance) <= 1 and self._check_balance(node.left) and self._check_balance(node.right)

    def print_tree(self, node, level=0, prefix="Root: "):
        if node is None:
            return
        print(" " * (level * 4) + prefix + str(node.value))
        if node.left or node.right:
            self.print_tree(node.left, level + 1, "L--- ")
            self.print_tree(node.right, level + 1, "R--- ")

# ---------------- Example Usage ----------------

if __name__ == "__main__":
    avl_tree = AVLTree()
    avl_tree.insert(10)
    avl_tree.insert(20)
    avl_tree.insert(30)
    avl_tree.insert(40)
    avl_tree.insert(50)

    print("\nAVL Tree after insertions:")
    avl_tree.print_tree(avl_tree.root)

    print("\nTree is Balanced:", avl_tree.is_balanced())  # Should return True
    print("Tree Height:", avl_tree.get_height())      # Should return 2

    avl_tree.delete(20)

    print("\nAVL Tree after deleting 20:")
    avl_tree.print_tree(avl_tree.root)

    print("\nTree is Balanced:", avl_tree.is_balanced())
    print("Tree Height:", avl_tree.get_height())
