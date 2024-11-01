#include <stdio.h>
#include <stdlib.h>

const maxStack = 100;

typedef struct {
    int data[maxStack];
    int top;
} Stack;

void initStack(Stack *stack) {
    (*stack).top = -1;
}

int isEmpty(Stack *stack) {
    return (*stack).top == -1;
}

void push(Stack *stack, int x) {
    if ((*stack).top < maxStack - 1) {
        (*stack).data[++(*stack).top] = x;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return (*stack).data[(*stack).top--];
    } else {
        printf("Stack doesnt have anything\n");
        return -1;
    }
}

int peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return (*stack).data[(*stack).top];
    } else {
        return -1;
    }
}

// Define Queue structure using two stacks
typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

void initQueue(Queue *q) {
    initStack(&(*q).stack1);
    initStack(&(*q).stack2);
}

void enqueue(Queue *q, int x) {
    push(&(*q).stack1, x);
    printf("Enqueued/Pushed: %d\n", x);
}

int dequeue(Queue *q) {
    // Checks if queue is empty
    if (isEmpty(&(*q).stack1) && isEmpty(&(*q).stack2)) {
        printf("Queue is empty/ Queue underflow\n");
        return -1;
    }

    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isEmpty(&(*q).stack2)) {
        while (!isEmpty(&(*q).stack1)) {
            int x = pop(&(*q).stack1);
            push(&(*q).stack2, x);
        }
    }

    return pop(&(*q).stack2);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 100);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 420);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}