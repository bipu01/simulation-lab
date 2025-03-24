#include <stdio.h>

int main() {
    // Transition matrix P
    double P[2][2] = {
        {0.4, 0.6}, // Rainy -> Rainy, Rainy -> Not Rainy
        {0.2, 0.8}  // Not Rainy -> Rainy, Not Rainy -> Not Rainy
    };

    // Compute the two-step transition matrix P^(2) = P * P
    double P2[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            P2[i][j] = 0.0;
            for (int k = 0; k < 2; k++) {
                P2[i][j] += P[i][k] * P[k][j];
            }
        }
    }

    // Probability of Not Rainy the day after tomorrow, given Not Rainy today
    double prob_not_rainy = P2[1][1]; // P^(2)(NR -> NR)

    // Print the result
    printf("Probability of not raining the day after tomorrow, given today is not rainy: %.2f (%.2f%%)\n",
           prob_not_rainy, prob_not_rainy * 100);

    return 0;
}
