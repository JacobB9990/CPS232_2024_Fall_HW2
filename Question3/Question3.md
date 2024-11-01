3. **(25 pts)** Given an array of positive and negative integers, separate the positives from the negatives without changing the relative order of elements. Please design an algorithm to solve this problem, justify the correctness of your algorithm, and analyze the running time.

         def rearrangeOrder(array, arraySize):
            
            pointerA = 0
            pointerB = 0
            
            while(pointerB < arraySize):
                
                if(array[pointerB] < 0): 
                    pointerB += 1
                    
                else: 
                    for i in range(pointerB,pointerA,-1):
                        
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

1) Create a function that takes input of an array and an integer representing the size of that array (arraySize)
2) Within the function let pointerA (holds position between positive and negative numbers) and pointerB (moves through array) equal 0
3) Create a while loop with the parameters pointerB < arraySize
4) Within the loop, if the array at index of pointerB is less than 0, add 1 to the value of pointerB
5) If else, create a for loop with i in range from pointerB to pointerA with a set step of -1
6) Within the for loop set a holder variable equal to array at index i
7) Set array at index i equal to array at index i-1   
8) Then set array at index i-1 equal to holder variable; end of for loop
9) Add 1 to value of both pointerA and pointerB; end of else loop
10) return array
