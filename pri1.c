/*To solve this problem in C, we can implement a sorting algorithm like Merge Sort, which inherently breaks the list into sub-lists. Then, we can measure the time taken to sort the list for various values of \( n \) to analyze the behavior in the Worst, Best, and Average cases.

### Steps:
1. *Implement Merge Sort*.
2. *Generate data for different values of \( n \)* (both best and worst cases).
3. *Measure the sorting time* for each \( n \).
4. *Plot the graph* of time taken vs \( n \).

### Implementation

#### 1. Implementing Merge Sort

Here's the Merge Sort implementation:

c*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to generate a random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Function to generate a sorted array (Best case)
void generateSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

// Function to generate a reverse sorted array (Worst case)
void generateReverseSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// Function to measure the time taken to sort an array
double measureSortTime(int arr[], int n) {
    clock_t start, end;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(0));

    int sizes[] = {100, 500, 1000, 5000, 10000, 50000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Size\tBest Case\tAverage Case\tWorst Case\n");
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr = (int *) malloc(n * sizeof(int));

        generateSortedArray(arr, n);
        double bestTime = measureSortTime(arr, n);

        generateRandomArray(arr, n);
        double avgTime = measureSortTime(arr, n);

        generateReverseSortedArray(arr, n);
        double worstTime = measureSortTime(arr, n);

        printf("%d\t%.6f\t%.6f\t%.6f\n", n, bestTime, avgTime, worstTime);

        free(arr);
    }

    return 0;
}
/*

### Explanation:
- *merge*: Merges two subarrays into a single sorted array.
- *mergeSort*: Recursively divides the array and sorts it using merge.
- *generateRandomArray*: Generates an array of random integers.
- *generateSortedArray*: Generates a sorted array (best case scenario).
- *generateReverseSortedArray*: Generates a reverse sorted array (worst case scenario).
- *measureSortTime*: Measures the time taken to sort an array using mergeSort.
- *main*: Executes the sorting for various values of \( n \) and prints the time taken for best, average, and worst cases.

### Running the Program:
Compile and run the program, then observe the printed times. You can then plot these times against \( n \) on a graph sheet to visualize the performance of the sorting algorithm.

### Plotting the Graph:
Use any graph plotting tool or software like Excel, GNUplot, or matplotlib in Python to plot the recorded times against the values of \( n \).

This approach will give you a comprehensive understanding of how Merge Sort performs in different scenarios for varying sizes of input data.*/