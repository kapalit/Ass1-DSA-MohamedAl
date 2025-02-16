#include "queue.h"
#include <stdlib.h>

// Generate a random user with a random username, level, and faction.
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