// user_ops.c
#include "queue.h"
#include <stdlib.h>

User generateRandomUser() {
    User user;
    const char* factions = "RBG";  // Possible factions

    // Create a random username of 10 characters
    for (int i = 0; i < 10; i++) {
        user.username[i] = 'a' + (rand() % 26);
    }
    user.username[10] = '\0';  // Ensure the username is null-terminated

    // Randomly assign a level between 1 and 60
    user.level = (rand() % 60) + 1;

    // Randomly assign one of the three factions
    user.faction = factions[rand() % 3];

    return user;
}

int enqueueMultipleUsers(Queue* q, int numberOfUsers) {
    for (int i = 0; i < numberOfUsers; i++) {
        User newUser = generateRandomUser();
        if (enqueue(q, newUser) != 0) {
            return -1; 
        }
    }
    return 0; 
}
