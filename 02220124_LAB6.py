#Part 1: Implementation of Quick sort

def quick_sort(arr):
    # Initialize counters as lists so they are mutable inside nested functions
    comparisons = [0]
    swaps = [0]

    # Median-of-three pivot selection
    def median_of_three(low, high):
        mid = (low + high) // 2
        a, b, c = arr[low], arr[mid], arr[high]
        if a <= b <= c or c <= b <= a:
            return mid
        elif b <= a <= c or c <= a <= b:
            return low
        else:
            return high

    # Partition function using Lomuto partition scheme
    def partition(low, high):
        pivot_index = median_of_three(low, high)
        arr[pivot_index], arr[high] = arr[high], arr[pivot_index]
        swaps[0] += 1

        pivot = arr[high]
        i = low - 1

        for j in range(low, high):
            comparisons[0] += 1
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
                swaps[0] += 1

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        swaps[0] += 1
        return i + 1

    # Recursive quick sort function
    def quick_sort_recursive(low, high):
        if low < high:
            pi = partition(low, high)
            quick_sort_recursive(low, pi - 1)
            quick_sort_recursive(pi + 1, high)

    # Start quick sort
    quick_sort_recursive(0, len(arr) - 1)
    return arr, comparisons[0], swaps[0]


# ---------------------- Main Program ----------------------
if __name__ == "__main__":
    # Example list to sort
    my_list = [38,20,15,15,13, 10]
    print("Original List:", my_list)

    # Perform quick sort
    sorted_list, comp, swp = quick_sort(my_list.copy())

    # Display results
    print("Sorted using Quick Sort:", sorted_list)
    print("Number of comparisons:", comp)
    print("Number of swaps:", swp)

