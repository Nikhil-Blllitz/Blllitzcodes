#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to fill the array with random numbers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

// Function to compute and print the time taken to sort arrays of different sizes
void computeTime(int sizes[], int num_sizes) {
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            return;
        }

        fillArray(arr, n);
        
        clock_t start, end;
        double cpu_time_used;
        
        start = clock();
        selectionSort(arr, n);
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cpu_time_used*=1000;
        
        printf("Time taken to sort array of size %d: %f seconds\n", n, cpu_time_used);
        
        free(arr);
    }
}

int main() {
    int sizes[] = {5000, 10000, 15000, 20000, 25000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Seed the random number generator
    srand(time(0));

    computeTime(sizes, num_sizes);

    return 0;
}
