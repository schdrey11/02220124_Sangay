#Part 1: Sequential Search Implementation 
def sequential_search(arr, target):
    comparison = 0
    for i in range(len(arr)):
        comparison += 1
        if arr[i] == target:
            return i, comparison
    return -1, comparison

if __name__=="__main__":
    arr = [21, 3, 40, 10, 18, 56]
    target = 10
    
    print(f"List:{arr}")
    print(f"Searching for {target} using Sequential Search")
    i, comparison = sequential_search(arr,target)
    if i != -1:
        print(f"Element found at index {i}")
    else:
        print("Element not found")
        
    print(f"Number of comparisons:{comparison}")
