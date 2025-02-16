#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize an empty queue by setting head and tail to NULL.
void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

// Check if the queue is empty by verifying if the head is NULL.
int isEmpty(Queue* q) {
    return q->head == NULL;
}

// Add a user to the end of the queue.
void enqueue(Queue* q, User user) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = user;  // Set the user data
    newNode->next = NULL;  // Next node is NULL initially

    if (q->tail != NULL) {  // If queue is not empty, append the new node
        q->tail->next = newNode;
    }
    q->tail = newNode;  // The new node is now the last node

    if (q->head == NULL) {  // If the queue was empty, new node is also the head
        q->head = newNode;
    }
}
