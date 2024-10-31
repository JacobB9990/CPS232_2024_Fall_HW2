#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Adds Sleep() easier to view the actual queue.

#define MAX_SIZE 10 // Maximum size of our queue

// Structure of our FancyQueue
typedef struct { 
    int data[MAX_SIZE]; // Array
    int head;          // Front of the queue
    int tail;          // Next insertion
    int size;          // Number of elements
} FancyQueue;

void printQueue(FancyQueue *queue) {
    if (queue->size == 0) { 
        printf("Queue is empty.\n"); //Checks if the queue is empty
        return;
    }
    
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->head + i) % MAX_SIZE; // Gets index, wrapping around the array.
        printf("\"%d\" - ", queue->data[index]);  // Print each element
    }
    
    printf(" NULL \n "); // End of the queue
}

// Function to initialize the queue
void initQueue(FancyQueue *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

// Function to add an element to the queue
void enqueue(FancyQueue *queue, int value) {
    if (queue->size == MAX_SIZE) {
        printf("Queue is full \n"); // Checks if the queue is full
        return;
    }

    queue->data[queue->tail] = value; // Add the new value at the tail
    queue->tail = (queue->tail + 1) % MAX_SIZE; // Update tail index
    queue->size++; // Increase the size
}

// Function to remove and return an element from the queue
int dequeue(FancyQueue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty"); // Check if the queue is empty
        return -1;
    }

    int value = queue->data[queue->head]; // Value at the head
    queue->head = (queue->head + 1) % MAX_SIZE; // Update head index
    queue->size--; // Decrease the size
    return value; //
}

int main() {
    FancyQueue queue;
    initQueue(&queue);

    srand(time(NULL)); // Makes sure each run is unique

    for (int i = 0; i < 50; i++) {
        int rando = rand() % 3 + 1; // Random number between 1 and 3

        if (rando == 1 || rando == 2) {
            int valueToAdd = rand() % 100 + 1; // Generate a random value to enqueue
            printf("Enqueuing: %d\n", valueToAdd);
            enqueue(&queue, valueToAdd); // Enqueue the generated value
        } 
        else if (rando == 3) {
            printf("Dequeuing...\n");
            dequeue(&queue); // Dequeue an element from the queue
        }

        printQueue(&queue); // Print the current state of the queue
        Sleep(250); // Pause for 250 milliseconds
    }

    return 0;
}