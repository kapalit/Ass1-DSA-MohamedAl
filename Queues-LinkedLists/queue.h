// queue.h
#ifndef QUEUE_H
#define QUEUE_H

// User structure definition
typedef struct {
    char username[11];  // 10 characters + null terminator for usernames
    int level;          // User level ranging from 1 to 60
    char faction;       // 'R' for Red, 'B' for Blue, 'G' for Green
} User;

// Node structure for the queue
typedef struct Node {
    User data;          // Data of the user
    struct Node* next;  // Pointer to the next node in the queue
} Node;

// Queue structure definition
typedef struct {
    Node* head;         // Pointer to the first node in the queue
    Node* tail;         // Pointer to the last node in the queue
} Queue;

// Declarations of all functions used to manipulate the queue and users
void initQueue(Queue* q);
int isEmpty(Queue* q);
int enqueue(Queue* q, User user);
User dequeue(Queue* q);
User generateRandomUser();
int enqueueMultipleUsers(Queue* q, int numberOfUsers);

#endif // QUEUE_H
