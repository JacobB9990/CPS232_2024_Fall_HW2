def rearrangeOrder(array, arraySize):

    pointerA = 0
    pointerB = 0

    while pointerB < arraySize:

        if array[pointerB] < 0:
            pointerB += 1

        else:
            for i in range(pointerB, pointerA, -1):

                holder = array[i]
                array[i] = array[i - 1]
                array[i - 1] = holder

            pointerA += 1
            pointerB += 1

    return array


array = [-1, 2, 7, -5, 3, -9, -8, 6, -4]
arraySize = len(array)
final = rearrangeOrder(array, arraySize)

print(final)
