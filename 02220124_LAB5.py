# Part 2: Binary Search Implementation

# Iterative Binary Search
def binary_search_iterative(arr, target):
    left = 0
    right = len(arr) - 1
    comparisons = 0

    while left <= right:
        comparisons += 1
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid, comparisons
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1, comparisons

# Recursive Binary Search
def binary_search_recursive(arr, target, left, right, comparisons=0):
    if left > right:
        return -1, comparisons

    comparisons += 1
    mid = (left + right) // 2

    if arr[mid] == target:
        return mid, comparisons
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right, comparisons)
    else:
        return binary_search_recursive(arr, target, left, mid - 1, comparisons)

numbers = [12, 23, 34, 45, 56, 67, 89]
target = 56

print("Sorted List:", numbers)
print("Target Element is:", target)

# Iterative Search
print("\nSearching for", target, "using Binary Search (Iterative)")
index, count = binary_search_iterative(numbers, target)
if index != -1:
    print("Found at index", index)
else:
    print("Not found")
print("Number of comparisons:", count)

# Recursive Search
print("\nSearching for", target, "using Binary Search (Recursive)")
index_r, count_r = binary_search_recursive(numbers, target, 0, len(numbers) - 1)
if index_r != -1:
    print("Found at index", index_r)
else:
    print("Not found")
print("Number of comparisons:", count_r)

    
