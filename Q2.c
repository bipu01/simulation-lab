#include <stdio.h>

int main() {
    // Transition matrix P
    double P[2][2] = {
        {0.9, 0.1}, // Coke -> Coke, Coke -> Pepsi
        {0.2, 0.8}  // Pepsi -> Coke, Pepsi -> Pepsi
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

    // Probability of purchasing Coke after two purchases, given currently Pepsi
    double prob_coke = P2[1][0]; // P^(2)(Pepsi -> Coke)

    // Print the result
    printf("Probability of purchasing Coke after two purchases, given currently Pepsi: %.2f (%.2f%%)\n",
           prob_coke, prob_coke * 100);

    return 0;
}
