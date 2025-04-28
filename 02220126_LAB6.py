#Part 2: Merge Sort Implementation
def merge_sort(arr):
    comparisons = 0
    array_accesses = 0

    def merge(left, right):
        nonlocal comparisons, array_accesses
        merged = []
        i = j = 0

        while i < len(left) and j < len(right):
            comparisons += 1
            array_accesses += 2
            if left[i] < right[j]:
                merged.append(left[i])
                array_accesses += 1
                i += 1
            else:
                merged.append(right[j])
                array_accesses += 1
                j += 1

        while i < len(left):
            merged.append(left[i])
            array_accesses += 1
            i += 1

        while j < len(right):
            merged.append(right[j])
            array_accesses += 1
            j += 1

        return merged

    def sort(arr):
        if len(arr) <= 1:
            return arr
        mid = len(arr) // 2
        left = sort(arr[:mid])
        right = sort(arr[mid:])
        return merge(left, right)

    sorted_arr = sort(arr)
    return sorted_arr, comparisons, array_accesses

original_list = [70, 15, 53, 20, 92, 41, 7]
sorted_list, comp, acc = merge_sort(original_list)

print("Original List:", original_list)
print("Sorted using Merge Sort:", sorted_list)
print("Number of comparisons:", comp)
print("Number of array accesses:", acc)