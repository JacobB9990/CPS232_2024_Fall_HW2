### Question:
1. **(25 pts)** We have learned about queues. There are two pointers for a queue: one is `head`, and the other is `tail`. When a new element is enqueued, this element will be placed at the position pointed to by the `tail`, and then the `tail` moves forward to point to the next vacancy. Conversely, dequeuing will pop the element pointed to by the `head`, and then the `head` moves forward to point to the next element.

   **There is a critical issue in such queues:** when an element is dequeued, the space previously occupied by this element cannot be reused for new elements. In array-based queues, this issue occurs literally as stated. In linked-list-based queues, frequently freeing memory for dequeued elements and allocating memory for enqueued elements may lead to memory issues, though it may mitigate the stated issue. To solve this issue neatly, Fanchao is looking for a new queue-like data structure that can reuse the space of dequeued elements and does not frequently free or allocate memory. **Please implement a new data structure, justify why it works, and analyze the running time of each operation.**

### Answer:
- One of the ways you could avoid allocating memory is just move the tail to a dequeued space after. This is pretty easy to implement within a queue already. We can just move the tail back to index 0, also checking if the queue is full. If the queue is full, like normal we can just throw away that "job". We could implement a dynamic array to handle more and more jobs as the queue gets full, but that is nessary our goal. If `n` gets really large it takes a lot more time to allocate memory then copy and past. Also, you could use a Circular Linked List, but that is more complex than what we implemented. 

#### How to run the code
- You must have a C compiler
- Open `cmd` or `terminal` at that file path
- Compile the code.
- Run the program
#### Modification
- You can change the `#define MAX_SIZE 10` to a higher number for a larger array
- You can change `Sleep(250)` to make it "Faster"
- You can change `i < 20` in `for (int i = 0; i < 20; i++)` at line 68

#### Time Complexity
- The time complexity is pretty trivial. For both `enqueue` and `dequeue` the time complexity is just `O(1)`, because each operation involves only a fixed number of steps that do not depend on the number of elements in the queue. Specifically, `enqueue` adds an element to the `tail` of the queue and then updates the `tail` index. Similarly, `dequeue` retrieves an element from the `head` of the queue and advances the `head` index. Since neither operation involves any loops or dependent steps, they both run in constant time, making the time complexity `O(1)` for each. Fun fact, `printQueue` function takes `O(n)` time as we have to iterate through the array to print out each element. This is not relevant to the problem as it is just for visual effect.