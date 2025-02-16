//Mohamed Al-h - 
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_users>\n", argv[0]);
        return 1;
    }

    int numUsers = atoi(argv[1]);
    Queue queue;
    initQueue(&queue);

    srand(time(NULL)); 

    // Enqueues multiple users and check for errors
    if (enqueueMultipleUsers(&queue, numUsers) != 0) {
        fprintf(stderr, "Failed to enqueue users\n");
        return -1;  
    }

    // Dequeues all users and display their information
    printf("Dequeuing users:\n");
    while (!isEmpty(&queue)) {
        User user = dequeue(&queue);
        printf("Username: %s, Level: %d, Faction: %c\n", user.username, user.level, user.faction);
    }

    return 0;  
}
