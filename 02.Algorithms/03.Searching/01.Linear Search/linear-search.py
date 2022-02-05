def linearSearch(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


if __name__ == "__main__":
    arr = [12, 52, 69, 78, 23, 5, 6, 8, 4, 64]
    r = linearSearch(arr, 64)
    if (r == -1):
        print("Element is not present in array")
    else:
        print(f"Element is present at index: {r}.")
