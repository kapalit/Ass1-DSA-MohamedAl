// queue_ops.c
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Queue* q) {
    return q->head == NULL;
}

int enqueue(Queue* q, User user) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        return -1;  
    }
    newNode->data = user;
    newNode->next = NULL;

    if (q->tail != NULL) {
        q->tail->next = newNode;
    }
    q->tail = newNode;

    if (q->head == NULL) {
        q->head = newNode;
    }
    return 0;  
}

User dequeue(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Attempt to dequeue from an empty queue\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = q->head;  // Temporarily store the head node
    User user = temp->data;  // Get user data from head
    q->head = q->head->next;  // Move head to next node

    if (q->head == NULL) {  // If the queue is now empty, update tail
        q->tail = NULL;
    }

    free(temp);  // Free the removed head node
    return user;
}
