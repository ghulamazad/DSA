def simpleArraySum(ar):
    sum1 = 0
    for n in ar:
        sum1 += n
    return sum1


if __name__ == '__main__':
    ar_count = int(input().strip())
    ar = list(map(int, input().rstrip().split()))
    result = simpleArraySum(ar)
    print(result)
