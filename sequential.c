// Provided Sequential Code
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

// Function to calculate sequential sum
int sequentialSum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    // Array size
    int n = atoi(argv[1]); // Adjust the size of the array as needed
    int array[n];

    // Initialize array with some values
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    // Measure sequential time
    double sequentialStart = omp_get_wtime();
    int sequentialResult = sequentialSum(array, n);
    double sequentialEnd = omp_get_wtime();
    double sequentialTime = sequentialEnd - sequentialStart;

    printf("Sequential Sum: %d\n", sequentialResult);
    printf("Sequential Time: %.9f seconds\n", sequentialTime);

    return 0;
}

