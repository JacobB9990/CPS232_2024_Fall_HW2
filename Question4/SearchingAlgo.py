import random

LEN_ARRY = 100

arry = []


def fillArray(arr):
    for i in range(LEN_ARRY):
        random_num = random.randint(1, 500)
        arry.append(random_num)

    return arr


def linearSearch(arr, n, x):
    pass


full_arry = fillArray(arry)
arry.sort()  # We are not worried about sorting.

print(arry)
