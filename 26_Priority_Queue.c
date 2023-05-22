#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure to represent the priority queue
typedef struct {
    int heap[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max heap property
void maxHeapify(int* heap, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, largest, size);
    }
}

// Function to insert an element into the priority queue
void insert(PriorityQueue* pq, int item) {
    if (pq->size == MAX_SIZE) {
        printf("Priority queue overflow\n");
        return;
    }

    // Insert the new element at the end of the heap
    int i = pq->size;
    pq->heap[i] = item;

    // Maintain the max heap property by swapping the element with its parent
    while (i > 0 && pq->heap[(i - 1) / 2] < pq->heap[i]) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    pq->size++;
}

// Function to remove the maximum element from the priority queue
int deleteMax(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue underflow\n");
        return -1;
    }

    int max = pq->heap[0];
    pq->size--;

    // Move the last element to the root position and maintain the max heap property
    pq->heap[0] = pq->heap[pq->size];
    maxHeapify(pq->heap, 0, pq->size);

    return max;
}

// Function to display the elements in the priority queue
void display(PriorityQueue pq) {
    if (pq.size == 0) {
        printf("Priority queue is empty\n");
        return;
    }

    printf("Priority queue elements: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.heap[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq = { .size = 0 };

    insert(&pq, 5);
    insert(&pq, 3);
    insert(&pq, 10);
    insert(&pq, 1);

    display(pq);

    printf("Maximum element in the priority queue: %d\n", deleteMax(&pq));

    display(pq);

    return 0;
}


// Input
// insert 5
// insert 3
// insert 10
// insert 1
// deleteMax

// Output
// Priority queue elements: 10 5 3 1 
// Maximum element in the priority queue: 10
// Priority queue elements: 5 1 3 
