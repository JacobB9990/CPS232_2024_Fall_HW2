import random

LEN_ARRY = 1000
MAX_VAL = 5000


def getRandSortedArr():
    arr = []
    arr = random.sample(range(1, MAX_VAL), LEN_ARRY)
    arr.sort()  # We are not worried about sorting.
    return (arr)


def standardBinary(arr, l, r, target):
    while l <= r:
        # Since n is very large we use this from to prevent overflow
        m = l + (r-l)//2
        if arr[m] == target:
            return m
        elif arr[m] < target:
            l = m+1
        else:
            r = m-1
    return -1


def expoSearch(arr, target):
    if arr[0] == target:
        return 0

    index = 1
    while index < LEN_ARRY and arr[index] <= target:
        index *= 2

    return standardBinary(arr, index // 2, min(index, len(arr) - 1), target)


arr = getRandSortedArr()
randInt = random.randint(1, 100)  # Since i << n
target = arr[randInt]
print(f"Target is: {target} and its at index {randInt}")

result = expoSearch(arr, target)
print(f"Element found at index {result} of value {arr[result]}")
