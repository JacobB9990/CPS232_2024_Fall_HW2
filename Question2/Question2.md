2. **(25 pts)** In class, we learned that stacks can be implemented using queues. Fanchao wants to know if queues can be implemented using stacks. **Please implement a queue using a stack and analyze the running time of `Push` and `Pop` operations in your stack-based queue.**

---

# **Answer**

**Yes**, a queue can be implemented using two stacks. When implementing a queue using stacks, we can **utilize two stacks** to manage the _First In First Out_ behavior of a queue, even though a stack works in a _Last-In-First-Out_ manner.

To implement a queue using two stacks, we handle enqueue and dequeue operations with a few simple steps. For enqueue aka push, we just push the element onto **Stack 1**. Dequeue aka pop is a bit more involved, if **Stack 2** is empty, we pop all elements from **Stack 1** and push them onto **Stack 2**. This reversal step is key because it lets us access the elements in the same order they were added, making sure the queue behaves in a _First In First Out_ way. Then, we pop from **Stack 2**, giving us the element at the "front" of the queue. This approach ensures that our queue follows FIFO order, even though we're working with stacks that usually operate in a _Last In First Out_ manner.

Also you can change the max stack size to increase the queues size, in the code its set to 100.

**Enqueue/Push**: O(1) – We only push the element to Stack 1, so it’s a constant time operation.
**Dequeue/Pop**: O(n) – If Stack 2 is empty, we transfer all elements from Stack 1 to Stack 2, which takes O(n) time. However, once the elements are in Stack 2, dequeuing becomes O(1) until Stack 2 is empty again. So its O(n) every time its empty but for most operations it will be constant.

---
