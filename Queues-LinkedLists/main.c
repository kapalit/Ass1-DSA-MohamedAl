#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function: Entry point of the program.
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_users>\n", argv[0]);
        return 1;
    }

    int numUsers = atoi(argv[1]);  // Number of users from command line
    Queue queue;
    initQueue(&queue);  // Initialize the queue

    srand(time(NULL));  // Seed the random number generator

    // Enqueue random users into the queue
    for (int i = 0; i < numUsers; i++) {
        enqueue(&queue, generateRandomUser());
    }

    // Dequeue all users and display their information
    printf("Dequeuing users:\n");
    while (!isEmpty(&queue)) {
        User user = dequeue(&queue);
        printf("Username: %s, Level: %d, Faction: %c\n", user.username, user.level, user.faction);
    }

    return 0;
}
