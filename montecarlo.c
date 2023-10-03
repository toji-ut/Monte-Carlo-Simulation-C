#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

// Function to simulate one experiment and update counts
void simulateOneExperiment(int counts[]) {
    int boxes[100] = {0};  // Initialize 100 boxes with 0 chips
    int chips = 100;

    // Number of chips to distribute
    while (chips > 0) {
        int box = rand() % 100;  // Generate a random box number (0-99)
        boxes [box]++;  // Place a chip in the selected box
        chips--;  // Decrement the number of chips
    }
    // Count the number of boxes with 0, 1, 2, ... chips
    for (int i = 0; i < 100; i++) {
        counts[boxes[i]]++; // Update the counts array based on chip count
    }
}

int main() {
    srand (time (NULL)) ;
    // Seed the random number generator with current time
    int numSimulations = 100000;  // Number of Monte Carlo simulations
    int counts[101] = {0};  // Initialize counts for 0 to 100 chips in a box

    // Run the simulations
    for (int simulation = 0; simulation < numSimulations; simulation++) {
        simulateOneExperiment (counts) ;  // Run one experiment and update counts
    }
    printf ("Expected number of boxes with chips: \n");
    // Print the expected values for each chip count
    for (int i = 0; i <= 100; i++) {
        if (counts[i] > 0) {
            double expectedCount = (double) counts[i] / numSimulations;
            printf("%d chip(s): %.2f \n", i, expectedCount);
        }
    }

	return 0;
}
