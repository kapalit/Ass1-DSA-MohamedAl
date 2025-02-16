#pragma once
#ifndef QUEUE_H
#define QUEUE_H

// User structure definition
// This structure holds all necessary information for a user in the game.
typedef struct {
    char username[11];  // 10 characters + null terminator for usernames
    int level;          // User level ranging from 1 to 60
    char faction;       // User faction, can be 'R' for Red, 'B' for Blue, 'G' for Green
} User;

// Node structure for the queue
// Each node holds a User and a pointer to the next node in the queue.
typedef struct Node {
    User data;          // Data of the user
    struct Node* next;  // Pointer to the next node in the queue
} Node;

// Queue structure definition
// A Queue is defined by pointers to the first (head) and last (tail) nodes.
typedef struct {
    Node* head;         // Pointer to the first node in the queue
    Node* tail;         // Pointer to the last node in the queue
} Queue;

// Declarations of all functions used to manipulate the queue and users.
void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, User user);
User dequeue(Queue* q);
User generateRandomUser();

#endif // QUEUE_H