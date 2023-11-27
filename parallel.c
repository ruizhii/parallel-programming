// Provided Parallel Code
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

// Function to calculate parallel sum
int parallelSum(int array[], int size) {
    int sum = 0;
    #pragma omp parallel for reduction (+:sum)
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

    // Measure parallel time
    double parallelStart = omp_get_wtime();
    int parallelResult = parallelSum(array, n);
    double parallelEnd = omp_get_wtime();
    double parallelTime = parallelEnd - parallelStart;

    printf("Sequential Sum: %d\n", parallelResult);
    printf("Sequential Time: %.9f seconds\n", parallelTime);

    return 0;
}

