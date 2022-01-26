def reverseArray(a):
    left = 0
    right = len(a) - 1
    while left < right:
        a[left], a[right] = a[right], a[left]
        right -= 1
        left += 1
    return a


if __name__ == '__main__':
    T = int(input())
    arr = list(map(int, input().rstrip().split()))
    res = reverseArray(arr)
    print(res)
